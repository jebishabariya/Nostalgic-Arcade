#include "result.h"
#include "./ui_result.h"

Dialog::Dialog(const QString &message, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->textEdit->setText(message);
    connect(ui->pushButton, &QPushButton::clicked, this, &Dialog::accept);
}

Dialog::~Dialog()
{
    delete ui;
}


