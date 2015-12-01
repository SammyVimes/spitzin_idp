#ifndef STATEVENTITEMWIDGET_H
#define STATEVENTITEMWIDGET_H

#include <QWidget>

namespace Ui {
class StatEventItemWidget;
}

class StatEventItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StatEventItemWidget(QWidget *parent = 0);
    ~StatEventItemWidget();

private:
    Ui::StatEventItemWidget *ui;
};

#endif // STATEVENTITEMWIDGET_H
