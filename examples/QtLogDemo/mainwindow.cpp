#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ÿ���������ָ���Լ��ļ�¼����, ��������þ�ʹ��RootLogger�ļ���.
    logger()->setLevels(QLogger::All);
    // ���һ���ı���¼��. �������������־���ᱻ������¼.
    logger()->addAppender(new QTextFileAppender(QString("test.txt"), this));
    // ������Ϣ���ᱻ��¼����. �ж�˳����ObjectLogger->RootLogger->Appender.
    logger()->warn("This is a warnning message.");
}

MainWindow::~MainWindow()
{
    delete ui;
}
