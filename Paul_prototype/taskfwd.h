#pragma once

#include <memory>

namespace Model
{
    struct TaskSettings;
    class TaskList;
    class Task;
    using TaskId = int;
    using TaskPtr = std::unique_ptr<Task>;
}
