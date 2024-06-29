#include "sms.h"
#include "ui_sms.h"

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
