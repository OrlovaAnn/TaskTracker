#include "mainwindow.h"

#include "ui_mainwindow.h"
#include "createtaskdialog.h"
#include "tasklistitemwidget.h"
#include "taskmanager.h"
#include "taskfilterfactory.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui_(std::make_unique<Ui::MainWindow>())
{
    ui_->setupUi(this);
    typeButtons_ =
    {
        {Model::TaskStatus::Open,       ui_->showOpen      },
        {Model::TaskStatus::InProgress, ui_->showInProgress},
        {Model::TaskStatus::Closed,     ui_->showClosed    }
    };
    updateFilter();

    connectToButtons();

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

void MainWindow::connectToButtons()
{
    for(const auto& pair : typeButtons_)
    {
        QObject::connect(pair.second, SIGNAL(clicked()), this, SLOT(on_filteringUpdateNeeded()));
    }
    QObject::connect(ui_->searchLine, SIGNAL(editingFinished()), this, SLOT(on_filteringUpdateNeeded()));
}

void MainWindow::on_addNewTaskButton_clicked()
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
    QObject::connect(&newWidget, SIGNAL(task_changed(Model::TaskId)), this, SLOT(on_task_changed(Model::TaskId)));
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
    if(!currentFilter_)
        return;

    (*currentFilter_)(task.getTask()) ? task.show() : task.hide();
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

void MainWindow::on_task_changed(Model::TaskId id)
{
    updateTaskVisibility(id);
}

void MainWindow::on_filteringUpdateNeeded()
{
    updateFilter();
    updateTasksVisibility();
}

bool MainWindow::shouldShowType(Model::TaskStatus type) const
{
    auto buttonIt = typeButtons_.find(type);
    if(buttonIt == typeButtons_.end() || !buttonIt->second)
        throw std::logic_error("Invalid task state type");

    return buttonIt->second->isChecked();
}

void MainWindow::updateFilter()
{
    const auto& factory = Model::TaskFilterFactory::get();
    auto filter = factory.getFilter(false); // show nothing by default
    for(auto pair : typeButtons_)
    {
        if(!pair.second)
            continue;  // not initialized button?..

        const auto& type = pair.first;
        if(!shouldShowType(type))
            continue;

        auto typeFilter = factory.getFilter(type);
        filter = (filter || typeFilter);
    }
    if(ui_->searchLine)
    {
        const auto& substr = ui_->searchLine->displayText();
        if(!substr.isEmpty())
            filter = (filter && factory.getFilter(substr));

    }
    currentFilter_ = std::make_unique<Model::TaskFilter>(filter);
}
