QT += core gui widgets

TARGET = task_tracker
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    tasklistitemwidget.cpp \
    task.cpp \
    createtaskdialog.cpp \
    tasklist.cpp

HEADERS += mainwindow.h \
    tasklistitemwidget.h \
    task.h \
    createtaskdialog.h \
    tasksettings.h \
    tasklist.h

FORMS += mainwindow.ui \
    tasklistitemwidget.ui \
    createtaskdialog.ui
