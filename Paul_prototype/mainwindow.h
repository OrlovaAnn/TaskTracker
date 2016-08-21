#pragma once

#include <memory>

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

namespace Model
{
    struct TaskSettings;
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

    void drawNewTask(const Model::TaskSettings& settings);
};
