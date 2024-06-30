#ifndef MANAGE_H
#define MANAGE_H

#include <QDialog>
#include"StudentsManager.h"
#include"studentScoreManager.h"
namespace Ui {
class Manage;
}

class Manage : public QDialog
{
    Q_OBJECT

public:
    explicit Manage(QWidget *parent = nullptr);
    ~Manage();
    void init();
    SSM::StudentManager *SSMinstance=nullptr;
    SCM::StudentScoreManager *SCMinstance=nullptr;
private:
    Ui::Manage *ui;
};

#endif // MANAGE_H
