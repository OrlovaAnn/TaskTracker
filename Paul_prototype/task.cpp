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
        state().done_ += amountDone;
    }

    double Task::getPercentageDone() const
    {
        if(getPlanned() <= std::numeric_limits<double>::epsilon())
        {
            return 0.0;
        }
        return getDone()/getPlanned() * 100.0;
    }

    double Task::getDone() const
    {
        return state().done_;
    }

    double Task::getPlanned() const
    {
        return state().planned_;
    }

    bool Task::overdue() const
    {
        return getDone() >= getPlanned();
    }

    TaskState& Task::state()
    {
        return settings_.state();
    }

    const TaskState &Task::state() const
    {
        return settings_.state();
    }

}
