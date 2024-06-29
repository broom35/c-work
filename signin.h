#ifndef SIGNIN_H
#define SIGNIN_H
#include <QDialog>
#include"AccountsManager.h"
namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    AccountsManager *accountsManager;
    ~SignIn();

private slots:
    void on_SignIn_accepted();

    void on_passWord_cursorPositionChanged(int arg1, int arg2);

    void on_SIButton_clicked();

    void on_SUButton_clicked();


private:
    Ui::SignIn *ui;

};

#endif // SIGNIN_H
