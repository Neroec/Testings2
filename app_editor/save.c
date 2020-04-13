/**
 * load.c -- функция загрузки текста из файла
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include "common.h"
#include "text/text.h"

static void save_line(int index, char *contents, int cursor, void *data);

/**
 * Сохраняет содержимое указанного файла в другой файл
 */
static void save_line(int index, char *contents, int cursor, void *data)
{
    FILE *f = (FILE*) data;
    /* Функция обработчик всегда получает существующую строку */
    assert(contents != NULL);
    
    /* Декларируем неиспользуемые параметры */
    UNUSED(index);
    UNUSED(cursor);
    
    /* Сохраняет строку в файл */
    fprintf(f, "%s", contents);
}

/**
 * Загружает содержимое указанного файла
 */
void save(text txt, char *filename)
{
    FILE *f;
    /* Открываем файл для записи */
    f = fopen(filename, "w");

    /* Применяем функцию save_line к каждой строке текста */
    process_forward(txt, save_line, (void*) f);

    fclose(f);
}
