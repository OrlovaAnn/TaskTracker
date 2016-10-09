#include <QPainter>

#include "ui_tasklistitemwidget.h"
#include "tasklistitemwidget.h"
#include "createtaskdialog.h"
#include <qmessagebox.h>

TasklistItemWidget::TasklistItemWidget(Model::Task& task, QWidget *parent)
    : QWidget(parent)
    , task_(task)
    , ui_(std::make_unique<Ui::TasklistItemWidget>())
{
    initialize();
}

TasklistItemWidget::~TasklistItemWidget()
{
}

Model::TaskStateType TasklistItemWidget::getType() const
{
    return task_.getSettings().state().type_;
}

const Model::Task& TasklistItemWidget::getTask() const
{
    return task_;
}

void TasklistItemWidget::paintEvent(QPaintEvent * p)
{
    const QColor GREEN(64,200,64);
    const QColor LIGHT_GREEN(0,255,0, 128);
    const QColor GREY(220,220,220);
    const QColor LIGHT_RED(255,0,0, 128);

    updateWidgetText();

    QPainter painter(this);

    const int wDone = int(size().width() * task_.getDone());
    const int wPlanned = int(size().width() * task_.getPlanned());

    painter.fillRect(0, 0, width(), height(), GREY);

    if (task_.overdue())
    {
        painter.fillRect(0, 0, wPlanned, height(), GREEN);
        painter.fillRect(wPlanned, 0, wDone - wPlanned, height(), LIGHT_GREEN);
    }
    else
    {
        painter.fillRect(0, 0, wDone, height(), GREEN);
        painter.fillRect(wDone, 0, wPlanned - wDone, height(), LIGHT_RED);
    }

    QWidget::paintEvent(p);
}

void TasklistItemWidget::on_logBtn_clicked()
{
    task_.logWork(0.1);
    repaint();
}


/// Check if the task should be striked out in the list
/// \param  task  task to check
/// \return  true if the task should be striked out, false otherwise
bool shouldStrikeOutTask(const Model::Task& task)
{
    return task.getSettings().state().type_ == Model::TaskStateType::Closed;
}

void TasklistItemWidget::updateNameFont()
{
    const bool shouldStrikeOut = shouldStrikeOutTask(task_);
    auto font = ui_->name->font();
    font.setStrikeOut(shouldStrikeOut);
    ui_->name->setFont(font);
}

void TasklistItemWidget::updateName()
{
    const auto& name = task_.getName();
    ui_->name->setText(name);
    updateNameFont();
}

void TasklistItemWidget::updatePercentDone()
{
    const double& done = task_.getDone();
    const double& planned = task_.getPlanned();

    const int percentLeft = int(100 * (done - planned));
    const int percentDone = 100 * done;
    const char signLeft = percentLeft >= 0 ? '+' : '-';
    const auto percentDoneText = QString("%1% (%2%3%)").arg(percentDone).arg(signLeft).arg(abs(percentLeft));
    ui_->percentDone->setText(percentDoneText);
}

void TasklistItemWidget::updateWidgetText()
{
    updatePercentDone();
    updateName();
}

void TasklistItemWidget::on_detailsBtn_clicked()
{
    auto newDlg = std::make_unique<CreateTaskDialog>(task_.getSettings());
    if(newDlg->exec())
    {
        task_.setSettings(newDlg->getSettings());
        emit task_changed(task_.getId());
    }
}

void TasklistItemWidget::initialize()
{
    ui_->setupUi(this);
    updateWidgetText();
}
