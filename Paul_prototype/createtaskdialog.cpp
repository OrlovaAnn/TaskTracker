#include "createtaskdialog.h"

#include "ui_createtaskdialog.h"

static const std::map<int, Model::TaskStatus> s_groupBoxItems =
{
    {0, Model::TaskStatus::Open},
    {1, Model::TaskStatus::InProgress},
    {2, Model::TaskStatus::Closed}
};

int getIndex(const Model::TaskStatus& state)
{
    for(auto it : s_groupBoxItems)
    {
        if(it.second == state)
            return it.first;
    }
    return -1;
}

CreateTaskDialog::CreateTaskDialog()
    : ui_(std::make_unique<Ui::CreateTaskDialog>())
{
    ui_->setupUi(this);
}

CreateTaskDialog::CreateTaskDialog(const Model::TaskSettings& settings)
    : ui_(std::make_unique<Ui::CreateTaskDialog>())
{
    ui_->setupUi(this);
    ui_->planned->setText(QString::number(settings.state_.planned_));
    ui_->done->setText(QString::number(settings.state_.done_));
    ui_->lineEdit->setText(settings.name_);
    ui_->textEdit->setText(settings.description_);
    ui_->statusComboBox->setCurrentIndex(getIndex(settings.state().status_));
}

Model::TaskSettings CreateTaskDialog::getSettings() const
{
    Model::TaskSettings settings{ui_->lineEdit->text(),
                ui_->textEdit->toPlainText(),
                ui_->planned->text().toDouble(),
                ui_->done->text().toDouble()};
    const int currentIndex = ui_->statusComboBox->currentIndex();
    settings.state().status_ = s_groupBoxItems.at(currentIndex);
    return settings;
}
