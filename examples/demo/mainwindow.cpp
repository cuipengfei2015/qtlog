#include "mainwindow.h"

MainWindow::MainWindow()
    : QWidget()
{

    // ÿ���������ָ���Լ��ļ�¼����, ��������þ�ʹ��RootLogger�ļ���.
    logger()->setLevels(QtLog::All);
    // ���һ���ı���¼��. �������������־���ᱻ������¼.
    logger()->addAppender(new QTextFileAppender(QString("demo.txt"), this));
    // ������Ϣ���ᱻ��¼����. �ж�˳����ObjectLogger->RootLogger->Appender.
    logger()->warn("This is a warnning message.");
}
