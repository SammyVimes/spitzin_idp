#include "stateventitemwidget.h"
#include "ui_stateventitemwidget.h"

void StatEventItemWidget::enterEvent(QEvent *e)
{
    bool tmpRekt = true;
    if (tmpRekt != rekt) {
        rekt = tmpRekt;
        updateRekt();
    }
}

void StatEventItemWidget::leaveEvent(QEvent *e)
{
    bool tmpRekt = false;
    if (tmpRekt != rekt) {
        rekt = tmpRekt;
        updateRekt();
    }
}

void StatEventItemWidget::updateRekt()
{
    ui->label_2->setProperty("hovered", QVariant(rekt));
    ui->label_2->style()->unpolish(ui->label_2);
    ui->label_2->style()->polish(ui->label_2);

    ui->label->setProperty("hovered", QVariant(rekt));
    ui->label->style()->unpolish(ui->label);
    ui->label->style()->polish(ui->label);
}

void StatEventItemWidget::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

StatEventItemWidget::StatEventItemWidget(QString text, QDateTime date):QWidget(0),
    ui(new Ui::StatEventItemWidget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    rekt = false;

    QString day = QString::number(date.date().day());
    QString month = QString::number(date.date().month());
    QString year = QString::number(date.date().year());

    QString hour = QString::number(date.time().hour());
    QString minute = QString::number(date.time().minute());

    ui->label->setText(hour + ":" + minute + " " + day + "." + month + "." + year);
    ui->label_2->setText(text);
}

StatEventItemWidget::StatEventItemWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StatEventItemWidget)
{
    ui->setupUi(this);
    this->setMouseTracking(true);
    rekt = false;
}

StatEventItemWidget::~StatEventItemWidget()
{
    delete ui;
}
