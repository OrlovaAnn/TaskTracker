QT += core gui widgets

TARGET = task_tracker
TEMPLATE = app

SOURCES += main.cpp \
    mainwindow.cpp \
    tasklistitemwidget.cpp \
    task.cpp \
    createtaskdialog.cpp \
    tasklist.cpp \
    taskmanager.cpp \
    taskstate.cpp \
    tasksettings.cpp \
    taskfilter.cpp \
    taskfilterfactory.cpp

HEADERS += mainwindow.h \
    tasklistitemwidget.h \
    task.h \
    createtaskdialog.h \
    tasksettings.h \
    tasklist.h \
    taskmanager.h \
    taskstate.h \
    taskfwd.h \
    taskfilter.h \
    taskfilterfactory.h

FORMS += mainwindow.ui \
    tasklistitemwidget.ui \
    createtaskdialog.ui

DISTFILES +=

RESOURCES += \
    icons.qrc
