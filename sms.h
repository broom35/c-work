#ifndef SMS_H
#define SMS_H

#include <QMainWindow>
#include"AccountsManager.h"

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
    AccountsManager *accountsManager;


private:
    Ui::SMS *ui;
};
#endif // SMS_H
