#include "tasklist.h"

namespace Model
{

    void TaskList::addTask(TaskId id, const TaskSettings& settings)
    {
        tasks_.emplace(id, std::make_unique<Task>(settings));
    }

    size_t TaskList::tasksCount() const
    {
        return tasks_.size();
    }

    Task* TaskList::findTask(TaskId id) const
    {
        auto& it = tasks_.find(id);
        return (it != tasks_.end()) ? it->second.get() : nullptr;
    }

}
