QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    accountcontroller.cpp \
    dbgateway.cpp \
    login.cpp \
    main.cpp \
    dashboard.cpp \
    scheme.cpp \
    schemecontroller.cpp \
    transaction.cpp \
    transactioncontroller.cpp

HEADERS += \
    account.h \
    accountcontroller.h \
    dashboard.h \
    dbgateway.h \
    login.h \
    scheme.h \
    schemecontroller.h \
    transaction.h \
    transactioncontroller.h

FORMS += \
    dashboard.ui \
    login.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
