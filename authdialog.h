#ifndef AUTHDIALOG_H
#define AUTHDIALOG_H

#include "mainwindow.h"
#include <QDialog>
#include <QMouseEvent>
#include <QApplication>
#include <QtCore/QFile>

namespace Ui {
class AuthDialog;
}

class AuthDialog : public QDialog
{
    Q_OBJECT
protected:
    void mousePressEvent( QMouseEvent *);
    void mouseMoveEvent( QMouseEvent *);

public:
    explicit AuthDialog(QWidget *parent = 0);
    ~AuthDialog();

private slots:
    void on_exitButton_clicked();

    void on_authButton_clicked();

private:
    Ui::AuthDialog *ui;
    QPoint clickPos;
};

#endif // AUTHDIALOG_H
