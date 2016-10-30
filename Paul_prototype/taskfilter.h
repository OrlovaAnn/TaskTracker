#pragma once

#include "task.h"
#include <memory>

namespace Model
{

    /// Abstract base class for any kind of filter
    class FilterBase
    {
    public:
        /// Method to check and filter task
        /// \param   task to check
        /// \return  true if the task satisfies condition,
        ///          false otherwise
        virtual bool operator()(const Task&) const = 0;
    };

    using FilterPtr = std::shared_ptr<FilterBase>;

    /// Trivial filter which filters out all tasks
    class FilterNo : public FilterBase
    {
    public:
        virtual bool operator()(const Task&) const
        {
            return false;
        }
    };

    /// Trivial filter which doesn't filter any task
    class FilterYes : public FilterBase
    {
    public:
        virtual bool operator()(const Task&) const
        {
            return true;
        }
    };

    /// Abstract base class for the composition of two filters
    class FilterComposite : public FilterBase
    {
    public:
        FilterComposite(FilterPtr left, FilterPtr right) :
            left_(left),
            right_(right)
        {}

    protected:
        FilterPtr left_;  // lhs of the composition
        FilterPtr right_; // rhs of the composition
    };

    /// Filter which inverts the source filter (logical NOT)
    class FilterNot : public FilterBase
    {
    public:
        FilterNot(FilterPtr src) : src_(src)
        {}

        virtual bool operator()(const Task& task) const
        {
            return !(*src_)(task);
        }

    private:
        FilterPtr src_;  // source filter

    };

    /// Composite filter which represents logical AND of the two filters
    class FilterAnd : public FilterComposite
    {
    public:

        FilterAnd(FilterPtr left, FilterPtr right) :
            FilterComposite(left, right)
        {}

        virtual bool operator()(const Task& task) const
        {
            return (*left_)(task) && (*right_)(task);
        }
    };

    /// Composite filter which represents logical OR of the two filters
    class FilterOr : public FilterComposite
    {
    public:

        FilterOr(FilterPtr left, FilterPtr right) :
            FilterComposite(left, right)
        {}

        virtual bool operator()(const Task& task) const
        {
            return (*left_)(task) || (*right_)(task);
        }
    };

    /// Filter which checks state of the task
    class FilterType : public FilterBase
    {
    public:
        FilterType(TaskStatus type) : type_(type)
        {}

        virtual bool operator()(const Task& task) const
        {
            return task.getSettings().state().status_ == type_;
        }
    private:
        TaskStatus type_; // state to compare with
    };

    /// Filter which checks if the task's name contains substring
    class FilterName : public FilterBase
    {
    public:
        FilterName(const QString& substring) : substring_(substring)
        {}

        virtual bool operator()(const Task& task) const
        {
            return task.getName().contains(substring_, Qt::CaseInsensitive);
        }
    private:
        const QString substring_; // substring to search
    };

    /// Reresents task filter for the user
    class TaskFilter
    {
    public:
        explicit TaskFilter(bool x)
        {
            if(x)
            {
                filter_ = std::make_shared<FilterYes>();
            }
            else
            {
                filter_ = std::make_shared<FilterNo>();
            }
        }

        explicit TaskFilter(TaskStatus type) : filter_(std::make_shared<FilterType>(type))
        {}

        explicit TaskFilter(const QString& str) : filter_(std::make_shared<FilterName>(str))
        {}

        explicit TaskFilter(const char* str) : filter_(std::make_shared<FilterName>(QString(str)))
        {}

        explicit TaskFilter(const std::string& str) : filter_(std::make_shared<FilterName>(QString(str.c_str())))
        {}

        TaskFilter(FilterPtr filter) : filter_(filter)
        {}

        TaskFilter(const TaskFilter& src) : filter_(src.filter_)
        {}

        TaskFilter(const TaskFilter&& src) : filter_(src.filter_)
        {}

        TaskFilter& operator=(const TaskFilter& src)
        {
            filter_= src.filter_;
            return *this;
        }

        bool operator()(const Task& task) const
        {
            return filter_ ? (*filter_)(task) : true;
        }

        TaskFilter operator||(const TaskFilter& right);
        TaskFilter operator&&(const TaskFilter& right);
        TaskFilter operator!();
    public:
        FilterPtr filter_; // internal filter to use
    };
}
