#include "task.h"

Task::Task()
{

}

std::string Task::getName() const
{
    return name_;
}

void Task::setName(const std::string& i_name)
{
    name_ = i_name;
}

std::string Task::getDescription() const
{
    return description_;
}

void Task::setDescription(const std::string& i_description)
{
    description_ = i_description;
}

int Task::getOriginalEstimate() const
{
    return originalEstimate_;
}

void Task::setOriginalEstimate(int originalEstimate)
{
    originalEstimate_ = originalEstimate;
}

int Task::getCurrentEstimate() const
{
    return currentEstimate_;
}

void Task::setCurrentEstimate(int currentEstimate)
{
    currentEstimate_ = currentEstimate;
}
