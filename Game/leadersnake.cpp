#include "leadersnake.h"
#include "ui_leadersnake.h"
#include "snakegame.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>


LeaderSnake::LeaderSnake(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LeaderSnake)
{
    ui->setupUi(this);
     setHighScores();
}

LeaderSnake::~LeaderSnake()
{
    delete ui;
}
void LeaderSnake::addScore(const QString &name, int score)
{
    // Insert the new score into the database
    QSqlQuery query;
    query.prepare("INSERT INTO highscores (name, score) VALUES (:name, :score)");
    query.bindValue(":name", name);
    query.bindValue(":score", score);

    if (!query.exec()) {
        qCritical() << "Failed to insert score:" << query.lastError().text();
    } else {
    qDebug() << "Score added to database.";
    }

    // Reload high scores
    setHighScores();
}
void LeaderSnake::setHighScores()
{
    // Load high scores from the database
    QSqlQuery query("SELECT name, score FROM highscores ORDER BY score DESC LIMIT 5");

    if (!query.exec()) {
        qCritical() << "Failed to fetch scores:" << query.lastError().text();
        return;
    }

    ui->listWidget->clear();
    while (query.next()) {
        QString name = query.value(0).toString();
        int score = query.value(1).toInt();
        qDebug() << "Retrieved score:" << name << score;
        ui->listWidget->addItem(QString("%1: %2").arg(name).arg(score));
    }
}
void LeaderSnake::onGameOver(int score)
{
    // Use the stored playerName to add the score to the database

        addScore(playerName, score);

    ui->lineEdit->clear();
}
void LeaderSnake::on_pushButton_clicked()
{
    this->hide();
    SnakeGame *snakeGame = new SnakeGame();
    // Connect the gameOver signal to the onGameOver slot
    connect(snakeGame, &SnakeGame::gameOver, this, &LeaderSnake::onGameOver);
    snakeGame->show();
}


void LeaderSnake::on_pushButton_2_clicked()
{
    playerName = ui->lineEdit->text();
   // addScore(playerName,score)
}

