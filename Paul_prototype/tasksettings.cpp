#include "tasksettings.h"

namespace Model
{

    TaskSettings::TaskSettings(QString name, QString description, double planned, double done) :
        name_(name),
        description_(description),
        state_{planned, done, TaskStateType::Open}
    {

    }

    TaskState& TaskSettings::state()
    {
        return state_;
    }

    const TaskState& TaskSettings::state() const
    {
        return state_;
    }

}
