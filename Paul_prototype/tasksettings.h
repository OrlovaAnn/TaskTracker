#pragma once

#include <QString>

namespace Model
{

    /// Represents properties of the task
    /// and its state of the progress
    struct TaskSettings
    {
        QString name_;          /// name of the task
        QString description_;   /// detailed description
        double planned_;        /// initial time estimate
        double done_;           /// amount of time already spent
    };

}
