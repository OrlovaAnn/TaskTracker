QT += core gui widgets

TARGET = task_tracker
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    tasklistitemwidget.cpp \
    task.cpp \
    createtaskdialog.cpp

HEADERS += mainwindow.h \
    tasklistitemwidget.h \
    task.h \
    createtaskdialog.h

FORMS += mainwindow.ui \
    tasklistitemwidget.ui \
    createtaskdialog.ui
