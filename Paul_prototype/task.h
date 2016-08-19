#pragma once

#include <QString>

namespace Model
{
    /// Represents simple task with the state of the progress
    class Task
    {
    public:
        /// ctor
        /// \param  name         name of the task
        /// \param  description  detailed description
        /// \param  planned      initial time estimate
        /// \param  done         amount of time already spent
        Task(const QString& name, const QString& description, double planned, double done = 0.0);

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
    private:
        QString name_ = "New task";
        QString description_ = "";
        double planned_;
        double done_ = 0.0;
    };

}
