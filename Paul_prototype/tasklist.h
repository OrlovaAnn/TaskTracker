#pragma once

#include <map>
#include "task.h"

namespace Model
{

    /// Represents a list of tasks
    class TaskList
    {
    public:
        /// Add task to the list
        /// \param  task  task to add
        void addTask(TaskId id, const Task& task);

        /// Add task to the list
        /// \param  settings settings to be used for the task
        void addTask(TaskId id, const TaskSettings& settings);

        /// Get tasks count in the list
        /// \return  tasks count
        size_t tasksCount() const;

        /// Find task by id in the list
        /// \param  id  task id to search
        /// \return task with the desired id or nullptr if not found
        Task* findTask(TaskId id) const;

    private:

        std::map<TaskId, TaskPtr> tasks_; /// tasks in the list
    };

}
