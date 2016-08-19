#pragma once

#include <memory>
#include <task.h>

#include <QWidget>

namespace Ui
{
  class TasklistItemWidget;
}

namespace Model
{
    class Task;
}

class TasklistItemWidget : public QWidget
{
    Q_OBJECT

public:
    TasklistItemWidget(QWidget *parent = nullptr, const QString & name = "", double planned = 0, double done = 0);
    ~TasklistItemWidget();

public:
    void paintEvent(QPaintEvent *) override;

private:
    std::unique_ptr<Ui::TasklistItemWidget> ui_;

    std::unique_ptr<Model::Task> task_;
};
