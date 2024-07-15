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
    // Path to your game executable or script
        QString gameFilePath = "D:\labProject\Nostalgic-Arcade\Home\snakemain.exe"; // Replace with actual path

        // Create a process to run the game file
        QProcess *process = new QProcess(this);
        process->start(gameFilePath);

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

