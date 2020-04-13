/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text/text.h"
#include "common.h"

#define MAXLINE 255

int main2()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg, *arg2;
    
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Вывод сообщения о командах */
    printf("Введите help для просмотра списка команд\n");
    
    /* Цикл обработки команд */
    while (1) {
        printf("Введите команду > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Пока!\n");
            break;
        }

	/* Список команд */
        if (strcmp(cmd, "help") == 0) {
	    FILE *in = fopen("commands.txt", "r");
	    while (fgets(cmdline, MAXLINE, in))
		printf("%s", cmdline);
	    fclose(in);
            continue;
        }
	
        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Используйте: load имя_файла\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

       /* Выгружаем содержимое файла, заданного параметром */
       if (strcmp(cmd, "save") == 0) {
	   if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Используйте: save имя_файла\n");
            } else {
                save(txt, arg);
            }
            continue;
        }
       
        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }

	/* Выводим текст, опуская чётные строки */
        if (strcmp(cmd, "showodd") == 0) {
            char line[MAXLINE+1] = {"showodd.txt"};
            showodd(txt, line);
            continue;
        }

	/* Перемещение курсора в заданную позицию */
	if (strcmp(cmd, "m") == 0) {
	    arg = strtok(NULL, " \n");
	    arg2 = strtok(NULL, " \n");
	    if (arg == NULL || arg2 == NULL) {
                fprintf(stderr, "Используйте: m номер_строки позиция\n");
            } else {
	       m(txt, atoi(arg), atoi(arg2));
            }
            continue;
        }

        /* Перемещение курсора в заданную позицию в текущей строке */
	if (strcmp(cmd, "mp") == 0) {
	    arg = strtok(NULL, " \n");
	    if (arg == NULL) {
                fprintf(stderr, "Используйте: mp позиция\n");
            } else {
	       mp(txt, atoi(arg));
            }
            continue;
        }

	/* Объединяет строку с курсором со следующей */
	if (strcmp(cmd, "j") == 0) {
	    j(txt);
            continue;
        }
	
        /* Если команда не известна */
        fprintf(stderr, "Неизвестная команда: %s\n", cmd);
    }

    return 0;
}
