#ifndef MAINWINDOWPINGPONG_H
#define MAINWINDOWPINGPONG_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QDialog>
#include <QPoint>
#include <QRandomGenerator>
#include "ui_pingpongresult.h"

namespace Ui {
class MainWindowPingPong;
}

class MainWindowPingPong : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowPingPong(QWidget *parent = nullptr);
    ~MainWindowPingPong();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void updateGame();
    void resetBall();
    void showResultDialog(const QString &result);

private:
    Ui::MainWindowPingPong *ui;
    QPoint ballDirection;
    QDialog *resultDialog;
    Ui::Dialog resultUi;
};

#endif // MAINWINDOWPINGPONG_H
