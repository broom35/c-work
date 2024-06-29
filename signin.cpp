#include "signin.h"
#include "ui_signin.h"
#include "sms.h"
#include "signup.h"
#include <QMessageBox>
#include<string.h>
SignIn::SignIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
}

SignIn::~SignIn()
{
    delete ui;
}

void SignIn::on_SignIn_accepted()
{

}


void SignIn::on_passWord_cursorPositionChanged(int arg1, int arg2)
{

}

void SignIn::on_SIButton_clicked()
{
    std::string ac,pw="";
    ac = ui->accountName->text().toStdString();
    pw =ui->passWord->text().toStdString();

    if(this->accountsManager->SignIn(ac,pw)){
        this->close();
        SMS *sui = new SMS;
        sui->accountsManager=this->accountsManager;
        sui->show();
        return;
    }
    QMessageBox::warning(this,"Warning","Wrong account or password");
    ui->accountName->clear();
    ui->passWord->clear();
    ui->accountName->setFocus();

}


void SignIn::on_SUButton_clicked()
{
    SignUp *suui = new SignUp;
    suui->accountsManager = this->accountsManager;
    suui ->show();
}

