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

    TaskId TaskManager::createTask(const TaskSettings& settings)
    {
        const auto taskId = nextId_;
        tasks_.addTask(taskId, settings);
        ++nextId_;
        return taskId;
    }

}
