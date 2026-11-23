#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define MAX_NODE_LENGTH 50
#define MAX_EVENTS 10000
#define MIN_ARCHIVE_RECORDS 20
#define ARCHIVE_INTERVAL 30
#define DUPLICATE_INTERVAL 10
#define MINUTES_IN_DAY 1440

#define ARCHIVE_FILE "archive.txt"

// Структура для хранения информации о событии
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
void writeArchive(Event* events, int count);
void processBuffer(Event* buffer, int count);

// Перевод времени в минуты
int getTime(Event event) {
    return event.h * 60 + event.m;
}

int main(void) {
    setlocale(LC_ALL, "Russian");

    // Выделение памяти для массивов событий
    Event* events = (Event*)malloc(MAX_EVENTS * sizeof(Event));
    Event* buffer = (Event*)malloc(MAX_EVENTS * sizeof(Event));

    // Проверка успешного выделения памяти
    if (events == NULL || buffer == NULL) {
        printf("Ошибка выделения памяти!\n");

        free(events);
        free(buffer);

        return 1;
    }

    printf("Программа обработки событий запущена.\n");

    // Освобождение выделенной памяти
    free(events);
    free(buffer);

    return 0;
}
