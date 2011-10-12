#include <QtGui/QApplication>
#include "mainwindow.h"
#include <QtLog/QtLog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // RootLogger�ļ������ó�ΪFatal��Debug.
    QLogger::rootLogger()->setLevels(QLogger::Levels() | QLogger::Fatal | QLogger::Debug);

    // ����һ������̨���Appender.
    QConsoleAppender consoleAppender;

    // ���ÿ��Appender��ָ����¼�ļ���, Ĭ��ʹ��RootLogger�ļ���.
    // consoleAppender.setLevels(QLogger::All);

    // ��ConsoleAppender��ӵ���¼������.
    QLogger::rootLogger()->addAppender(&consoleAppender);

    // ������Ϣ��������, ��ΪRootLogger����ֻ��¼Fatal��Debug��.
    QLogger::rootLogger()->debug("This message will be ignored.");
    // �����ռǽ������������̨.
    QLogger::rootLogger()->fatal("This message will be recorded.");

    // ����¼�����޸�Ϊȫ����¼.
    QLogger::rootLogger()->setLevels(QLogger::All);
    // SQLITE���ݿ��ļ�.
    QDBFileAppender dbfileAppender(QString("test.any"));
    // ��ӽ�ȥ.
    QLogger::rootLogger()->addAppender(&dbfileAppender);

    // �������ʱ������QTLOG_LOCALE_SUPPORT, д������Ҳ�ǿ��Ե�.
    QLogger::rootLogger()->error("�����Ϣ�����ĵ�, ���ᱻ����.");


    MainWindow w;
    w.show();

    return a.exec();
}
