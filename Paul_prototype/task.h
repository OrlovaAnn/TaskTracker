#pragma once

#include <string>

class Task
{
public:
    Task();

    std::string getName() const;
    void setName(const std::string& i_name);

    std::string getDescription() const;
    void setDescription(const std::string& i_description);

    int getOriginalEstimate() const;
    void setOriginalEstimate(int originalEstimate);

    int getCurrentEstimate() const;
    void setCurrentEstimate(int currentEstimate);

private:
    std::string name_ = "";
    std::string description_ = "";
    int originalEstimate_ = 0;
    int currentEstimate_ = 0;

};
