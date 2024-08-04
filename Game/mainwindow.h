#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include "choice.h"
#include <QMediaPlayer>
#include <QAudioInput>
#include <QPropertyAnimation>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();


private:
     Ui::MainWindow *ui;
    QMediaPlayer *bgMusic;
    QAudioOutput *Vol;
    QPropertyAnimation *animation;
    void closeEvent(QCloseEvent *event);
    void hideEvent(QHideEvent *event);
};

#endif // MAINWINDOW_H
