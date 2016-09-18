#include "createtaskdialog.h"

#include "ui_createtaskdialog.h"

CreateTaskDialog::CreateTaskDialog()
    : ui_(std::make_unique<Ui::CreateTaskDialog>())
{
    ui_->setupUi(this);
    ui_->horizontalSlider->setMaximum(100);
}

Model::TaskSettings CreateTaskDialog::getSettings() const
{
    return Model::TaskSettings{ui_->lineEdit->text(),
                               ui_->textEdit->toPlainText(),
                               static_cast<double>(ui_->horizontalSlider->value())/ui_->horizontalSlider->maximum()};
}
