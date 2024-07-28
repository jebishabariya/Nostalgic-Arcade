#ifndef MODE2_H
#define MODE2_H

#include <QDialog>
#include <choice.h>
namespace Ui {
class mode2;
}

class mode2 : public QDialog
{
    Q_OBJECT

public:
    explicit mode2(QWidget *parent = nullptr);
    ~mode2();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mode2 *ui;
};

#endif // MODE2_H
