/**
 * m.c -- перемещает курсор в новую позицию
 *
 * Copyright (c) 2020 Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int m(text txt, int arg1, int arg2)
{
    /* Проверяем на наличие строки с данным номером */
    if (arg1 < 0) {
        printf("Нумерация строк начинается с 0\n");
        return 1;
    }
    if (arg1 > (int) txt->length - 1) {
        printf("Нет строки с таким номером\nПоследний номер: %d\n", (int) txt->length - 1);
        return 2;
    }
    
    /* Указатель на новую строку с курсором */
    node* current = txt->begin;
    
    /* Смещаем указатель до нужной строки */
    int i;
    for (i = 0; i < arg1; i++) {
        current = current->next;
    }
    
    /* Проверяем на наличие данной позиции в строке */
    if (arg2 < 0) {
        printf("Нумерация позиций в строке начинается с 0\n");
        return 3;
    }
    if (arg2 > (int) strlen(current->contents) - 2) {
        printf("В строке нет такой позиции\nПоследняя позиция: %d\n", (int) strlen(current->contents) - 2);
        return 4;
    }
    
    /* Новая строка курсора */
    txt->cursor->line = current;
    
    /* Новая позиция курсора в строке */
    txt->cursor->position = arg2;
    
    return 0;
}
