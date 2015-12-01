#include "stateventitemwidget.h"
#include "ui_stateventitemwidget.h"

void StatEventItemWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

StatEventItemWidget::StatEventItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatEventItemWidget)
{
    ui->setupUi(this);

    QString array[4] = {"ВКонтакте от Гришки", "Telegram", "YouTube", "DachaMonitor"};
    int min = 0;
    int max = 3;
    int output = min + (rand() % (int)(max - min + 1));
    ui->label_2->setText("Запущено приложение " + array[output]);
}

StatEventItemWidget::~StatEventItemWidget()
{
    delete ui;
}
