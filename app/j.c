/**
 * j.c -- объединяет строку с курсором со следующей
 *
 * Copyright (c) 2020 Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int j(text txt)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "В тексте нету строк!\n");
        return 2;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Объявляем используемые переменные */
    int i;

    /* Проверяем строку с курсором */
    if (txt->cursor->line == NULL) {
        fprintf(stderr, "Курсор указывает в никуда!\n");
        return 3;
    }
    
    /* Запоминаем строку */
    node *nd = txt->cursor->line->next;

    /* Проверяем на последнюю строку */
    if (nd == NULL) {
        printf("Ошибка: это последняя строка\n");
        return 1;
    }

    /* Удаляем символ перевода строки */
    for (i = 0; txt->cursor->line->contents[i] != '\n'; i++);
    txt->cursor->line->contents[i] = '\0';

    /* Прикрепляем следующую строку */
    strncat(txt->cursor->line->contents, nd->contents, MAXLINE);

    /* Меняем связи */
    if (nd->next != NULL) {
        nd->next->previous = txt->cursor->line;
        txt->cursor->line->next = nd->next;
    } else {
        txt->cursor->line->next = NULL;
        txt->end = txt->cursor->line;
    }

    /* Освобождаем память */
    free(nd);

    return 0;
}
