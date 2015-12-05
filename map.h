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
public slots:
    void replyFinished(QNetworkReply*);
    void loadCoordinates();
    void geoCode(const QString &address);
    void clearCoordinates();

protected:
    void resizeEvent(QResizeEvent *event);

signals:
    void reloadMap();

private:
    QNetworkAccessManager *manager;
    QList<QPointF> coordinates;
    int pendingRequests;
};

#endif // MAP_H
