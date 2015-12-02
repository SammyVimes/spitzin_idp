#include "mainwindow.h"
#include <QApplication>
#include <QtCore/QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QFile file(":/qss/style.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    qApp->setStyleSheet(styleSheet);
    //w.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    w.show();


    return a.exec();
}
