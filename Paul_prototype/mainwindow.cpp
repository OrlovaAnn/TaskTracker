#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "createtaskdialog.h"
#include "tasklistitemwidget.h"
#include "taskmanager.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(std::make_unique<Ui::MainWindow>())
{
    ui_->setupUi(this);

    ui_->scrollArea->widget()->setLayout(new QVBoxLayout());

    addDefaultTasks();
}

void MainWindow::addDefaultTasks()
{
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

void MainWindow::on_pushButton_clicked()
{
    auto newDlg = std::make_unique<CreateTaskDialog>();
    if(newDlg->exec())
    {
        drawNewTask(newDlg->getSettings());
    }
}

void MainWindow::drawNewTask(const Model::TaskSettings& settings)
{
    auto& mgr = Model::TaskManager::get();
    const auto newTaskId = mgr.createTask(settings);
    auto* newTask = mgr.findTask(newTaskId);
    if(!newTask)
        return;

    auto* widget = ui_->scrollArea->widget();
    if(!widget)
        return;

    tasks_[newTaskId] = std::make_unique<TasklistItemWidget>(*newTask, widget);
    auto& newWidget = *tasks_.at(newTaskId);
    widget->layout()->addWidget(&newWidget);
    QObject::connect(&newWidget, SIGNAL(type_changed(Model::TaskId)), this, SLOT(on_task_type_changed(Model::TaskId)));
    updateTaskVisibility(newWidget);
}

void MainWindow::updateTaskVisibility(Model::TaskId id)
{
    auto& taskIt = tasks_.find(id);
    if(taskIt == tasks_.end() || !taskIt->second)
        return;

    updateTaskVisibility(*taskIt->second);
}

void MainWindow::updateTaskVisibility(TasklistItemWidget& task)
{
    const auto type = task.getType();

    const bool checked = isFilterChecked(type);
    checked ? task.show() : task.hide() ;
}

void MainWindow::updateTasksVisibility()
{
    for(auto& pair : tasks_)
    {
        if(!pair.second)
            continue;

        updateTaskVisibility(*pair.second);
    }
}

void MainWindow::on_filterOpen_toggled(bool)
{
    updateTasksVisibility();
}

void MainWindow::on_filterInProgress_toggled(bool)
{
    updateTasksVisibility();
}

void MainWindow::on_filterClosed_toggled(bool)
{
    updateTasksVisibility();
}

void MainWindow::on_task_type_changed(Model::TaskId id)
{
    updateTaskVisibility(id);
}

bool MainWindow::isFilterChecked(Model::TaskStateType type) const
{
    switch(type)
    {
    case Model::TaskStateType::Open:
        return ui_->filterOpen->isChecked();
    case Model::TaskStateType::InProgress:
        return ui_->filterInProgress->isChecked();
    case Model::TaskStateType::Closed:
        return ui_->filterClosed->isChecked();
    default:
        return false;
    }
}
