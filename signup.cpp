#include "signup.h"
#include "ui_signup.h"
#include<QMessageBox>

SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
}

SignUp::~SignUp()
{
    delete ui;
}

void SignUp::on_SUButton_clicked()
{
    int acType = ui->ACType->currentIndex();
    // 0:学生 1：老师
    std::string ac,pw="";
    ac = ui->ACName->text().toStdString();
    pw =ui->PSWord->text().toStdString();
    if(this->accountsManager->SignUp(ac,pw,acType)){
        this->accountsManager->Save();
        QMessageBox::information(this,"Success","Sign up successfully,please sign in again.");
        this->close();
        return;
    }
}


