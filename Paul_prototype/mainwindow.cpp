#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "tasklistitemwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    ui_->scrollArea->widget()->setLayout(new QVBoxLayout());
    ui_->scrollArea->widget()->layout()->addWidget(new TasklistItemWidget(ui_->scrollArea->widget(), "Task name 1", 0.81, 0.62));
    ui_->scrollArea->widget()->layout()->addWidget(new TasklistItemWidget(ui_->scrollArea->widget(), "Task name 2", 0.55, 0.77));
    ui_->scrollArea->widget()->layout()->addWidget(new TasklistItemWidget(ui_->scrollArea->widget(), "Task name 3", 0.23, 0.89));
    ui_->scrollArea->widget()->layout()->addWidget(new TasklistItemWidget(ui_->scrollArea->widget(), "Task name 4", 0.91, 0.00));
    ui_->scrollArea->widget()->layout()->addWidget(new TasklistItemWidget(ui_->scrollArea->widget(), "Task name 5", 0.42, 0.42));
    ui_->scrollArea->widget()->layout()->addItem(new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

MainWindow::~MainWindow()
{
}
