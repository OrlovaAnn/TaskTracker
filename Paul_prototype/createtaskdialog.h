#pragma once

#include <QDialog>
#include "task.h"
#include <memory>


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
    std::unique_ptr<Ui::CreateTaskDialog> ui_;
};
