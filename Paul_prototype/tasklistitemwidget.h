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
    TasklistItemWidget(Model::Task& task, QWidget *parent = nullptr);
    ~TasklistItemWidget();

    Model::TaskStateType getType() const
    {
        return task_.getSettings().state().type_;
    }

public:
    void paintEvent(QPaintEvent *) override;

private slots:
    void on_logBtn_clicked();

    void on_detailsBtn_clicked();

signals:
    void type_changed(Model::TaskId id);

private:
    std::unique_ptr<Ui::TasklistItemWidget> ui_;

    Model::Task& task_;

    void initialize();
    void updateWidgetText();
    void updatePercentDone();
    void updateName();
    void updateNameFont();
};
