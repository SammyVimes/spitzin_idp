#ifndef STATEVENTITEMWIDGET_H
#define STATEVENTITEMWIDGET_H

#include <QWidget>
#include <QStyle>
#include <QPainter>
#include <QDateTime>
#include <QMouseEvent>

namespace Ui {
class StatEventItemWidget;
}

class StatEventItemWidget : public QWidget
{
    Q_OBJECT

protected:
    void enterEvent(QEvent* e);
    void leaveEvent(QEvent* e);


public:
    void paintEvent(QPaintEvent *);
    explicit StatEventItemWidget(QWidget *parent = 0);
    StatEventItemWidget(QString text, QDateTime date);
    ~StatEventItemWidget();

private:
    void updateRekt();
    Ui::StatEventItemWidget *ui;
    bool rekt;
};

#endif // STATEVENTITEMWIDGET_H
