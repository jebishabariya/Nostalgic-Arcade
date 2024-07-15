#include "mainwindow.h"
#include "snake.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QKeyEvent>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(600, 400);

    connect(&timer, SIGNAL(timeout()), this, SLOT(updateGame()));
    timer.start(100); // Update game every 100 ms

    gameOver = false;
    snake.init();
    food.generate();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    // Get the current direction of the snake
    Direction currentDirection = snake.getcurrentDirection();

    switch (event->key()) {
    case Qt::Key_Up:
        if (currentDirection != Direction::Down) {

            snake.setDirection(Direction::Up);
        }
        break;
    case Qt::Key_Down:
        if (currentDirection != Direction::Up) {
            snake.setDirection(Direction::Down);
        }
        break;
    case Qt::Key_Left:
        if (currentDirection != Direction::Right) {
            snake.setDirection(Direction::Left);
        }
        break;
    case Qt::Key_Right:
        if (currentDirection != Direction::Left) {
            snake.setDirection(Direction::Right);
        }
        break;
    default:
        QMainWindow::keyPressEvent(event);
    }
}


void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);

    if (gameOver) {
        // Display game over message and score
        painter.drawText(rect(), Qt::AlignCenter, "Game Over!");
       // painter.drawText(rect(), Qt::AlignBaseline, SCORE);
        return;
    }

    // Draw Snake
    painter.setBrush(Qt::blue);
    for (auto& segment : snake.getBody()) {
        painter.drawRect(segment.x() * 10, segment.y() * 10, 10, 10);
    }

    // Draw Food
    painter.setBrush(Qt::red);
    painter.drawRect(food.getPosition().x() * 10, food.getPosition().y() * 10, 10, 10);
}

void MainWindow::updateGame()
{
    if (!gameOver) {
        snake.move();
        if (snake.checkCollision() || snake.checkSelfCollision()) {
            gameOver = true;
        }
        if (snake.head() == food.getPosition()) {
           // SCORE+=1;
            snake.grow();
            food.generate();
        }
    }

    update(); // Trigger paintEvent
}
