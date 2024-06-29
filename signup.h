#ifndef SIGNUP_H
#define SIGNUP_H
#include "AccountsManager.h"
#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();
    AccountsManager *accountsManager;

private slots:
    void on_SUButton_clicked();

private:
    Ui::SignUp *ui;
};

#endif // SIGNUP_H
