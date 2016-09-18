#pragma once

#include "tasklistitemwidget.h"

#include <memory>
#include <vector>

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

namespace Model
{
    struct TaskSettings;
    class TaskList;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    std::unique_ptr<Ui::MainWindow> ui_;

    using WidgetPtr = std::unique_ptr<TasklistItemWidget>;
    std::vector<WidgetPtr> tasks_;


    void drawNewTask(const Model::TaskSettings& settings);
};
