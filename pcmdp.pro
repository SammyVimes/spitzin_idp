#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T01:13:45
#
#-------------------------------------------------

QT       += core gui widgets designer quickwidgets qml quick declarative

TARGET = pcmdp
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    clickablelabel.cpp \
    stateventitemwidget.cpp \
    dataprovider.cpp

HEADERS  += mainwindow.h \
    clickablelabel.h \
    stateventitemwidget.h \
    dataprovider.h \
    statevent.h \
    rotationlabel.h

FORMS    += mainwindow.ui \
    stateventitemwidget.ui

OTHER_FILES += \
    ChartForm.ui.qml

DISTFILES += \
    ChartForm.ui.qml \
    QChart.qml \
    MyChart.qml \
    QChartGallery.js \
    QChart.js \
    QChartGallery.js \
    style.qss \
    BarChart.qml

RESOURCES += \
    stylesheet.qrc

