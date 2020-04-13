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
    /* Объявляем используемые переменные */
    int i;
    
    /* Запоминаем строку */
    node *nd = txt->cursor->line->next;

    /* Проверяем на последнюю строку */
    if (nd == NULL) {
        printf("Ошибка: это последняя строка\n");
        return 1;
    }

    /* Удаляем символ перевода строки */
    for (i = 0; txt->cursor->line->contents[i] != '\n'; i++);
    txt->cursor->line->contents[i] = ' ';

    /* Прикрепляем следующую строку */
    strcat(txt->cursor->line->contents, nd->contents);

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
