#pragma once

#include <QString>

namespace Model
{

    class Task
    {
    public:
        Task(const QString& name, const QString& description, double planned, double done = 0.0);

        QString getName() const;
        void setName(const QString& name);

        QString getDescription() const;
        void setDescription(const QString& description);

        void logWork(double amountDone);

        double getPercentageDone() const;

        double getDone() const;

        double getPlanned() const;

        bool overdue() const;
    private:
        QString name_ = "New task";
        QString description_ = "";
        double planned_;
        double done_ = 0.0;
    };

}
