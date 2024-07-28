#include "mainwindowtictactoe.h"
#include "./ui_mainwindowtictactoe.h"
#include "result.h"


MainWindowTicTacToe::MainWindowTicTacToe(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTicTacToe),
    currentPlayer(1),
    player1Symbol("X"),
    player2Symbol("O")
{
    ui->setupUi(this);

    // Connect buttons to slots
    buttons.append(ui->pushButton);
    buttons.append(ui->pushButton_2);
    buttons.append(ui->pushButton_3);
    buttons.append(ui->pushButton_4);
    buttons.append(ui->pushButton_5);
    buttons.append(ui->pushButton_6);
    buttons.append(ui->pushButton_7);
    buttons.append(ui->pushButton_8);
    buttons.append(ui->pushButton_9);

    for (QPushButton *button : buttons) {
        connect(button, &QPushButton::clicked, this, &MainWindowTicTacToe::handleButtonClick);
    }

    connect(ui->pushButton_10,&QPushButton::clicked,this,&MainWindowTicTacToe::handleRegame);
}

MainWindowTicTacToe::~MainWindowTicTacToe()
{
    delete ui;
}

void MainWindowTicTacToe::handleButtonClick()
{
    QPushButton *clickedButton = qobject_cast<QPushButton*>(sender());
    if (clickedButton) {
        if (currentPlayer == 1) {
            clickedButton->setText(player1Symbol);
            currentPlayer = 2;
        } else {
            clickedButton->setText(player2Symbol);
            currentPlayer = 1;
        }
        clickedButton->setEnabled(false); // Disable button after click

        if (checkWin(player1Symbol)) {
            showResultDialog("Player 1 (X) wins!");
        } else if (checkWin(player2Symbol)) {
            showResultDialog("Player 2 (O) wins!");
        }
        else if (isDraw())
        {
            showResultDialog(("It's Draw"));
        }
    }
}

bool MainWindowTicTacToe::checkWin(const QString &symbol)
{
    // Check rows
    for (int row = 0; row < 3; ++row) {
        if (buttons[row * 3]->text() == symbol &&
            buttons[row * 3 + 1]->text() == symbol &&
            buttons[row * 3 + 2]->text() == symbol) {
            return true;
        }
    }

    // Check columns
    for (int col = 0; col < 3; ++col) {
        if (buttons[col]->text() == symbol &&
            buttons[col + 3]->text() == symbol &&
            buttons[col + 6]->text() == symbol) {
            return true;
        }
    }

    // Check main diagonal (\)
    if (buttons[0]->text() == symbol &&
        buttons[4]->text() == symbol &&
        buttons[8]->text() == symbol) {
        return true;
    }

    // Check secondary diagonal (/)
    if (buttons[2]->text() == symbol &&
        buttons[4]->text() == symbol &&
        buttons[6]->text() == symbol) {
        return true;
    }

    return false;
}
bool MainWindowTicTacToe::isDraw()
{
    for(QPushButton *button:buttons)
    {
        if(button->text().isEmpty())
        {
            return false;
        }
    }
    return true;
}

void MainWindowTicTacToe::showResultDialog(const QString &message)
{
    Dialog resultDialog(message, this);
    resultDialog.exec();
    handleRegame();
}

void MainWindowTicTacToe::handleRegame()
{
    resetGame();
}

void MainWindowTicTacToe::resetGame()
{
    for (QPushButton *button : buttons) {
        button->setText("");
        button->setEnabled(true);
    }
    currentPlayer = 1; // Reset to player 1
}
