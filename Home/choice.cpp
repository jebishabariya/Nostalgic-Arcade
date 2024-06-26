#include "choice.h"
#include "ui_choice.h"

choice::choice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choice)
{
    ui->setupUi(this);
}

choice::~choice()
{
    delete ui;
}

void choice::on_pushButton_clicked()//snake
{
    this->hide();
}


void choice::on_pushButton_2_clicked()//pong
{
    this->hide();
}


void choice::on_pushButton_3_clicked()//spr
{
    this->hide();
}


void choice::on_pushButton_4_clicked()//tictactoe
{
    this->hide();
}

