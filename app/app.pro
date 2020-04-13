TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.c \
    ../app_editor/load.c \
    ../app_editor/save.c \
    ../app_editor/show.c \
    ../app_editor/showodd.c \
    ../app_editor/text/append_line.c \
    ../app_editor/text/create_text.c \
    ../app_editor/text/j.c \
    ../app_editor/text/m.c \
    ../app_editor/text/mp.c \
    ../app_editor/text/process_forward.c \
    ../app_editor/text/remove_all.c

HEADERS += \
    ../app_editor/common.h \
    ../app_editor/text/_text.h \
    ../app_editor/text/text.h

QMAKE_CFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov
