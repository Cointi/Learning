#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <stdbool.h>
/*Описана структура данных
typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;
Требуется реализовать только одну функцию, которая в данном списке находит адрес блока памяти занимающий больше всего места.
Адрес хранится в поле address, поле size - соответствующий размер данного блока. Если список пустой, то функция должна возвращать 0.
Если есть несколько таких блоков, то вернуть адрес любого из них.*/

typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;



uint64_t findMaxBlock(list *head)
{
    if(!head) // проверка на наличие данных
        return 0;
    const list *max_node = head; // делаем указатель на структуру, через этот указатель мы не можем поменять содержимое, благодаря const

    for (const list *current = head->next; current; current = current->next)
    {
        if (current->size > max_node->size)
            max_node = current;

    }

    return max_node->address;
}

int main()
{
    // Выделяем память под первый узел
    list *head = (list *)malloc(sizeof(list));
    if (!head)
        return 1;  // Проверяем выделение памяти

    head->address = 1000;
    head->size = 50;
    snprintf(head->comment, 64, "First block");
    head->next = NULL;

     // Выделяем память под второй узел
    list *node2 = (list *)malloc(sizeof(list));
    if (!node2) return 1;

    node2->address = 2000;
    node2->size = 80;
    snprintf(node2->comment, 64, "Second block");
    node2->next = NULL;

     // Связываем узлы
    head->next = node2;

    // Вывод данных
    list *current = head;
    while (current)
    {
        printf("Address: %llu, Size: %zu, Comment: %s\n",
               current->address, current->size, current->comment);
        current = current->next;
    }
    printf("%llu",findMaxBlock(head));
    // Освобождаем память
    free(node2);
    free(head);



    return 0;
}
