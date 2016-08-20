#pragma once

#include <QDialog>
#include "task.h"

namespace Ui
{
    class CreateTaskDialog;
}

class CreateTaskDialog : public QDialog
{
public:
    CreateTaskDialog();

    QString getText() const;

    Model::Task createTask() const;

private:
    Ui::CreateTaskDialog* ui_;
};
