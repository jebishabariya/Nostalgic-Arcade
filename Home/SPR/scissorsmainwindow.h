#ifndef SCISSORSMAINWINDOW_H
#define SCISSORSMAINWINDOW_H

#include <QMainWindow>
#include <QRandomGenerator>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowScissors; }
QT_END_NAMESPACE

class MainWindowScissors : public QMainWindow
{
    Q_OBJECT

public:
    MainWindowScissors(QWidget *parent = nullptr);
    ~MainWindowScissors();

private slots:
    void on_pushButton_7_clicked(); // Scissors
    void on_pushButton_8_clicked(); // Paper
    void on_pushButton_9_clicked(); // Rock
    void on_pushButton_clicked();   // Restart

private:
    Ui::MainWindowScissors *ui;
    void updateChoices(const QString &playerChoice, const QString &computerChoice);
    void determineResult(const QString &playerChoice, const QString &computerChoice);
};

#endif // SCISSORSMAINWINDOW_H

