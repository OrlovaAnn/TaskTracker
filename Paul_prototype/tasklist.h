#pragma once

#include <vector>
#include "task.h"

namespace Model
{

    class TaskList
    {
    public:
        TaskList();

        void addTask(const Task& task);

        size_t tasksCount() const;

    private:
        std::vector<Task> tasks_;
    };

}
