#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include "dataprovider.h"
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

    void onDataLoaded();

private:
    QFutureWatcher< QList<StatEvent> >* watcher;
    QPropertyAnimation *refreshAnimation;

    void loadStats(QString msisdn);
    void startRefreshAnim();
    void stopRefreshAnim();
    QPoint clickPos;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
