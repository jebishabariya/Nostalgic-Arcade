#include "gameboard.h"

GameBoard::GameBoard(QWidget *parent)
    : QWidget(parent),
    snakeLength(3),
    currentDirection(None),
    gameOver(false)
{
    setFixedSize(BoardWidth * SquareSize, BoardHeight * SquareSize);
    setFocusPolicy(Qt::StrongFocus);

    for (int i = 0; i < snakeLength; ++i)
        snake[i] = QPoint(BoardWidth / 2 + i, BoardHeight / 2);

    QRandomGenerator rand;
    food = QPoint(rand.bounded(BoardWidth), rand.bounded(BoardHeight));
}

GameBoard::~GameBoard()
{
}

void GameBoard::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        if (currentDirection != Down)
            currentDirection = Up;
        break;
    case Qt::Key_Down:
        if (currentDirection != Up)
            currentDirection = Down;
        break;
    case Qt::Key_Left:
        if (currentDirection != Right)
            currentDirection = Left;
        break;
    case Qt::Key_Right:
        if (currentDirection != Left)
            currentDirection = Right;
        break;
    default:
        QWidget::keyPressEvent(event);
    }
}

void GameBoard::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    if (gameOver)
    {
        painter.drawText(rect(), Qt::AlignCenter, "Game Over!");
        return;
    }

    // Draw snake
    painter.setBrush(Qt::green);
    for (int i = 0; i < snakeLength; ++i)
        painter.drawRect(snake[i].x() * SquareSize, snake[i].y() * SquareSize, SquareSize, SquareSize);

    // Draw food
    painter.setBrush(Qt::red);
    painter.drawRect(food.x() * SquareSize, food.y() * SquareSize, SquareSize, SquareSize);
}

void GameBoard::updateGame()
{
    if (gameOver)
        return;

    // Move the snake
    for (int i = snakeLength - 1; i > 0; --i)
        snake[i] = snake[i - 1];

    switch (currentDirection)
    {
    case Up:
        snake[0].ry() -= 1;
        break;
    case Down:
        snake[0].ry() += 1;
        break;
    case Left:
        snake[0].rx() -= 1;
        break;
    case Right:
        snake[0].rx() += 1;
        break;
    default:
        break;
    }

    // Check collision with walls
    if (snake[0].rx() < 0 || snake[0].rx() >= BoardWidth || snake[0].ry() < 0 || snake[0].ry() >= BoardHeight)
        gameOver = true;

    // Check collision with itself
    for (int i = 1; i < snakeLength; ++i)
    {
        if (snake[0] == snake[i])
        {
            gameOver = true;
            break;
        }
    }

    // Check if food is eaten
    if (snake[0] == food)
    {
        snakeLength++;
        QRandomGenerator rand;
        food = QPoint(rand.bounded(BoardWidth), rand.bounded(BoardHeight));
    }

    // Update display
    update();

    // Adjust game speed
    int timerInterval = 100 - (snakeLength > 10 ? 10 * (snakeLength - 10) : 0);
    static_cast<QTimer *>(sender())->setInterval(timerInterval);
}
