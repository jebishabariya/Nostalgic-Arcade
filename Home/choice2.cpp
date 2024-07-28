#include "choice2.h"
#include "ui_choice2.h"

choice2::choice2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choice2)
{
    ui->setupUi(this);
}

choice2::~choice2()
{
    delete ui;
}

void choice2::on_pushButton_clicked()
{
    this->hide();
    choice ind;
    ind.setModal(true);
    ind.exec();
}
