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
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "В тексте нету строк!\n");
        return 5;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
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

    /* Новая строка курсора */
    txt->cursor->line = current;
    
    /* Длина строки */
    size_t lenght = strlen(current->contents);
    
    /* Проверяем строку */
    if (lenght == 0) {
        fprintf(stderr, "Это пустая строка, в ней нет позиции!\n");
        return 6;
    }
    if (lenght == 1) {
	txt->cursor->position = 0;
        return 0;
    }
    
    /* Проверяем на наличие данной позиции в строке */
    if (arg2 < 0) {
        printf("Нумерация позиций в строке начинается с 0\n");
        return 3;
    }
    if (arg2 > (int) lenght - 2) {
        printf("В строке нет такой позиции\nПоследняя позиция: %d\n", (int) lenght - 2);
        return 4;
    }
        
    /* Новая позиция курсора в строке */
    txt->cursor->position = arg2;
    
    return 0;
}
