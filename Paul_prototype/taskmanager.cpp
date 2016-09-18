#include "taskmanager.h"

namespace Model
{

    TaskManager& TaskManager::get()
    {
        static TaskManager mgr;
        return mgr;
    }

    Task* TaskManager::findTask(TaskId id) const
    {
        return tasks_.findTask(id);
    }

    template<typename Source>
    TaskId TaskManager::createTask(const Source& source)
    {
        const auto taskId = nextId_;
        tasks_.addTask(taskId, source);
        ++nextId_;
        return taskId;
    }

    template TaskId TaskManager::createTask(const TaskSettings&);
    template TaskId TaskManager::createTask(const Task&);

}
