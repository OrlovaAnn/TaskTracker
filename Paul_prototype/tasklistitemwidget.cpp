#include <QPainter>

#include "tasklistitemwidget.h"
#include "ui_tasklistitemwidget.h"
#include "task.h"

TasklistItemWidget::TasklistItemWidget(QWidget *parent, const QString & name, double planned, double done)
    : QWidget(parent)
    , ui_(new Ui::TasklistItemWidget)
    , task_(new Model::Task(name, "", planned, done))
{
    ui_->setupUi(this);
    ui_->name->setText(name);

    const int percentLeft = int(100 * (done - planned));
    const int percentDone = 100 * done;
    const char signLeft = percentLeft >= 0 ? '+' : '-';
    const auto percentDoneText = QString("%1% (%2%3%)").arg(percentDone).arg(signLeft).arg(abs(percentLeft));
    ui_->percentDone->setText(percentDoneText);
}

TasklistItemWidget::~TasklistItemWidget()
{
}

void TasklistItemWidget::paintEvent(QPaintEvent * p)
{
    if(!task_)
    {
        return;
    }

    QPainter painter(this);

    const int wDone = int(size().width() * task_->getDone());
    const int wPlanned = int(size().width() * task_->getPlanned());

    painter.fillRect(0, 0, width(), height(), QColor(220,220,220));

    if (task_->overdue())
    {
        painter.fillRect(0, 0, wPlanned, height(), QColor(64,200,64));
        painter.fillRect(wPlanned, 0, wDone - wPlanned, height(), QColor(0,255,0, 128));
    }
    else
    {
        painter.fillRect(0, 0, wDone, height(), QColor(64,200,64));
        painter.fillRect(wDone, 0, wPlanned - wDone, height(), QColor(255,0,0, 128));
    }

    QWidget::paintEvent(p);
}
