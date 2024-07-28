#include "choice.h"
#include "ui_choice.h"
#include <QMediaPlayer>
#include <QAudioOutput>

choice::choice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choice)
{
    ui->setupUi(this);

    bgMusic = new QMediaPlayer(this);
    Vol = new QAudioOutput(this);
    bgMusic->setAudioOutput(Vol);
    Vol->setVolume(0.6);
    bgMusic->setSource(QUrl("qrc:/new/res/bgmusic.mp3"));
    //bgMusic->setVolume(50);
    bgMusic->setLoops(QMediaPlayer::Infinite);
    bgMusic->play();
}

choice::~choice()
{
    delete ui;
}

void choice::on_pushButton_clicked()//snake
{
    this->hide();
    // Path to your game executable or script
       // QString gameFilePath = "D:\labProject\Nostalgic-Arcade\Home\snakemain.exe"; // Replace with actual path

        // Create a process to run the game file
       // QProcess *process = new QProcess(this);
       // process->start();

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

void choice::hideEvent(QHideEvent *event)
{
    QDialog::hideEvent(event);
    if (bgMusic) {
        bgMusic->stop(); // Stop playback when the window is hidden
    }
}

void choice::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
    if (bgMusic) {
        bgMusic->stop(); // Stop playback when the window is closed
    }
}


