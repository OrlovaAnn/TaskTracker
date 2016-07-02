QT += core gui widgets

TARGET = task_tracker
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    tasklistitemwidget.cpp

HEADERS += mainwindow.h \
    tasklistitemwidget.h

FORMS += mainwindow.ui \
    tasklistitemwidget.ui
