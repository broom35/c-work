#include "signin.h"
#include "ui_signin.h"
#include "sms.h"
#include "signup.h"
#include <QMessageBox>
#include"AccountsManager.h"
#include<string.h>
SignIn::SignIn(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignIn)
{
    ui->setupUi(this);
}
void SignIn::init(){
     this->setWindowTitle("登录界面");
    if(this->instance==nullptr){
         ASM::AccountsManager Pam= ASM::AccountsManager();
        Pam.Init();
        this->instance = &Pam;
     }
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

    if(this->instance->SignIn(ac,pw)){
        this->close();
        SMS *sui = new SMS;
        sui->setAccount(this->instance->getAccount(ac));
        sui->init();
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
    suui->instance = this->instance;
    suui->init();
    suui ->show();
}

