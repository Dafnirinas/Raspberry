TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /home/sergey/mico/include
INCLUDEPATH += /home/sergey/mico/include/mico
INCLUDEPATH += /home/sergey/mico/include/coss

LIBS += -L/home/sergey/mico/lib -lmico2.3.13 -lmicocoss2.3.13 -lmicoaux2.3.13 -lmicoir2.3.13 -lpthread -ldl -L/usr/local/lib -lserial
SOURCES += main.cpp \
    Watering.cc \
    initserver.cpp \
    eventchannelServer.cpp \
    corbainit.cpp \
#    deviceser.cpp \
    pullconsumer_impl.cpp \
    pullsupplier_impl.cpp \
    pushconsumer_impl.cpp \
    pushsupplier_impl.cpp \
    wateringsystem_impl.cpp

HEADERS += \
    Watering.h \
    initserver.h \
    eventchannelServer.h \
    corbainit.h \
#    deviceser.h \
    pullconsumer_impl.h \
    pullsupplier_impl.h \
    pushconsumer_impl.h \
    pushsupplier_impl.h \
    wateringsystem_impl.h

DISTFILES += \
    Watering.idl
