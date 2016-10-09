#pragma once

#include "tasklistitemwidget.h"

#include <memory>
#include <map>

#include <QMainWindow>
#include <QPushButton>

#include "taskfwd.h"

namespace Ui
{
    class MainWindow;
}

/// Main window of the Task Tracker.
/// Contains list of the tasks and
/// allows tasks editing and filtering.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    /// Called a user wants to add new task
    void on_addNewTaskButton_clicked();

    /// Called when task changes its state
    /// \param  id of the task which changed
    void on_task_changed(Model::TaskId id);

    /// Called when filtering query has changed
    void on_filteringUpdateNeeded();

private:
    std::unique_ptr<Ui::MainWindow> ui_;

    // Stores ui buttons which correspond to task types
    std::map<Model::TaskStateType, QPushButton*> typeButtons_;

    // Stores created widgets corresponding to some task id
    using WidgetPtr = std::unique_ptr<TasklistItemWidget>;
    std::map<Model::TaskId, WidgetPtr> tasks_;

    // Filter currently used to show and hide tasks
    using TaskFilterPtr = std::unique_ptr<Model::TaskFilter>;
    TaskFilterPtr currentFilter_;

    /// Create and add new task to the list
    /// \param  settings to be used
    void drawNewTask(const Model::TaskSettings& settings);

    /// Update visibility of all tasks or single task
    void updateTasksVisibility();
    void updateTaskVisibility(Model::TaskId id);
    void updateTaskVisibility(TasklistItemWidget& task);

    /// Add some default tasks to the list
    /// (for the testing needs only)
    void addDefaultTasks();

    /// Check if the task with given type should be shown in the list
    /// \param  type  task state type
    /// \return  true if the task should be shown,
    ///          false if the task should be hidden
    bool shouldShowType(Model::TaskStateType type) const;

    /// Update internal filter query
    void updateFilter();

    /// Connect to children widgets signals
    void connectToButtons();
};
