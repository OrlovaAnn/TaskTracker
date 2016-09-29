#pragma once

#include "tasklist.h"

namespace Model
{

    /// Class to manage tasks
    class TaskManager
    {
    public:
        TaskManager& operator=(const TaskManager&) = delete;
        TaskManager(const TaskManager&) = delete;
        TaskManager(const TaskManager&&) = delete;

        /// Get the instance of the manager
        static TaskManager& get();

        /// Create task from the settings
        /// \param  settings  params to use for creation
        /// \return  id of the newly created task
        TaskId createTask(const TaskSettings& settings);

        /// Find task by id
        /// \param  id  task id to search
        /// \return task with the desired id or nullptr if not found
        Task* findTask(TaskId id) const;

    private:
        TaskManager() = default;
        ~TaskManager() = default;

        TaskList tasks_; /// already created task
        TaskId nextId_;  /// id to be used for the next task creation
    };

}
