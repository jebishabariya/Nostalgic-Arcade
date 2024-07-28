#include "mainwindowpingpong.h"
#include "ui_mainwindowpingpong.h"

MainWindowPingPong::MainWindowPingPong(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowPingPong)
{
    ui->setupUi(this);
    ballDirection = {1, 1}; // Initial ball direction

    QTimer *timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindowPingPong::updateGame);
    timer->start(16); // Approximately 60 FPS

    resultDialog = new QDialog(this);
    resultUi.setupUi(resultDialog);
    connect(resultUi.pushButton, &QPushButton::clicked, this, [=]() {
        resultDialog->hide();
        resetBall();
    });
}

MainWindowPingPong::~MainWindowPingPong()
{
    delete ui;
}

void MainWindowPingPong::keyPressEvent(QKeyEvent *event)
{
    // Optional: If you want to keep keyboard controls
    if(event->key() == Qt::Key_W && ui->label->y() > 0) {
        ui->label->move(ui->label->x(), ui->label->y() - 10);
    }
    if(event->key() == Qt::Key_S && ui->label->y() < height() - ui->label->height()) {
        ui->label->move(ui->label->x(), ui->label->y() + 10);
    }
}

void MainWindowPingPong::mousePressEvent(QMouseEvent *event)
{
    // Move the paddle towards the cursor
    if (event->pos().x() < width() / 2) { // Only move the human paddle
        int paddleY = event->pos().y() - ui->label->height() / 2;
        paddleY = qBound(0, paddleY, height() - ui->label->height()); // Keep paddle within bounds
        ui->label->move(ui->label->x(), paddleY);
    }
}

void MainWindowPingPong::updateGame()
{
    // Ball movement
    ui->label_3->move(ui->label_3->x() + ballDirection.x(), ui->label_3->y() + ballDirection.y());

    // Ball collision with top and bottom walls
    if (ui->label_3->y() <= 0 || ui->label_3->y() + ui->label_3->height() >= height()) {
        ballDirection.setY(-ballDirection.y());
    }

    // Ball collision with paddles
    if (ui->label_3->geometry().intersects(ui->label->geometry()) || ui->label_3->geometry().intersects(ui->label_2->geometry())) {
        ballDirection.setX(-ballDirection.x());
    }

    // Ball out of bounds (left or right)
    if (ui->label_3->x() <= 0) {
        showResultDialog("Computer Wins! Sorry, you lose.");
    } else if (ui->label_3->x() + ui->label_3->width() >= width()) {
        showResultDialog("Human Wins! Congratulations.");
    }

    // Simple AI for the computer paddle
    if (ui->label_3->y() < ui->label_2->y() && ui->label_2->y() > 0) {
        ui->label_2->move(ui->label_2->x(), ui->label_2->y() - 2);
    } else if (ui->label_3->y() > ui->label_2->y() && ui->label_2->y() < height() - ui->label_2->height()) {
        ui->label_2->move(ui->label_2->x(), ui->label_2->y() + 2);
    }
}

void MainWindowPingPong::resetBall()
{
    ui->label_3->move(width() / 2, height() / 2);
    ballDirection = {QRandomGenerator::global()->bounded(2) == 0 ? -1 : 1, QRandomGenerator::global()->bounded(2) == 0 ? -1 : 1};
}

void MainWindowPingPong::showResultDialog(const QString &result)
{
    resultUi.textEdit->setPlainText(result);
    resultDialog->exec();
}
