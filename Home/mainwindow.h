#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDialog>
#include <QMainWindow>
#include <mode2.h>
#include <choice.h>
#include <QMediaPlayer>
#include <QAudioInput>
namespace Ui {
class MainWindow;
}

class MainWindow : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();


private:
   QMediaPlayer *bgMusic;
    QAudioOutput *Vol;
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
    void hideEvent(QHideEvent *event);
};

#endif // MAINWINDOW_H
