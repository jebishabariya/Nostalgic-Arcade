#include "leadersnake.h"
#include "ui_leadersnake.h"
#include "snakegame.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>
#include <vector>
#include <QString>

LeaderSnake::LeaderSnake(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LeaderSnake)
{
    ui->setupUi(this);
    initializeDatabase();
    setHighScores();
}

LeaderSnake::~LeaderSnake()
{
    delete ui;
}
void LeaderSnake::initializeDatabase()
{
     db = DatabaseConnect::instance().database();
    /*if (QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
        db = QSqlDatabase::database(QSqlDatabase::defaultConnection);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("snakehighscores.db");

        if (!db.open()) {
            qCritical() << "Failed to connect to database:" << db.lastError().text();
            return;
        }

        QSqlQuery query;
        if (!query.exec("CREATE TABLE IF NOT EXISTS highscores (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT NOT NULL, score INTEGER NOT NULL);")) {
            qCritical() << "Failed to create table:" << query.lastError().text();
        } else {
            qDebug() << "Database initialized and table created.";
        }
    }*/
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
    QSqlQuery query("SELECT name, score FROM highscores ORDER BY score DESC LIMIT 5");

    if (!query.exec()) {
        qCritical() << "Failed to fetch scores:" << query.lastError().text();
        return;
    }

    ui->listWidget->clear(); // Clear the list widget before adding new items
    while (query.next()) {
        QString name = query.value(0).toString();
        int score = query.value(1).toInt();
        qDebug() << "Retrieved score:" << name << score;
        ui->listWidget->addItem(QString("%1: %2").arg(name).arg(score));
    }
}
void LeaderSnake::onGameOver(int score)
{
    qDebug() << "Game over received with score:" << score;
    qDebug() << "Player name in onGameOver:" << playerName;

    if (playerName.isEmpty()) {
        qCritical() << "Player name is still empty in onGameOver.";
    }

    addScore(playerName, score);
    setHighScores(); // Call setHighScores to refresh the list
     ui->lineEdit->clear();
}
void LeaderSnake::on_pushButton_clicked()
{
    QString name = ui->lineEdit->text().trimmed(); // Get the player name and trim any extra spaces
    if (name.isEmpty()) {
        qDebug() << "Player name is empty.";
        return; // Do not start the game if the player name is empty
    }
    playerName = name; // Set the player name
    qDebug() << "Player name set to:" << playerName;

    this->hide(); // Hide the LeaderSnake dialog
    SnakeGame *snakeGame = new SnakeGame();
    connect(snakeGame, &SnakeGame::gameOver, this, &LeaderSnake::onGameOver);
    snakeGame->show();
}


void LeaderSnake::on_pushButton_2_clicked()
{
    playerName = ui->lineEdit->text();
    if (playerName.isEmpty()) {
        qDebug() << "Player name is empty.";
        return; // Do not proceed if the player name is empty
    }
   // QString name = playerName;
    qDebug() << "Player name set to:" << playerName;
}




