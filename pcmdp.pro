#-------------------------------------------------
#
# Project created by QtCreator 2015-11-30T01:13:45
#
#-------------------------------------------------

QT       += core gui widgets designer quickwidgets qml quick

TARGET = pcmdp
TEMPLATE = app



SOURCES += main.cpp\
        mainwindow.cpp \
    clickablelabel.cpp \
    stateventitemwidget.cpp \
    dataprovider.cpp \
    msisdn.cpp \
    authdialog.cpp

HEADERS  += mainwindow.h \
    clickablelabel.h \
    stateventitemwidget.h \
    dataprovider.h \
    statevent.h \
    rotationlabel.h \
    msisdn.h \
    coreutils.h \
    authdialog.h

FORMS    += mainwindow.ui \
    stateventitemwidget.ui \
    authdialog.ui

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
    BarChart.qml \
    dialog.qss

RESOURCES += \
    stylesheet.qrc

