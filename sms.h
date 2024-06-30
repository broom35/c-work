#ifndef SMS_H
#define SMS_H

#include <QMainWindow>
#include"AccountsManager.h"
#include"StudentsManager.h"
#include"Account.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class SMS;
}
QT_END_NAMESPACE

class SMS : public QMainWindow
{
    Q_OBJECT

public:
    SMS(QWidget *parent = nullptr);
    ~SMS();
    SSM::StudentManager * SSMinstance;
    void setAccount(Account& account)
    {
        this->acc = &account;
    }
    void init();


private slots:
    void on_acType_linkHovered(const QString &link);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_pushButton_clicked();

private:
    Ui::SMS *ui;
    Account * acc;
};
#endif // SMS_H
