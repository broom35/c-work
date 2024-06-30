QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    manage.cpp \
    score.cpp \
    signin.cpp \
    signup.cpp \
    sms.cpp

HEADERS += \
    Account.h \
    AccountsManager.h \
    Student.h \
    StudentsManager.h \
    manage.h \
    score.h \
    signin.h \
    signup.h \
    sms.h \
    studentScore.h \
    studentScoreManager.h

FORMS += \
    manage.ui \
    score.ui \
    signin.ui \
    signup.ui \
    sms.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
