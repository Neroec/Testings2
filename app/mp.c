/**
 * mp.c -- перемещает курсор в новую позицию в текущей строке
 *
 * Copyright (c) 2020 Roman "Neroe" Nikanorov <nikanoro@cs.petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include "_text.h"

int mp(text txt, int arg1)
{
    /* Проверяем, имеется ли текст */
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "В тексте нету строк!\n");
        return 3;
    }

    /* Текст ненулевой длины должен содержать хотя бы одну строку */
    assert(txt->begin != NULL && txt->end != NULL);
    
    /* Указатель на текущую строку с курсором */
    node* current = txt->begin;
    
    /* Смещаем указатель до нужной строки */
    while (current != txt->cursor->line) {
        current = current->next;
    }

    /* Длина строки */
    size_t lenght = strlen(current->contents);
    
    /* Проверяем строку */
    if (lenght == 0) {
        fprintf(stderr, "Это пустая строка, в ней нет позиции!\n");
        return 4;
    }
    if (lenght == 1) {
	txt->cursor->position = 0;
        return 0;
    }
    
    /* Проверяем на наличие данной позиции в строке */
    if (arg1 < 0) {
        printf("Нумерация позиций в строке начинается с 0\n");
        return 1;
    }
    if (arg1 > (int) lenght - 2) {
        printf("В строке нет такой позиции\nПоследняя позиция: %d\n", (int) lenght - 2);
        return 2;
    }
    
    /* Новая позиция курсора в строке */
    txt->cursor->position = arg1;
    
    return 0;
}
