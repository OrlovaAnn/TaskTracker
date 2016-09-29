#include "task.h"

namespace Model
{
    Task::Task(TaskId id, const TaskSettings& settings) :
        id_(id),
        settings_(settings)
    {}

    TaskId Task::getId() const
    {
        return id_;
    }

    QString Task::getName() const
    {
        return getSettings().name_;
    }

    void Task::setName(const QString& name)
    {
        settings_.name_ = name;
    }

    QString Task::getDescription() const
    {
        return getSettings().description_;
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

    TaskSettings Task::getSettings() const
    {
        return settings_;
    }

    void Task::setSettings(const TaskSettings &settings)
    {
        settings_ = settings;
    }

    TaskState& Task::state()
    {
        return settings_.state();
    }

    const TaskState &Task::state() const
    {
        return getSettings().state();
    }

}
