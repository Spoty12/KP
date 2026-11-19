#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define _CRT_SECURE_NO_WARNINGS
#define MAX_NODE_LENGTH 50
#define MAX_EVENTS 10000
#define MIN_ARCHIVE_RECORDS 20
#define ARCHIVE_INTERVAL 30
#define DUPLICATE_INTERVAL 10
#define MINUTES_IN_DAY 1440

#define ARCHIVE_FILE "archive.txt"

// Структура события
typedef struct {
    int h;
    int m;
    char node[MAX_NODE_LENGTH];
    int messages;
    int size;
} Event;

// Объявления функций
int readEvent(Event* event);
int getTime(Event event);
int isDuplicate(Event* events, int count, Event event);
int shouldArchive(Event* events, int count);
int filterDuplicates(Event* buffer, int count, Event* unique);
int writeArchive(Event* events, int count);
int processBuffer(Event* buffer, int count, Event* unique,
    int* duplicates, int* archived);

// Главная функция
int main()
{
    setlocale(LC_ALL, "Russian");

    Event* buffer = (Event*)malloc(MAX_EVENTS * sizeof(Event));
    Event* unique = (Event*)malloc(MAX_EVENTS * sizeof(Event));

    if (buffer == NULL || unique == NULL)
    {
        printf("Ошибка выделения памяти.\n");

        free(buffer);
        free(unique);

        return 1;
    }

    printf("Сервер логирования запущен.\n");

    free(buffer);
    free(unique);

    return 0;
}
