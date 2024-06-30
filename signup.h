#ifndef SIGNUP_H
#define SIGNUP_H
#include <QDialog>
#include"AccountsManager.h"
#include"StudentsManager.h"
namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    void init();
    ASM::AccountsManager *instance;
private slots:
    void on_SUButton_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
