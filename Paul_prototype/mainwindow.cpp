#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "tasklistitemwidget.h"
#include "task.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(new Ui::MainWindow)
{
    ui_->setupUi(this);

    ui_->scrollArea->widget()->setLayout(new QVBoxLayout());

    drawNewTask({"Task name 1", "", 0.81, 0.62});
    drawNewTask({"Task name 2", "", 0.55, 0.77});
    drawNewTask({"Task name 3", "", 0.23, 0.89});
    drawNewTask({"Task name 4", "", 0.91, 0.00});
    drawNewTask({"Task name 5", "", 0.42, 0.42});
    drawNewTask({"Read a book", "I would like to read all the books in the world!", 0.68, 0.15});
    ui_->scrollArea->widget()->layout()->addItem(new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding));
}

MainWindow::~MainWindow()
{
}

void MainWindow::drawNewTask(const Model::TaskSettings& settings)
{
    const Model::Task newTask(settings);
    ui_->scrollArea->widget()->layout()->addWidget(new TasklistItemWidget(newTask, ui_->scrollArea->widget()));
}
