#ifndef ROTATIONLABEL
#define ROTATIONLABEL


#include <QtDesigner/QDesignerExportWidget>
#include <QtDesigner/QtDesigner>
#include <QtGui>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QtCore/QPropertyAnimation>

#include <math.h>

#ifdef  M_PI
#define PI M_PI
#else
#define PI 3.14159265358979323846
#endif


class PixmapItem : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
    Q_PROPERTY(qreal rotate READ rotation WRITE setRot/*ation*/)
public:
    PixmapItem(const QPixmap &pix) : QGraphicsPixmapItem(pix){

        // Set point rotation
        crX = qreal(pixmap().width())  / 2.0;
        crY = qreal(pixmap().height()) / 2.0;
        // Radius rotation
        crR = sqrt(crX*crX + crY*crY);


        // Adjust point from scene
        crX = qreal(pixmap().width())  / 2.0F - 0.0F;
        crY = qreal(pixmap().height()) / 2.0F - 5.0F;
    }

    inline
    void setRot(qreal a)
    {
        qreal dxc = cos(((a+225.0F) / 360.0F) * 2 * PI) * crR + crX;
        qreal dyc = sin(((a+225.0F) / 360.0F) * 2 * PI) * crR + crY;

        this->setPos(dxc, dyc);
        setRotation(a);
    }


private:
    qreal crR; // radius
    qreal crX; // point rotation x
    qreal crY; // point rotation y
};

class RotationLabel : public QWidget
{
    Q_OBJECT
public:

    inline explicit
    RotationLabel(QWidget *parent = 0): QWidget(parent)
    {
    }

    inline
    ~RotationLabel()
    {
        delete an_pix;
        delete scene;
        delete view;
    }

    inline void start(){ m_anim->start(); }
    inline void stop() { m_anim->stop();  }

    inline QString path() {
        return _path;
    }

    void showEvent(QShowEvent* event) {
        view->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    }

    inline void setPath(QString path) {
        this->_path = path;
        QPixmap pixmap(_path);
        an_pix = new PixmapItem(pixmap);
        m_anim = new QPropertyAnimation(an_pix,"rotate",this);
        m_anim->setEasingCurve(QEasingCurve::Linear);
        m_anim->setStartValue(qreal(0.0F));
        m_anim->setEndValue(qreal(360.0F));
        m_anim->setDuration(1333);
        m_anim->setDirection(QAbstractAnimation::Forward);// Forward Backward
        m_anim->setLoopCount(-1);

        scene = new QGraphicsScene(this);
        scene->addItem(an_pix);
        QRectF r = scene->sceneRect();

        view = new QGraphicsView(scene, this);
        view->setScene(scene);
        QSize sz = this->size();
        view->setBaseSize(sz);
        view->setFixedSize(sz);
        view->show();
    }

private:
    QPropertyAnimation *m_anim;
    PixmapItem         *an_pix;
    QGraphicsScene     *scene;
    QGraphicsView      *view;
    QString _path;
};


#endif // ROTATIONLABEL
