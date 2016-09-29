#pragma once

#include <QString>

#include "tasksettings.h"

#include <memory>

namespace Model
{
    /// Represents simple task with the state of the progress
    class Task
    {
    public:

        /// Construct task from the settings
        Task(TaskId id, const TaskSettings& settings);

        Task(const Task&) = default;
        Task& operator=(const Task&) = default;

        /// Getter for the task id
        TaskId getId() const;

        /// Getter & setter for the task name
        QString getName() const;
        void setName(const QString& name);

        /// Getter & setter for the detailed description
        QString getDescription() const;
        void setDescription(const QString& description);

        /// Log work on the task
        /// \param  amountDone   amount of time spent
        void logWork(double amountDone);

        /// Time spent relative to initial estimate
        /// \return  percentage of time spent
        ///          normally between 0 and 100
        ///          can be over 100 if the task is overdue
        double getPercentageDone() const;

        /// Getter for the time spent
        /// \return  amount of time already spent
        double getDone() const;

        /// Getter for the original estimate
        /// \return  initial time estimate
        double getPlanned() const;

        /// Check if the task is overdue
        /// \return  true if the time spent exceeds initial estimate
        bool overdue() const;

        /// Getter & setter for the task settings
        TaskSettings getSettings() const;
        void setSettings(const TaskSettings& settings);

    private:
        TaskId id_;             /// unique id of the task
        TaskSettings settings_; /// task's properties

        TaskState& state(); /// access state
        const TaskState& state() const; /// get state
    };

}
