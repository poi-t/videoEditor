#pragma once

#include <QtWidgets/QWidget>
#include "ui_videoEditor.h"
#include "vlc/vlc.h"
#include <QTimer>
#include <QProcess>

class videoEditor : public QWidget
{
    Q_OBJECT

public:
    videoEditor(QWidget *parent = Q_NULLPTR);

private slots:
    void on_btnLoadVideo_clicked();                                 //导入按钮点击事件
    void on_btnPlay_clicked();                                      //播放按钮点击事件
    void on_btnMute_clicked();                                      //音量按钮点击事件
    void on_SetVolume(int vol);                                     //音量条拖动事件
    void on_SetVideoTime();                                         //定时器事件，对进度进行显示
    void on_LeftPointSeek(int lPos);                                //进度条左端变动事件
    void on_RightPointSeek(int rPos);                               //进度条右端变动事件
    void on_btnStartCut_clicked();                                  //剪辑按钮点击事件
    void on_Finished(int exidCode, QProcess::ExitStatus exitStaus); //剪辑完成事件
    void on_spinBoxStart(int value);                                //开始时间变动事件
    void on_spinBoxEnd(int value);                                  //结束事件变动事件

private:
    int changeVolume(int vol);                                      //音量调节
    QString getTimeStr(int secs);                                   //获取时间对于字符串形式

    Ui::videoEditorClass ui;
    QTimer* m_pTimer;                                               //定时器
    libvlc_instance_t* m_pInstance;                                 //指向libVLC实例
    libvlc_media_player_t* m_pPlayer;                               //指向一个VLC媒体播放器
    long long m_times;                                              //视频总时长
    bool m_LeftMove;                                                //用于判断进度条拖动方向
    QString m_fileName;                                             //所选文件名
    QProcess* m_pProcess;                                           //用于调用外部程序（ffmpeg）
    bool m_begin;                                                   //判断视频是否正在播放
};
