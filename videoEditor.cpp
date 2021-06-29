#include "videoEditor.h"
#include <QMessageBox>
#include <QFileDialog>
#include <QProcess>
#include <QInputDialog>
#include "QxtSpanSlider.h"

//避免中文乱码
#pragma execution_character_set("utf-8")


videoEditor::videoEditor(QWidget *parent)
    : QWidget(parent), m_times(0), m_LeftMove(true), m_begin(false)
{
    ui.setupUi(this);

    m_pPlayer = NULL;
    m_pProcess = NULL;

    m_pInstance = libvlc_new(0, NULL);
    if (m_pInstance == NULL) {
        QMessageBox::information(this, "提示", "初始化失败");
        return;
    }

    //用于视频播放时其他组件的同步的定时器
    m_pTimer = new QTimer(this);     
    m_pTimer->start(100);

    ui.btnPlay->setStyleSheet("background-image:url(:/videoEditor/pictures/pause.png)");
    ui.btnMute->setStyleSheet("background-image:url(:/videoEditor/pictures/volume.png)");
    ui.volumeSlider->setRange(0, 100);
    ui.volumeSlider->setValue(50);
    ui.label_time->clear();

    //防止双向滑动器重叠
    ui.timeSlider->setHandleMovementMode(QxtSpanSlider::NoOverlapping);

    //连接槽函数
    connect(ui.volumeSlider, &QSlider::valueChanged, this, &videoEditor::on_SetVolume);
    connect(m_pTimer, &QTimer::timeout, this, &videoEditor::on_SetVideoTime);
    connect(ui.timeSlider, &QxtSpanSlider::lowerPositionChanged, this, &videoEditor::on_LeftPointSeek);
    connect(ui.timeSlider, &QxtSpanSlider::upperPositionChanged, this, &videoEditor::on_RightPointSeek);
    connect(ui.spinBox_start, SIGNAL(valueChanged(int)), this, SLOT(on_spinBoxStart(int)));
    connect(ui.spinBox_end, SIGNAL(valueChanged(int)), this, SLOT(on_spinBoxEnd(int)));
}

void videoEditor::on_btnLoadVideo_clicked()
{
    m_fileName = QFileDialog::getOpenFileName(this, "请选择视频文件", qApp->applicationDirPath(), "视频文件(*.mp4 *.avi);");
    if (m_fileName.isEmpty())
    {
        return;
    }

    //window下编码问题
    m_fileName.replace(":/", ":\\");
    setWindowTitle(m_fileName);

    //创建一个可播放的媒体
    libvlc_media_t* pMedia = libvlc_media_new_path(m_pInstance, m_fileName.toStdString().c_str());
    if (pMedia == NULL)
    {
        QMessageBox::information(this, "提示", "media创建失败");
        return;
    }

    //获取视频时长
    libvlc_media_parse(pMedia);
    libvlc_time_t len = libvlc_media_get_duration(pMedia);
    if (len == -1)
    {
        QMessageBox::information(this, "提示", "获取视频时长失败，无效的视频");
        return;
    }
    m_times = len / 1000;

    //创建一个VLC媒体播放器
    m_pPlayer = libvlc_media_player_new_from_media(pMedia);
    if (m_pPlayer == NULL)
    {
        QMessageBox::information(this, "提示", "player创建失败");
        return;
    }

    libvlc_media_release(pMedia);
    libvlc_media_player_set_hwnd(m_pPlayer, (void*)ui.widget->winId());
    libvlc_media_player_play(m_pPlayer);

    //循环播放
    libvlc_media_list_t* pMList = libvlc_media_list_new(m_pInstance);
    libvlc_media_list_add_media(pMList, pMedia);
    libvlc_media_release(pMedia);
    libvlc_media_list_player_t* pPlayerList = libvlc_media_list_player_new(m_pInstance);
    libvlc_media_list_player_set_media_list(pPlayerList, pMList);
    libvlc_media_list_player_set_media_player(pPlayerList, m_pPlayer);
    libvlc_media_list_player_set_playback_mode(pPlayerList, libvlc_playback_mode_loop);

    ui.spinBox_start->setRange(0, m_times);
    ui.spinBox_end->setRange(0, m_times);
    ui.spinBox_start->setValue(0);
    ui.spinBox_end->setValue(m_times);

    ui.label_time->setText("00:00:00 / " + getTimeStr(m_times));

    ui.timeSlider->setRange(0, m_times);
    ui.timeSlider->setLowerValue(0);
    ui.timeSlider->setUpperValue(m_times);

    m_begin = true;
}

void videoEditor::on_btnPlay_clicked()
{
    if (m_pPlayer == NULL)
    {
        return;
    }

    if (libvlc_media_player_is_playing(m_pPlayer))
    {
        libvlc_media_player_pause(m_pPlayer);
        ui.btnPlay->setStyleSheet("background-image:url(:/videoEditor/pictures/play.png)");
    }
    else
    {
        libvlc_media_player_play(m_pPlayer);
        ui.btnPlay->setStyleSheet("background-image:url(:/videoEditor/pictures/pause.png)");
    }
}

void videoEditor::on_btnMute_clicked()
{
    if (m_pPlayer == NULL)
    {
        return;
    }

    int vol = ui.volumeSlider->value();
    if (vol == 0)
    {
        changeVolume(50);
        ui.volumeSlider->setValue(50);
        ui.btnMute->setStyleSheet("background-image:url(:/videoEditor/pictures/volume.png)");
    }
    else
    {
        changeVolume(0);
        ui.volumeSlider->setValue(0);
        ui.btnMute->setStyleSheet("background-image:url(:/videoEditor/pictures/mute.png)");
    }
}

