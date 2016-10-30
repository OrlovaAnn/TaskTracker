#pragma once

namespace Model
{

    /// Status of the task
    enum class TaskStatus
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
        TaskStatus status_;     /// progress status
    };

}
