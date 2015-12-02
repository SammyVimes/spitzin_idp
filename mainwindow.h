#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QCheckBox>
#include "stateventitemwidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
protected:
    void mousePressEvent( QMouseEvent *);
    void mouseMoveEvent( QMouseEvent *);
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_child1Btn_clicked();

    void on_child2Btn_clicked();

private:
    QPoint clickPos;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
