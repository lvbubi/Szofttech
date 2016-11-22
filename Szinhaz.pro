TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Admin.cpp \
    Customer.cpp \
    Director.cpp \
    GuestBook.cpp \
    Payment.cpp \
    Plays.cpp \
    Review.cpp \
    Ticket.cpp

DISTFILES += \
    Szinhaz.pro.user \
    README.md

HEADERS += \
    Admin.h \
    C_Datas.h \
    Customer.h \
    Director.h \
    GuestBook.h \
    Payment.h \
    Play.h \
    Plays.h \
    Review.h \
    Ticket.h
