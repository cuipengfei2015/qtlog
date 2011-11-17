#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtLog/QtLog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // RootLogger�ļ������ó�ΪFatal��Debug.
    QtLog::rootLogger()->setLevels(QLogLevels() | QtLog::Fatal | QtLog::Debug);

    // ����һ������̨���Appender.
    QConsoleAppender consoleAppender;

    // ���ÿ��Appender��ָ����¼�ļ���, Ĭ��ʹ��RootLogger�ļ���.
    // consoleAppender.setLevels(QLogger::All);

    // ��ConsoleAppender��ӵ���¼������.
    QtLog::rootLogger()->addAppender(&consoleAppender);

    // ������Ϣ��������, ��ΪRootLogger����ֻ��¼Fatal��Debug��.
    QtLog::rootLogger()->debug("This message will be ignored.");
    // �����ռǽ������������̨.
    QtLog::rootLogger()->fatal("This message will be recorded.");

    // ����¼�����޸�Ϊȫ����¼.
    QtLog::rootLogger()->setLevels(QtLog::All);
    // SQLITE���ݿ��ļ�.
    QSQLiteAppender dbfileAppender(QString("test.any"));
    // ��ӽ�ȥ.
    QtLog::rootLogger()->addAppender(&dbfileAppender);

    // �������ʱ������QTLOG_LOCALE_SUPPORT, д������Ҳ�ǿ��Ե�.
    QtLog::rootLogger()->error("�����Ϣ�����ĵ�, ���ᱻ����.");


    MainWindow w;
    w.show();

    return a.exec();
}
