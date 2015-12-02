#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    clickPos = e->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    //move( e->globalPos() - clickPos );
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->refreshIcon->setPath(QString::fromUtf8(":/img/icon_refresh.png"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_child1Btn_clicked()
{
    this->ui->child1Btn->setActive(true);
    this->ui->child2Btn->setActive(false);

    loadStats("asd");
}

void MainWindow::on_child2Btn_clicked()
{
    this->ui->child2Btn->setActive(true);
    this->ui->child1Btn->setActive(false);
}

//вместо extern сделаем просто функцию тут
QList<StatEvent> getData(DataProvider& provider, QString msisdn) {
    return provider.getEventsForMsisdn(msisdn);
}

void MainWindow::loadStats(QString msisdn)
{
    startRefreshAnim();
    DataProvider* dataSource = new DataProvider;
    watcher = new QFutureWatcher< QList<StatEvent> >;
    connect(watcher, SIGNAL(finished()), this, SLOT(onDataLoaded()));
    QFuture< QList<StatEvent> > mahBoi = QtConcurrent::run(getData, *dataSource, msisdn);
    watcher->setFuture(mahBoi);
}

void MainWindow::startRefreshAnim()
{
    ui->refreshIcon->start();
}

void MainWindow::stopRefreshAnim()
{
    ui->refreshIcon->stop();
}

void MainWindow::onDataLoaded()
{
    stopRefreshAnim();
    QList<StatEvent> events = watcher->future().result();

    QListWidget* statEvents = ui->statEvents;

    for (int i = 0; i < events.size(); i++) {
        StatEvent e = events.at(i);

        QListWidgetItem* item = new QListWidgetItem();
        StatEventItemWidget* widgetItem = new StatEventItemWidget(e.getEventText(), e.getDate());
        item->setSizeHint(QSize(45,90));
        statEvents->addItem(item);
        statEvents->setItemWidget(item, widgetItem);
    }
}
