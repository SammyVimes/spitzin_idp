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
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_child1Btn_clicked()
{
    this->ui->child1Btn->setActive(true);
    this->ui->child2Btn->setActive(false);


    QListWidget* statEvents = ui->statEvents;

    QListWidgetItem* item = new QListWidgetItem();
    StatEventItemWidget* widgetItem = new StatEventItemWidget();

    item->setSizeHint(QSize(45,90));

    statEvents->addItem(item);
    statEvents->setItemWidget(item, widgetItem);
}

void MainWindow::on_child2Btn_clicked()
{
    this->ui->child2Btn->setActive(true);
    this->ui->child1Btn->setActive(false);
}
