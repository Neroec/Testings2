/**
 * text.h -- внешний интерфейс библиотеки для работы с текстом
 *
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#ifndef TEXT_H
#define TEXT_H

#define MAXLINE 255

/* Декларирует неиспользуемый аргумент,
 * корректно подавляя предупреждение вида "unused parameter" */
#define UNUSED(x) (void)(x)

/**
 * Абстрактный тип текстовых объектов
 */
typedef struct _list *text;

/**
 * Абстрактный тип курсора
 */
typedef struct _crsr *cursor;

/**
 * Обрабатывает текст, применяя заданную функцию к каждой строке
 * 
 * @param txt текст
 * @param process функция-обработчик
 * @returns none
 */
void process_forward(
    text txt,
    void (*process)(int index, char *contents, int cursor_position, void *data),
    void *data
);

/**
 * Выгружает содержимое в указанный файл
 * @param txt текст
 * @param filename имя файла для сохраннеия текста
 */
void save(text txt, char *filename);

/**
 * Выводит содержимое указанного файла на экран, опуская чётные строки
 * @param txt текст
 * @param filename имя файла для сохранения вывода
 */
void showodd(text txt, char *filename);

/**
 * Перемещаем курсор в заданную позицию
 * @param txt текст
 * @param arg1 номер строки
 * @param arg2 номер позиции в строке
 * @returns код исполнения 
 */
int m(text txt, int arg1, int arg2);

/**
 * Перемещаем курсор в заданную позицию в текущей строке
 * @param txt текст
 * @param arg1 номер позиции в строке
 * @returns код исполнения 
 */
int mp(text txt, int arg1);

/**
 * Объединяет строку с курсором со следующей
 * @param txt текст
 * @returns код исполнения 
 */
int j(text txt);

#endif
