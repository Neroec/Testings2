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
    ../app/myfunc.h \
    ../app_editor/text/_text.h \
    ../app_editor/text/text.h \
    ../app_editor/common.h \
    j.h \
    m.h \
    mp.h \
    save.h \
    showodd.h
    
SOURCES += \
    main.cpp \
    ../app_editor/text/process_forward.c \
    ../app_editor/text/m.c \
    ../app_editor/text/mp.c \
    ../app_editor/text/j.c \
    ../app_editor/save.c \
    ../app_editor/showodd.c
    
INCLUDEPATH += \
    ../app \
    ../app_editor
