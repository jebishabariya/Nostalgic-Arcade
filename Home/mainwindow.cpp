#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QMediaPlayer>
#include <QAudioOutput>

MainWindow::MainWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel *label = ui->label; // Assuming the QLabel is named "label" in the .ui file

    // Create a property animation for the QLabel's geometry property
    QPropertyAnimation *animation = new QPropertyAnimation(label, "geometry");
    animation->setDuration(1000); // Duration of 1 second
    animation->setStartValue(QRect(label->x(), label->y(), label->width(), label->height()));
    animation->setEndValue(QRect(label->x(), label->y() + 25, label->width(), label->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);

    // Set the animation to loop infinitely
    animation->setLoopCount(-1);

    // Start the animation
    animation->start();

    bgMusic = new QMediaPlayer(this);
    Vol = new QAudioOutput(this);
    bgMusic->setAudioOutput(Vol);
    Vol->setVolume(0.6);
    bgMusic->setSource(QUrl("qrc:/new/res/bgmusic.mp3"));
    //bgMusic->setVolume(50);
    bgMusic->setLoops(QMediaPlayer::Infinite);
    bgMusic->play();

}

MainWindow::~MainWindow()
{
    if (bgMusic) {
        bgMusic->stop(); // Stop playback
        delete bgMusic; // Delete the player
    }
    if (Vol) {
        delete Vol; // Delete the audio output
    }
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->hide();
    choice ind;
    ind.setModal(true);
    ind.showFullScreen();
    ind.exec();
}
void MainWindow::hideEvent(QHideEvent *event)
{
    QDialog::hideEvent(event);
    if (bgMusic) {
        bgMusic->stop(); // Stop playback when the window is hidden
    }
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    QDialog::closeEvent(event);
    if (bgMusic) {
        bgMusic->stop(); // Stop playback when the window is closed
    }
}




