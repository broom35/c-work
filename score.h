#ifndef SCORE_H
#define SCORE_H

#include <QDialog>
#include"studentScoreManager.h"
#include "ui_score.h"
#include"studentScore.h"
#include<vector>
namespace Ui {
class score;
}

class score : public QDialog
{
    Q_OBJECT

public:
    explicit score(QWidget *parent = nullptr);
    ~score();
    void init(std::string accid);
    SCM::StudentScoreManager *SCMinstance=nullptr;
private:
    Ui::score *ui;
};

#endif // SCORE_H
