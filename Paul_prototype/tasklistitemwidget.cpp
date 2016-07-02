#include <QPainter>

#include "tasklistitemwidget.h"
#include "ui_tasklistitemwidget.h"

TasklistItemWidget::TasklistItemWidget(QWidget *parent, const QString & name, double planned, double done)
    : QWidget(parent)
    , ui_(new Ui::TasklistItemWidget)
    , planned_(planned)
    , done_(done)
{
    ui_->setupUi(this);
    ui_->name->setText(name);

    int d = int(100 * (done - planned));
    ui_->percentDone->setText(QString("%1% (%2%3%)").arg(int(100 * done)).arg(d >= 0 ? '+' : '-').arg(abs(d)));
}

TasklistItemWidget::~TasklistItemWidget()
{
}

void TasklistItemWidget::paintEvent(QPaintEvent * p)
{
    QPainter painter(this);

    const int wDone = int(size().width() * done_);
    const int wPlanned = int(size().width() * planned_);

    painter.fillRect(0, 0, width(), height(), QColor(220,220,220));

    if (done_ >= planned_)
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
