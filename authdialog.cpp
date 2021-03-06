#include "authdialog.h"
#include "ui_authdialog.h"

void AuthDialog::mousePressEvent(QMouseEvent* e)
{
    clickPos = e->pos();
}

void AuthDialog::mouseMoveEvent(QMouseEvent* e)
{
    move( e->globalPos() - clickPos );
}

AuthDialog::AuthDialog(QWidget *parent, Factory<AbstractDataProvider *>* dataProviderFactory) :
    QDialog(parent),
    ui(new Ui::AuthDialog)
{
    ui->setupUi(this);
    this->dataProviderFactory = dataProviderFactory;
}

AuthDialog::~AuthDialog()
{
    delete ui;
}

void AuthDialog::on_exitButton_clicked()
{
    close();
}

void AuthDialog::on_authButton_clicked()
{
        MainWindow* w = new MainWindow(0, dataProviderFactory);


        QFile file(":/qss/style.qss");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());

        qApp->setStyleSheet(styleSheet);
        w->setWindowFlags(Qt::Window | Qt::FramelessWindowHint | Qt::CustomizeWindowHint);
        w->show();
        close();
}
