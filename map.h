#ifndef MAP_H
#define MAP_H

#include <QWebView>

class QNetworkAccessManager;

class Map : public QWebView
{
    Q_OBJECT

public:
    Map(QWidget *parent=0);
    void selectMarker(int pos);
protected:
    void resizeEvent(QResizeEvent *event);

signals:
    void reloadMap();
};

#endif // MAP_H
