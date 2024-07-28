#include "mode2.h"
#include "ui_mode2.h"

mode2::mode2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mode2)
{
    ui->setupUi(this);
}

mode2::~mode2()
{
    delete ui;
}

void mode2::on_pushButton_clicked()
{
    this->hide();
    choice ind;
    ind.setModal(true);
    ind.exec();
}

