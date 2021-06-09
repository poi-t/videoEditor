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
    void on_btnLoadVideo_clicked();
    void on_btnPlay_clicked();
    void on_btnMute_clicked();
    void on_SetVolume(int vol);
    void on_SetVideoTime();
    void on_LeftPointSeek(int lPos);
    void on_RightPointSeek(int rPos);
    void on_btnStartCut_clicked();
    void on_Finished(int exidCode, QProcess::ExitStatus exitStaus);
    void on_spinBoxStart(int value);
    void on_spinBoxEnd(int value);

private:
    int changeVolume(int vol);
    QString getTimeStr(int secs);

    Ui::videoEditorClass ui;
    libvlc_instance_t* m_pInstance;
    libvlc_media_player_t* m_pPlayer;
    long long m_times;                //视频总时长
    QTimer* m_pTimer;
    bool m_LeftMove;                  //用于判断是进度条哪边拖动
    QString m_fileName;
    QProcess* m_pProcess;
    bool m_begin;
};
