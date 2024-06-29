#include "signin.h"
#include <QApplication>
#include "AccountsManager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AccountsManager Pam= AccountsManager();
    Pam.Init();
    SignIn w;
    w.accountsManager = &Pam;
    w.show();
    return a.exec();
}
