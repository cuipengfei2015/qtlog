#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../../include/QtLog/QtLog"
// �����װ��Qt��SDKĿ¼, ���԰��������д��
// #include <QtLog/QtLog>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    // ���ﶨ����־��
    Q_LOGGER

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
