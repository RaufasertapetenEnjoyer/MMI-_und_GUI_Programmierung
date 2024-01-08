QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dialogadd.cpp \
    dialogdel.cpp \
    dialogedit.cpp \
    dialogstat.cpp \
    main.cpp \
    mainwindow.cpp \
    player.cpp \
    playerdatabase.cpp \
    playertablemodel.cpp \
    playertablemodelalt.cpp \
    test.cpp \
    userlistmodel.cpp

HEADERS += \
    dialogadd.h \
    dialogdel.h \
    dialogedit.h \
    dialogstat.h \
    mainwindow.h \
    player.h \
    playerdatabase.h \
    playertablemodel.h \
    playertablemodelalt.h \
    test.h \
    userlistmodel.h

FORMS += \
    dialogadd.ui \
    dialogdel.ui \
    dialogedit.ui \
    dialogstat.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