int videoEditor::changeVolume(int vol)
{
    int ret = -1;
    if (m_pPlayer != NULL)
    {
        ret = libvlc_audio_set_volume(m_pPlayer, vol);
    }
    return ret;
}

void videoEditor::on_SetVolume(int vol)
{
    if (m_pPlayer != NULL)
    {
        changeVolume(vol);
        if (vol == 0)
        {
            ui.btnMute->setStyleSheet("background-image:url(:/videoEditor/pictures/mute.png)");
        }
        else
        {
            ui.btnMute->setStyleSheet("background-image:url(:/videoEditor/pictures/volume.png)");
        }
    }
}

QString videoEditor::getTimeStr(int secs)
{
    QString time_hour = "00:";
    QString time_min = "00:";
    QString time_sec = "00";
    if (secs >= 3600)
    {
        time_hour = secs / 3600 >= 10 ? QString::number(secs / 3600) + ":" : "0" + QString::number(secs / 3600) + ":";
        secs %= 3600;
    }
    if (secs >= 60)
    {
        time_min = secs / 60 >= 10 ? QString::number(secs / 60) + ":" : "0" + QString::number(secs / 60) + ":";
        secs %= 60;
    }
    time_sec = secs >= 10 ? QString::number(secs) : "0" + QString::number(secs);
    QString time = time_hour + time_min + time_sec;
    return time;
}

void videoEditor::on_SetVideoTime()
{
    if (m_pPlayer == NULL)
    {
        return;
    }

    float per = libvlc_media_player_get_position(m_pPlayer);
    int curTime = per * m_times;
    QString str1 = getTimeStr(curTime);
    QString str2 = getTimeStr(m_times);
    ui.label_time->setText(str1 + " / " + str2);
    if (m_LeftMove)
    {
        ui.timeSlider->setLowerValue(curTime);
        ui.spinBox_start->setValue(curTime);
    }
    else
    {
        ui.timeSlider->setUpperValue(curTime);
        ui.spinBox_end->setValue(curTime);
    }
}

void videoEditor::on_LeftPointSeek(int lPos)
{
    if (m_pPlayer == NULL)
    {
        return;
    }
    int low = ui.timeSlider->lowerValue();
    libvlc_media_player_set_position(m_pPlayer, low * 1.0 / m_times);
    m_LeftMove = true;
    ui.spinBox_start->setValue(low);

}

void videoEditor::on_RightPointSeek(int rPos)
{
    if (m_pPlayer == NULL)
    {
        return;
    }
    int right = ui.timeSlider->upperValue();
    libvlc_media_player_set_position(m_pPlayer, right * 1.0 / m_times);
    m_LeftMove = false;
    ui.spinBox_end->setValue(right);
}

void videoEditor::on_btnStartCut_clicked()
{
    if (m_pPlayer == NULL)
    {
        return;
    }

    //将视频停下
    libvlc_media_player_pause(m_pPlayer);
    ui.btnPlay->setStyleSheet("background-image:url(:/videoEditor/pictures/play.png)");
    m_pTimer->stop();

    //调用ffmpeg进行视频剪辑
    m_pProcess = new QProcess(this);

    QString dir = QFileDialog::getExistingDirectory(this, "输出文件夹", "/");
    QString text = QInputDialog::getText(this, "输出文件名", "输出文件名", QLineEdit::Normal, "output.mp4");
    QString ffmpeg_path = qApp->applicationDirPath() + "/ffmpeg";
    QString str_strat = getTimeStr(ui.spinBox_start->value());
    QString str_end = getTimeStr(ui.spinBox_end->value());
    QString cmd = ffmpeg_path + " -i " + m_fileName + " -ss " + str_strat + " -c copy -to " + str_end + " " + dir + "/" + text;

    m_pProcess->setProcessChannelMode(QProcess::MergedChannels);
    m_pProcess->start(cmd);
    bool isOK = m_pProcess->waitForStarted(50000);
    if (!isOK)
    {
        QMessageBox::information(this, "提示", "剪辑视频失败");
        return;
    }

    connect(m_pProcess, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(on_Finished(int, QProcess::ExitStatus)));
}

void videoEditor::on_Finished(int exidCode, QProcess::ExitStatus exitStaus)
{
    if (exitStaus == 0)
    {
        QMessageBox::information(this, "提示", "视频剪辑成功");
        return;
    }
    else
    {
        QMessageBox::information(this, "提示", "剪辑异常结束");
        return;
    }
}

void videoEditor::on_spinBoxStart(int value)
{
    if (m_begin)
    {
        libvlc_media_player_set_position(m_pPlayer, value * 1.0 / m_times);
        m_LeftMove = true;
        QString str1 = getTimeStr(value);
        QString str2 = getTimeStr(m_times);
        ui.label_time->setText(str1 + " / " + str2);
        ui.timeSlider->setLowerValue(value);
    }
}

void videoEditor::on_spinBoxEnd(int value)
{
    if (m_begin)
    {
        libvlc_media_player_set_position(m_pPlayer, value * 1.0 / m_times);
        m_LeftMove = false;
        QString str1 = getTimeStr(value);
        QString str2 = getTimeStr(m_times);
        ui.label_time->setText(str1 + " / " + str2);
        ui.timeSlider->setUpperValue(value);
    }
}