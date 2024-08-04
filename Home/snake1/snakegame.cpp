#include "snakegame.h"
#include <QPainter>
#include <QRandomGenerator>
#include <QCoreApplication>
#include <QFontMetrics>
#include <QPainterPath>
#include <cmath>

SnakeGame::SnakeGame(QWidget *parent) : QMainWindow(parent) {
    setStyleSheet("background-color:green;"); // Set background color to black
    setFixedSize(B_WIDTH, B_HEIGHT); // Set fixed size of the window
    initGame(); // Initialize the game
}

SnakeGame::~SnakeGame() {}

void SnakeGame::initGame() {
    dots = 3;
    score = 0;

    for (int z = 0; z < dots; z++) {
        x[z] = 50 - z * DOT_SIZE;
        y[z] = 50;
    }

    locateApple();
    initObstacles();

    leftDirection = false;
    rightDirection = true;
    upDirection = false;
    downDirection = false;
    inGame = true;

    timerId = startTimer(DELAY);
}

void SnakeGame::initObstacles() {
    obstacles.clear();
    while (obstacles.size() < 20) { // Generate 20 non-overlapping obstacles
        int obsx = QRandomGenerator::global()->bounded(5, 100) * DOT_SIZE;
        int obsy = QRandomGenerator::global()->bounded(5, 65) * DOT_SIZE;
        QRect newObstacle(obsx, obsy, DOT_SIZE, DOT_SIZE);

        // Check for overlaps with existing obstacles and the snake
        bool overlaps = false;
        for (const QRect &obstacle : obstacles) {
            if (newObstacle.intersects(obstacle)) {
                overlaps = true;
                break;
            }
        }
        for (int i = 0; i < dots; ++i) {
            QRect snakePart(x[i], y[i], DOT_SIZE, DOT_SIZE);
            if (newObstacle.intersects(snakePart)) {
                overlaps = true;
                break;
            }
        }

        if (!overlaps) {
            obstacles.push_back(newObstacle);
        }
    }
}



void SnakeGame::paintEvent(QPaintEvent *event) {
    Q_UNUSED(event);
    doDrawing();
}


void SnakeGame::doDrawing() {
    QPainter qp(this);
    qp.setRenderHint(QPainter::Antialiasing);

    if (inGame) {
        // Drawing the food
        qp.setBrush(Qt::red);
        qp.drawEllipse(apple_x, apple_y, DOT_SIZE + 1, DOT_SIZE + 1);

        // Drawing the obstacles
        qp.setBrush(Qt::blue);
        for (const QRect &obstaclePos : obstacles) {
            qp.drawRect(obstaclePos);
        }

        // Draw the snake with a wavy pattern
        qp.setPen(QPen(Qt::gray, DOT_SIZE)); // Set pen color and width

        QPainterPath path;
        path.setFillRule(Qt::WindingFill);

        // Draw the head with a rounded curve
        path.moveTo(x[0] + DOT_SIZE / 2, y[0]); // Move to head position
        path.addEllipse(x[0], y[0], DOT_SIZE - 7, DOT_SIZE - 7); // Draw the head

        // Amplitude and frequency for the wavy effect
        const double amplitude = 5.0;
        const double frequency = 0.2;

        for (int i = 1; i < dots; ++i) {
            QPoint p1 = QPoint(x[i - 1], y[i - 1]);
            QPoint p2 = QPoint(x[i], y[i]);

            // Calculate the control point for a smoother curve with sinusoidal offset
            double offset = amplitude * std::sin(frequency * i);
            QPoint controlPoint = QPoint((p1.x() + p2.x()) / 2, (p1.y() + p2.y()) / 2 + offset);

            if (i == 1) {
                // For the second segment, draw a line to the curve
                path.lineTo(p2);
            } else {
                // Draw a quadratic Bezier curve for the snake body with wavy effect
                path.quadTo(controlPoint, p2);
            }
        }

        // Draw the tail with a rounded curve
        QPoint tailEnd = QPoint(x[dots - 1], y[dots - 1]);
        QPoint tailControl = QPoint((x[dots - 2] + tailEnd.x()) / 2, (y[dots - 2] + tailEnd.y()) / 2);
        path.quadTo(tailControl, tailEnd);

        qp.drawPath(path);

        // Draw the border
        qp.setPen(QPen(Qt::green, 2)); // Set pen color and width for the border

        // Top border
        qp.drawLine(25, 25, B_WIDTH - 25, 25);

        // Draw the score
        QString scoreText = QString("Score: %1").arg(score);
        qp.setPen(Qt::white);
        qp.setFont(QFont("Courier", 15, QFont::DemiBold));
        qp.drawText(10, 20, scoreText);

    } else {
        // Game Over screen
        QString message = "Game Over";
        QFont font("Courier", 15, QFont::DemiBold);
        QFontMetrics fm(font);
        int textWidth = fm.horizontalAdvance(message);

        qp.setPen(Qt::white);
        qp.setFont(font);
        int h = height();
        int w = width();

        qp.translate(QPoint(w / 2, h / 2));
        qp.drawText(-textWidth / 2, 0, message);

        QString scoreText = QString("Final Score: %1").arg(score);
        int scoreTextWidth = fm.horizontalAdvance(scoreText);
        qp.drawText(-scoreTextWidth / 2, 20, scoreText);
    }
}


