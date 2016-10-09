#pragma once

#include <memory>

namespace Model
{
    struct TaskSettings;
    class TaskList;
    class Task;
    class TaskFilterFactory;
    class TaskFilter;
    using TaskId = int;
    using TaskPtr = std::unique_ptr<Task>;
}
