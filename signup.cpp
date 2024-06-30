#include "signup.h"
#include "ui_signup.h"
#include<QMessageBox>
#include"AccountsManager.h"
SignUp::SignUp(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SignUp)
{
    ui->setupUi(this);
}
void SignUp::init(){
    this->setWindowTitle("注册界面");
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
    if(ac==""||pw==""){
         QMessageBox::warning(this,"Warning","account or password couldn't been empty!");
        return;
    }
    if(this->instance->SignUp(ac,pw,acType)){
        this->instance->Save();
        QMessageBox::information(this,"Success","Sign up successfully,please sign in again.");
        this->close();
        return;
    }else{
        QMessageBox::warning(this,"Warning","Something wrong happen! please sign up with your student or teacher number!");
    }
}


