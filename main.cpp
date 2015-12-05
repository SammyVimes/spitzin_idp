#include "authdialog.h"
#include <QApplication>
#include <QtCore/QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    AuthDialog d;


    QFile file(":/qss/dialog.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());

    qApp->setStyleSheet(styleSheet);
    d.setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
    d.show();

    return a.exec();
}
