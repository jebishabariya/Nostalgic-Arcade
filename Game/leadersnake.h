#ifndef LEADERSNAKE_H
#define LEADERSNAKE_H

#include"snakegame.h"
#include <QDialog>
#include <QListWidget>
#include <QSqlDatabase>
#include "databaseconnect.h"
namespace Ui {
class LeaderSnake;
}

class LeaderSnake : public QDialog
{
    Q_OBJECT

public:
    explicit LeaderSnake(QWidget *parent = nullptr);
    ~LeaderSnake();
    void displayLeaderboard();
    void loadLeaderboard();
public slots:
    void onGameOver(int score); // Slot to handle the game over signal
    void setHighScores();

private slots:
    void addScore(const QString &name, int score);

    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    void initializeDatabase();
    Ui::LeaderSnake *ui;
     QSqlDatabase db;
    QString playerName;

};

#endif // LEADERSNAKE_H
