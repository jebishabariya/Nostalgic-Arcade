#ifndef LEADERSNAKE_H
#define LEADERSNAKE_H
#include"snakegame.h"
#include <QDialog>
#include <QListWidget>
class SnakeGame;
namespace Ui {
class LeaderSnake;
}

class LeaderSnake : public QDialog
{
    Q_OBJECT

public:
    explicit LeaderSnake(QWidget *parent = nullptr);
    ~LeaderSnake();
public slots:
    void onGameOver(int score); // Slot to handle the game over signal


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    void addScore(const QString &name, int score);
    void setHighScores();
    Ui::LeaderSnake *ui;
    QString playerName;
};

#endif // LEADERSNAKE_H
