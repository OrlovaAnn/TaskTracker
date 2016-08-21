#include "task.h"

namespace Model
{
    Task::Task(const TaskSettings& settings)
        : settings_(settings)
    {}

    QString Task::getName() const
    {
        return settings_.name_;
    }

    void Task::setName(const QString& name)
    {
        settings_.name_ = name;
    }

    QString Task::getDescription() const
    {
        return settings_.description_;
    }

    void Task::setDescription(const QString& description)
    {
        settings_.description_ = description;
    }

    void Task::logWork(double amountDone)
    {
        settings_.done_ += amountDone;
    }

    double Task::getPercentageDone() const
    {
        if(settings_.planned_ <= std::numeric_limits<double>::epsilon())
        {
            return 0.0;
        }
        return settings_.done_/settings_.planned_ * 100.0;
    }

    double Task::getDone() const
    {
        return settings_.done_;
    }

    double Task::getPlanned() const
    {
        return settings_.planned_;
    }

    bool Task::overdue() const
    {
        return settings_.done_ >= settings_.planned_;
    }

}
