#pragma once

#include <memory>
#include <task.h>

#include <QWidget>

namespace Ui
{
    class TasklistItemWidget;
}

class TasklistItemWidget : public QWidget
{
    Q_OBJECT

public:
    TasklistItemWidget(QWidget *parent = nullptr, const QString & name = "", double planned = 0, double done = 0);
    TasklistItemWidget(const Model::Task& task, QWidget *parent = nullptr);
    ~TasklistItemWidget();

public:
    void paintEvent(QPaintEvent *) override;

private slots:
    void on_logBtn_clicked();

    void on_detailsBtn_clicked();

private:
    std::unique_ptr<Ui::TasklistItemWidget> ui_;

    Model::Task task_;

    void initialize();
    void updateWidgetText();
};
