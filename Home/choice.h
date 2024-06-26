#ifndef CHOICE_H
#define CHOICE_H

#include <QDialog>

namespace Ui {
class choice;
}

class choice : public QDialog
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
    Ui::choice *ui;
};

#endif // CHOICE_H
