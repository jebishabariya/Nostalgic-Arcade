#include "scissorsmainwindow.h"
#include "ui_scissorsmainwindow.h"

MainWindowScissors::MainWindowScissors(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindowScissors)
{
    ui->setupUi(this);
}

MainWindowScissors::~MainWindowScissors()
{
    delete ui;
}

void MainWindowScissors::updateChoices(const QString &playerChoice, const QString &computerChoice)
{
    // Update the labels with images
    ui->label_17->setPixmap(QPixmap(playerChoice));
    ui->label_18->setPixmap(QPixmap(computerChoice));
}

void MainWindowScissors::determineResult(const QString &playerChoice, const QString &computerChoice)
{
    if (playerChoice == computerChoice)
        ui->label_16->setText("RESULT: Draw");
    else if ((playerChoice == ":/images/rock.png" && computerChoice == ":/images/scissors.png") ||
             (playerChoice == ":/images/scissors.png" && computerChoice == ":/images/paper.png") ||
             (playerChoice == ":/images/paper.png" && computerChoice == ":/images/rock.png"))
        ui->label_16->setText("RESULT: You Win!");
    else
        ui->label_16->setText("RESULT: You Lose!");
}

void MainWindowScissors::on_pushButton_7_clicked() // Scissors
{
    QString playerChoice = ":/images/Scissors.png";
    QStringList choices = { ":/images/Rock.png", ":/images/Paper.png", ":/images/Scissors.png" };
    QString computerChoice = choices.at(QRandomGenerator::global()->bounded(choices.size()));
    updateChoices(playerChoice, computerChoice);
    determineResult(playerChoice, computerChoice);
}

void MainWindowScissors::on_pushButton_8_clicked() // Paper
{
    QString playerChoice = ":/images/Paper.png";
    QStringList choices = { ":/images/Rock.png", ":/images/Paper.png", ":/images/Scissors.png" };
    QString computerChoice = choices.at(QRandomGenerator::global()->bounded(choices.size()));
    updateChoices(playerChoice, computerChoice);
    determineResult(playerChoice, computerChoice);
}

void MainWindowScissors::on_pushButton_9_clicked() // Rock
{
    QString playerChoice = ":/images/Rock.png";
    QStringList choices = { ":/images/Rock.png", ":/images/Paper.png", ":/images/Scissors.png" };
    QString computerChoice = choices.at(QRandomGenerator::global()->bounded(choices.size()));
    updateChoices(playerChoice, computerChoice);
    determineResult(playerChoice, computerChoice);
}

void MainWindowScissors::on_pushButton_clicked() // Restart
{
    ui->label_16->setText("RESULT:");
    ui->label_17->clear();
    ui->label_18->clear();
}

