#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::mousePressEvent(QMouseEvent* e)
{
    clickPos = e->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent* e)
{
    move( e->globalPos() - clickPos );
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    watcher(0)
{
    ui->setupUi(this);
    ui->refreshIcon->setPath(QString::fromUtf8(":/img/icon_refresh.png"));
    setWindowTitle("ParentalCare");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *e)
{
    this->ui->child1Btn->setActive(true);
    this->ui->child2Btn->setActive(false);
    loadStats("+79218711725");
}

void MainWindow::on_child1Btn_clicked()
{
    this->ui->child1Btn->setActive(true);
    this->ui->child2Btn->setActive(false);
    loadStats("+79218711725");
}

void MainWindow::on_child2Btn_clicked()
{
    this->ui->child2Btn->setActive(true);
    this->ui->child1Btn->setActive(false);
    loadStats("+79215988738");
}

//вместо extern сделаем просто функцию тут
QList<StatEvent> getData(DataProvider& provider, QString msisdn) {
    return provider.getEventsForMsisdn(msisdn);
}

QList<StatEvent> getData(DataProvider& provider, MSISDN msisdn, QDateTime dateTime) {
    return provider.selectByDateAndMsisdn(msisdn, dateTime);
}

void MainWindow::loadStats(QString msisdn)
{
    if (watcher) {
        QFuture< QList<StatEvent> > mahOldBoi = (QFuture< QList<StatEvent> >) watcher->future();
        mahOldBoi.cancel();
        delete watcher;
        watcher = 0;
    }
    startRefreshAnim();
    DataProvider* dataSource = new DataProvider;
    watcher = new QFutureWatcher< QList<StatEvent> >;
    connect(watcher, SIGNAL(finished()), this, SLOT(onDataLoaded()));
    QFuture< QList<StatEvent> > mahBoi = QtConcurrent::run(getData, *dataSource, msisdn);
    watcher->setFuture(mahBoi);
}

//FIXME: duplicate
void MainWindow::loadStatsByMsisdnAndDate(MSISDN msisdn, QDateTime dateTime)
{
    if (watcher) {
        QFuture< QList<StatEvent> > mahOldBoi = (QFuture< QList<StatEvent> >) watcher->future();
        mahOldBoi.cancel();
        delete watcher;
        watcher = 0;
    }
    startRefreshAnim();
    DataProvider* dataSource = new DataProvider;
    watcher = new QFutureWatcher< QList<StatEvent> >;
    connect(watcher, SIGNAL(finished()), this, SLOT(onDataLoaded()));
    QFuture< QList<StatEvent> > mahBoi = QtConcurrent::run(getData, *dataSource, msisdn, dateTime);
    watcher->setFuture(mahBoi);
}

void MainWindow::onDataLoaded() {
    stopRefreshAnim();
    QList<StatEvent> events = watcher->future().result();

    QListWidget* statEvents = ui->statEvents;
    statEvents->clear();
    for (int i = 0; i < events.size(); i++) {
        StatEvent e = events.at(i);

        QListWidgetItem* item = new QListWidgetItem();
        StatEventItemWidget* widgetItem = new StatEventItemWidget(e.getEventText(), e.getDate());
        item->setSizeHint(QSize(45,90));
        statEvents->addItem(item);
        statEvents->setItemWidget(item, widgetItem);
    }
}

void MainWindow::on_buttonFilter_clicked() {
    QDateTime dTime = ui->dateFilter->dateTime();
    loadStatsByMsisdnAndDate(MSISDN(QString("79218711725")), dTime);
}

void MainWindow::on_exitButton_clicked() {
    this->close();
}

//refresh anim
void MainWindow::startRefreshAnim()
{
    ui->refreshIcon->start();
}

void MainWindow::stopRefreshAnim()
{
    ui->refreshIcon->stop();
}
