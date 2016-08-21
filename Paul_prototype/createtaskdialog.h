#pragma once

#include <QDialog>
#include <memory>

#include "tasksettings.h"

namespace Ui
{
    class CreateTaskDialog;
}

class CreateTaskDialog : public QDialog
{
public:
    CreateTaskDialog();

    Model::TaskSettings getSettings() const;

private:
    std::unique_ptr<Ui::CreateTaskDialog> ui_;
};