void SnakeGame::timerEvent(QTimerEvent *event) {
    Q_UNUSED(event);

    if (inGame) {
        checkCollision();
        move();
        repaint(); // Ensure the screen updates
    }
}

void SnakeGame::keyPressEvent(QKeyEvent *event) {
    int key = event->key();

    if ((key == Qt::Key_Left) && (!rightDirection)) {
        leftDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Right) && (!leftDirection)) {
        rightDirection = true;
        upDirection = false;
        downDirection = false;
    }

    if ((key == Qt::Key_Up) && (!downDirection)) {
        upDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    if ((key == Qt::Key_Down) && (!upDirection)) {
        downDirection = true;
        rightDirection = false;
        leftDirection = false;
    }

    QWidget::keyPressEvent(event);
}

void SnakeGame::move() {
    for (int z = dots; z > 0; z--) {
        x[z] = x[z - 1];
        y[z] = y[z - 1];
    }

    if (leftDirection) {
        x[0] -= DOT_SIZE;
    }

    if (rightDirection) {
        x[0] += DOT_SIZE;
    }

    if (upDirection) {
        y[0] -= DOT_SIZE;
    }

    if (downDirection) {
        y[0] += DOT_SIZE;
    }
}

void SnakeGame::checkCollision() {
    int borderOffset = 25; // The border offset

    // Check for collision with self
    for (int z = dots - 1; z > 0; z--) {
        if ((x[0] == x[z]) && (y[0] == y[z])) {
            inGame = false;
        }
    }

    // Check for collision with obstacles
    QRect snakeHeadRect(x[0], y[0], DOT_SIZE, DOT_SIZE);
    for (const QRect &obstacleRect : obstacles) {
        if (snakeHeadRect.intersects(obstacleRect)) {
            inGame = false; // End game on collision
        }
    }

    // Check for collision with boundaries
    if (y[0] >= (B_HEIGHT - 1) || y[0] < 25 ||
        x[0] >= (B_WIDTH - 1) || x[0] < 0) {
        inGame = false;
    }

    // Check for collision with food
    if ((x[0] == apple_x) && (y[0] == apple_y)) {
        dots++;
        score += 1;
        locateApple();
    }

    if (!inGame) {
        killTimer(timerId);
    }
}


void SnakeGame::locateApple() {
    int r = (QRandomGenerator::global()->bounded(5,100));
    apple_x = r * DOT_SIZE;

    r = (QRandomGenerator::global()->bounded(5,65));
    apple_y = r * DOT_SIZE;

    for (const QRect &obstacleRect : obstacles) {
        if (apple_x == obstacleRect.x() && apple_y == obstacleRect.y()) {
            locateApple();
            return;
        }
    }
}
