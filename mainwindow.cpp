#include "mainwindow.h"
#include "ui_mainwindow.h"

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
}

void MainWindow::on_child2Btn_clicked()
{
    this->ui->child2Btn->setActive(true);
    this->ui->child1Btn->setActive(false);
}
