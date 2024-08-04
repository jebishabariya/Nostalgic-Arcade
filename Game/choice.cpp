#include "choice.h"
#include "ui_choice.h"
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QProcess>
#include "snakegame.h"
#include "leadersnake.h"
#include "mainwindowpingpong.h"

choice::choice(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::choice)
{
    ui->setupUi(this);


    bgMusic = new QMediaPlayer(this);
    Vol = new QAudioOutput(this);
    bgMusic->setAudioOutput(Vol);
    Vol->setVolume(0.6);
    bgMusic->setSource(QUrl("qrc:/res1/bgmusic.mp3"));
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
   LeaderSnake ind;
    ind.setModal(true);
    ind.exec();
    //showLeaderboard();

}


void choice::on_pushButton_2_clicked()//pong
{
    this->hide();
    MainWindowPingPong *pingpong = new MainWindowPingPong();
    pingpong->show();
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
/*void choice::showLeaderboard()
{
    LeaderSnake leaderSnake;
    if (leaderSnake.exec() == QDialog::Accepted) {
        QString playerName = leaderSnake.getPlayerName();
        // Create a QDialog pointer to handle visibility control
        QDialog *leaderSnakeDialog = new LeaderSnake(this);

        // Hide the LeaderSnake dialog
        leaderSnakeDialog->hide();
        // Start the respective game (example for SnakeGame)
        SnakeGame game;
        game.();

        // After the game ends, retrieve the player's score
        int playerScore = game.getScore();

        // Update the score in the database
        leaderSnake.addScore(playerName, playerScore);

        // Show the high scores
        leaderSnake.setHighScores();
        leaderSnake.exec();
        delete leaderSnakeDialog;

    }
}*/



