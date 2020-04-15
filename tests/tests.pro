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
    ../app/main.c \
    ../app/process_forward.c \
    ../app/save.c \
    ../app/showodd.c \
    ../app/m.c \
    ../app/mp.c \
    ../app/j.c
    
INCLUDEPATH += \
    ../app
