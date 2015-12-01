#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QVariant>
#include <QStyle>

class ClickableLabel : public QLabel
{
Q_OBJECT
public:
    explicit ClickableLabel( const QString& text="", QWidget* parent=0 );
    explicit ClickableLabel(QWidget *parent=0, Qt::WindowFlags f=0);
    void setActive(bool active);
    ~ClickableLabel();
signals:
    void clicked();
protected:
    void mousePressEvent(QMouseEvent* event);
private:
    bool isActive;
};

#endif // CLICKABLELABEL_H
