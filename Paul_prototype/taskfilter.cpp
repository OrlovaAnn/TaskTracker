#include "taskfilter.h"

namespace Model
{

TaskFilter TaskFilter::operator!()
{
    return std::make_shared<FilterNot>(filter_);
}

TaskFilter TaskFilter::operator&&(const TaskFilter& other)
{
    return std::make_shared<FilterAnd>(filter_, other.filter_);
}

TaskFilter TaskFilter::operator||(const TaskFilter& other)
{
    return std::make_shared<FilterOr>(filter_, other.filter_);
}

}
