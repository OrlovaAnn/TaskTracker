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

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_filterOpen_toggled(bool);
    void on_filterInProgress_toggled(bool);
    void on_filterClosed_toggled(bool);

    void on_task_type_changed(Model::TaskId id);

private:
    std::unique_ptr<Ui::MainWindow> ui_;

    using WidgetPtr = std::unique_ptr<TasklistItemWidget>;
    std::map<Model::TaskId, WidgetPtr> tasks_;

    void drawNewTask(const Model::TaskSettings& settings);

    void updateTasksVisibility();
    void updateTaskVisibility(Model::TaskId id);
    void updateTaskVisibility(TasklistItemWidget& task);
    void addDefaultTasks();
    bool isFilterChecked(Model::TaskStateType type) const;
};
