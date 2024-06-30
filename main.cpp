#include "signin.h"
#include <QApplication>
#include "AccountsManager.h"
#include "StudentsManager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ASM::AccountsManager Pam= ASM::AccountsManager();
    SSM::StudentManager Stm = SSM::StudentManager();
    Stm.init();
    Pam.SSMinstance = &Stm;
    Pam.Init();

    SignIn w;
    w.instance = &Pam;
    w.init();
    w.show();
    return a.exec();
}
