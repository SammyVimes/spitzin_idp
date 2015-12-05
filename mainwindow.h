#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QCheckBox>
#include <QtConcurrent/QtConcurrent>
#include <QFuture>
#include <QFutureWatcher>
#include <QDateTime>
#include "dataprovider.h"
#include "stateventitemwidget.h"
#include "msisdn.h"

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

    void showEvent(QShowEvent* e);

    void on_exitButton_clicked();

    void on_buttonFilter_clicked();

private:
    QFutureWatcher< QList<StatEvent> >* watcher;
    QPropertyAnimation *refreshAnimation;

    void loadStats(QString msisdn);
    void loadStatsByMsisdnAndDate(MSISDN msisdn, QDateTime dateTime);
    void startRefreshAnim();
    void stopRefreshAnim();
    QPoint clickPos;
    DataProvider* dataProvider;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
