#include "tasklist.h"

namespace Model
{

    TaskList::TaskList()
    {

    }

    void TaskList::addTask(const Task &task)
    {
        tasks_.push_back(task);
    }

    size_t TaskList::tasksCount() const
    {
        return tasks_.size();
    }

}
