#pragma once

#include <memory>

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
    ~TasklistItemWidget();

public:
    void paintEvent(QPaintEvent *) override;

private:
    std::unique_ptr<Ui::TasklistItemWidget> ui_;

    double planned_ = 0;
    double done_ = 0;
};
