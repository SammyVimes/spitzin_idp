#include "map.h"

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QWebFrame>
#include <QWebPage>
#include <QResizeEvent>
#include <math.h>

Map::Map(QWidget *parent) : QWebView(parent)
{
}

void Map::selectMarker(int pos)
{
    QStringList scriptStr;
    switch(pos) {
    case 0:
        scriptStr << QString("map.setCenter(new GLatLng(59.972271, 30.323396), 13);");
        break;
    case 1:
        scriptStr << QString("map.setCenter(new GLatLng(59.946522, 30.498118), 13);");
        break;
    }
    page()->mainFrame()->evaluateJavaScript( scriptStr.join("\n") );
}


void Map::resizeEvent(QResizeEvent *event)
{
    if(page())
        page()->setViewportSize(event->size());

    int x = event->size().width();
    int y = event->size().height();

    QStringList scriptStr;
    scriptStr
        << "elem = document.getElementById(\"map\");"
        << QString("elem.style.width = '%1px';").arg(x-6)
        << QString("elem.style.height = '%2px';").arg(y-6);

    page()->mainFrame()->evaluateJavaScript( scriptStr.join("\n") );
}


