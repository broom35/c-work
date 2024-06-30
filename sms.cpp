#include "sms.h"
#include "ui_sms.h"
#include <string>
#include<QMessageBox>
#include<signin.h>
#include"score.h"
#include"studentScore.h"
SMS::SMS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SMS)
{
    ui->setupUi(this);
}

SMS::~SMS()
{
    delete ui;
}
void SMS::init(){
    this->SSMinstance = new SSM::StudentManager();
    this->setWindowTitle("学生管理系统");
    std::string ty = "身份：";
    int as = static_cast<int>(acc->getType());
    switch(as){
    case 0:
        ty += "学生";
        break;
    case 1:
        ty += "教师";
        break;
    case 2:
        ty += "管理员";
        break;
    default:
        ty += "你它妈的怎么进来的？联系2735712359@qq.com";
        break;
    }

    ui->acType->setText(QString::fromStdString(ty));
    ui->ac->setText(QString::fromStdString("账号: "+this->acc->getAccount()));
}
void SMS::on_acType_linkHovered(const QString &link)
{
    QMessageBox::warning(this,"Warning","just testing!");
}
//useless!

void SMS::on_buttonBox_accepted()
{
    this->close();
}


void SMS::on_buttonBox_rejected()
{
    this->close();
    SignIn *siui = new SignIn();
    siui->init();
    siui->show();
}


void SMS::on_pushButton_clicked()
{
    score *scui = new score();
    scui->init(this->acc->getAccount());
    scui->show();
}

