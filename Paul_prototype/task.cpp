#include "task.h"

namespace Model
{

    Task::Task(const QString& name,
               const QString& description,
               double planned,
               double done /*=0.0*/) :
        name_(name),
        description_(description),
        planned_(planned),
        done_(done)
    {}

    QString Task::getName() const
    {
        return name_;
    }

    void Task::setName(const QString& name)
    {
        name_ = name;
    }

    QString Task::getDescription() const
    {
        return description_;
    }

    void Task::setDescription(const QString& description)
    {
        description_ = description;
    }

    void Task::logWork(double amountDone)
    {
        done_ += amountDone;
    }

    double Task::getPercentageDone() const
    {
        if(planned_ <= std::numeric_limits<double>::epsilon())
        {
            return 0.0;
        }
        return done_/planned_ * 100.0;
    }

}
