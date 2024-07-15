#ifndef SNAKE_H
#define SNAKE_H

#include <QDialog>

namespace Ui {
class Snake;
}

class Snake : public QDialog
{
    Q_OBJECT

public:
    explicit Snake(QWidget *parent = nullptr);
    ~Snake();

private:
    Ui::Snake *ui;
};

#endif // SNAKE_H


