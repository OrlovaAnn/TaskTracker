#include "createtaskdialog.h"

#include "ui_createtaskdialog.h"

CreateTaskDialog::CreateTaskDialog()
    : ui_(new Ui::CreateTaskDialog)
{
    ui_->setupUi(this);
    ui_->horizontalSlider->setMaximum(100);
}

QString CreateTaskDialog::getText() const
{
    return ui_->lineEdit->text();
}

Model::Task CreateTaskDialog::createTask() const
{
    const auto& name = ui_->lineEdit->text();
    const auto& description = ui_->textEdit->toPlainText();
    const double& planned = static_cast<float>(ui_->horizontalSlider->value())/ui_->horizontalSlider->maximum();
    return Model::Task(name, description, planned);
}
