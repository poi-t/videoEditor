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
    void on_btnLoadVideo_clicked();                                 //���밴ť����¼�
    void on_btnPlay_clicked();                                      //���Ű�ť����¼�
    void on_btnMute_clicked();                                      //������ť����¼�
    void on_SetVolume(int vol);                                     //�������϶��¼�
    void on_SetVideoTime();                                         //��ʱ���¼����Խ��Ƚ�����ʾ
    void on_LeftPointSeek(int lPos);                                //��������˱䶯�¼�
    void on_RightPointSeek(int rPos);                               //�������Ҷ˱䶯�¼�
    void on_btnStartCut_clicked();                                  //������ť����¼�
    void on_Finished(int exidCode, QProcess::ExitStatus exitStaus); //��������¼�
    void on_spinBoxStart(int value);                                //��ʼʱ��䶯�¼�
    void on_spinBoxEnd(int value);                                  //�����¼��䶯�¼�

private:
    int changeVolume(int vol);                                      //��������
    QString getTimeStr(int secs);                                   //��ȡʱ������ַ�����ʽ

    Ui::videoEditorClass ui;
    QTimer* m_pTimer;                                               //��ʱ��
    libvlc_instance_t* m_pInstance;                                 //ָ��libVLCʵ��
    libvlc_media_player_t* m_pPlayer;                               //ָ��һ��VLCý�岥����
    long long m_times;                                              //��Ƶ��ʱ��
    bool m_LeftMove;                                                //�����жϽ������϶�����
    QString m_fileName;                                             //��ѡ�ļ���
    QProcess* m_pProcess;                                           //���ڵ����ⲿ����ffmpeg��
    bool m_begin;                                                   //�ж���Ƶ�Ƿ����ڲ���
};
