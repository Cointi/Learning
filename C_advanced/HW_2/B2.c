#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
/*Описана структура данных
Требуется реализовать только одну функцию, которая анализирует данный список и возвращает сколько всего памяти используется.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.*/

typedef struct list {
void *address;
size_t size;
char comment[64];
struct list *next;
} list;


size_t totalMemoryUsage(list *head)
{
    if(!head) // проверка на наличие данных
        return 0;
    size_t res=0; // переменная для результата суммы

    for (const list *current = head; current; current = current->next)
        res+=current->size;

    return res;
}

int main()
{
    // Выделяем память под первый узел
    list *head = (list *)malloc(sizeof(list));
    if (!head)
        return 1;  // Проверяем выделение памяти

    head->address = 140525067852320;
    head->size = 10;
    snprintf(head->comment, 64, "First block");
    head->next = NULL;

     // Выделяем память под второй узел
    list *node2 = (list *)malloc(sizeof(list));
    if (!node2) return 1;

    node2->address = 140525067852350;
    node2->size = 30;
    snprintf(node2->comment, 64, "Second block");
    node2->next = NULL;

     // Связываем узлы
    head->next = node2;

    // Выделяем память под третий узел
    list *node3 = (list *)malloc(sizeof(list));
    if (!node3) return 1;

    node3->address = 140525067852900 ;
    node3->size = 100;
    snprintf(node3->comment, 64, "Third block");
    node3->next = NULL;

     // Связываем узлы
    node2->next = node3;

    // Вывод данных
    list *current = head;

    while (current)
    {
        printf("Address: %p, Size: %zu, Comment: %s\n",
               current->address, current->size, current->comment);
        current = current->next;
    }
    printf("Total memory usage: %zu\n", totalMemoryUsage(head));
    // Освобождаем память
    free(node3);
    free(node2);
    free(head);

    return 0;
}
