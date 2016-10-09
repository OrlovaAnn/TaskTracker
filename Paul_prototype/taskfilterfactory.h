#pragma once

#include "taskfwd.h"

namespace Model
{

    /// Singleton class for creation of the task filters
    class TaskFilterFactory
    {
    public:
        TaskFilterFactory& operator=(const TaskFilterFactory&) = delete;
        TaskFilterFactory(const TaskFilterFactory&) = delete;
        TaskFilterFactory(const TaskFilterFactory&&) = delete;

        static TaskFilterFactory& get();

        template<typename Source>
        TaskFilter getFilter(Source src) const
        {
            return TaskFilter(src);
        }

    private:
        TaskFilterFactory() = default;
        ~TaskFilterFactory() = default;
    };

}
