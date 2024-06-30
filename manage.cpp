#include "manage.h"
#include "ui_manage.h"

Manage::Manage(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Manage)
{
    ui->setupUi(this);
}

Manage::~Manage()
{
    delete ui;
}
void Manage::init(){
    this->setWindowTitle("管理页面");
    if(this->SSMinstance==nullptr){
        SSM::StudentManager *Ssm = new SSM::StudentManager();
        Ssm->init();
        this->SSMinstance=Ssm;
    }
    if (this->SCMinstance==nullptr)
    {
        SCM::StudentScoreManager *Scm = new SCM::StudentScoreManager();
        Scm->init();
        this->SCMinstance=Scm;
    }
    std::string Allscores = this->SCMinstance->AllScores();
    ui->Allscores->setText(QString::fromStdString(Allscores));
}
