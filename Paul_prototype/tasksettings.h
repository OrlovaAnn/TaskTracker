#pragma once

#include <QString>
#include "taskstate.h"
#include "taskfwd.h"

namespace Model
{

    /// Represents properties of the task
    /// and its state of the progress
    struct TaskSettings
    {
        TaskSettings(QString name, QString description, double planned, double done = 0);

        QString name_;          /// name of the task
        QString description_;   /// detailed description
        TaskState state_;       /// progress state of the task

        /// Access task state member
        TaskState& state();

        /// Get task state
        const TaskState& state() const;
    };

}
