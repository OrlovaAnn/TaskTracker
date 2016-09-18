#pragma once

namespace Model
{

    enum class TaskStateType
    {
        Open,
        InProgress,
        Closed
    };

    /// Progress of the task
    class TaskState
    {
    public:
        double planned_;        /// initial time estimate
        double done_;           /// amount of time already spent
        TaskStateType type_;    /// progress state
    };

}
