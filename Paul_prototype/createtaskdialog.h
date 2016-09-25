#pragma once

#include <QDialog>
#include <memory>

#include "tasksettings.h"

namespace Ui
{
    class CreateTaskDialog;
}

/// Dialog to input data for the new task
class CreateTaskDialog : public QDialog
{
public:
    /// ctor
    CreateTaskDialog();

    CreateTaskDialog(const Model::TaskSettings& settings);

    /// Construct task settings based on the dialog controls
    /// \return  task settings to be used
    Model::TaskSettings getSettings() const;

private:
    std::unique_ptr<Ui::CreateTaskDialog> ui_;
};
