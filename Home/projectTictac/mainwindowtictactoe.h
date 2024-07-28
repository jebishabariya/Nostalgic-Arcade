#ifndef MAINWINDOWTICTACTOE_H
#define MAINWINDOWTICTACTOE_H

#include <QMainWindow>
#include <QPushButton>
#include <QVector>
#include "ui_mainwindowtictactoe.h"
namespace Ui {
class MainWindowTicTacToe;
}

class MainWindowTicTacToe : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTicTacToe(QWidget *parent = nullptr);
    ~MainWindowTicTacToe();

private slots:
    void handleButtonClick();

private:
    Ui::MainWindowTicTacToe *ui;
    QVector<QPushButton*> buttons;
    int currentPlayer;
    QString player1Symbol;
    QString player2Symbol;

    bool checkWin(const QString &symbol);
    void showResultDialog(const QString &message);
    void handleRegame();
    void resetGame();
    bool isDraw();
};

#endif // MAINWINDOWTICTACTOE_H



