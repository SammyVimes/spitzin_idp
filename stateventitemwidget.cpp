#include "stateventitemwidget.h"
#include "ui_stateventitemwidget.h"

StatEventItemWidget::StatEventItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatEventItemWidget)
{
    ui->setupUi(this);
}

StatEventItemWidget::~StatEventItemWidget()
{
    delete ui;
}
