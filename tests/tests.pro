include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov


HEADERS += \
    ../app/_text.h \
    ../app/text.h \
    save.h \
    showodd.h \
    m.h \
    mp.h \
    j.h
    
SOURCES += \
    main.cpp \
    ../app/process_forward.c \
    ../app/text/save.c \
    ../app/text/showodd.c \
    ../app/text/m.c \
    ../app/mp.c \
    ../app/j.c
    
INCLUDEPATH += \
    ../app
