#ifndef STATEVENTITEMWIDGET_H
#define STATEVENTITEMWIDGET_H

#include <QWidget>
#include <QStyle>
#include <QPainter>

namespace Ui {
class StatEventItemWidget;
}

class StatEventItemWidget : public QWidget
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent *);
    explicit StatEventItemWidget(QWidget *parent = 0);
    ~StatEventItemWidget();

private:
    Ui::StatEventItemWidget *ui;
};

#endif // STATEVENTITEMWIDGET_H
