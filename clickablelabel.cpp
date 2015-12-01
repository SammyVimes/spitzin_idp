#include "clickablelabel.h"

ClickableLabel::ClickableLabel(const QString& text, QWidget* parent)
    : QLabel(parent)
{
    setText(text);
    isActive = false;
}

ClickableLabel::ClickableLabel(QWidget *parent, Qt::WindowFlags f)
    : QLabel(parent, f) {
    isActive = false;
}

ClickableLabel::~ClickableLabel()
{
}

void ClickableLabel::setActive(bool isActive) {
    this->isActive = isActive;
    this->setProperty("pressed", QVariant(isActive));
    style()->unpolish(this);
    style()->polish(this);
}

void ClickableLabel::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

