#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include "../../include/QtLog/QtLog"
// �����װ��Qt��SDKĿ¼, ���԰��������д��
// #include <QtLog/QtLog>

class MainWindow : public QWidget
{
    Q_OBJECT
    // ���ﶨ����־��
    Q_LOGGER

public:
    MainWindow();
};

#endif//MAINWINDOW_H
