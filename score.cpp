#include "score.h"

score::score(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::score)
{
    ui->setupUi(this);
}
void score::init(std::string accid){
    if(this->SCMinstance==nullptr){
        SCM::StudentScoreManager *Scm = new SCM::StudentScoreManager();
        Scm->init();
        this->SCMinstance=Scm;
    }
    this->setWindowTitle("学生成绩");
    std::vector<std::string> subcores = this->SCMinstance->getStudent(accid).AllScores();
    for(auto &i:subcores){
        ui->scoreList->addItem(QString::fromStdString(i));
    }
}
score::~score()
{
    delete ui;
}
