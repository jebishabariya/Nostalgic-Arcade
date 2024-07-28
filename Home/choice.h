#ifndef CHOICE_H
#define CHOICE_H

//#include <D:/labProject/Nostalgic-Arcade/snakee/snake.h>
#include <QDialog>
#include <QWidget>
#include<QProcess>
#include <QPushButton>
#include<snakemain.h>
#include<gameboard.h>
#include <QMediaPlayer>
#include <QAudioInput>
namespace Ui {
class choice;
}

class choice : public QDialog// public QWidget
{
    Q_OBJECT

public:
    explicit choice(QWidget *parent = nullptr);
    ~choice();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    QMediaPlayer *bgMusic;
    QAudioOutput *Vol;
    Ui::choice *ui;
    void hideEvent(QHideEvent *event);
    void closeEvent(QCloseEvent *event);
};

#endif // CHOICE_H
