#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void insertion_sort_list(listint_t **list);
listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}

int main(void)
{
    listint_t *list;
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    list = create_listint(array, n);
    if (!list)
        return (1);
    //print_list(list);
    printf("\n");
    insertion_sort_list(&list);
    //printf("\n");
   // print_list(list);
    return (0);
}

void insertion_sort_list(listint_t **list)
{
    listint_t * tr, *pr;
    tr = (*list)->next;
    pr = tr->prev;

    while (tr)
    {
        while (tr->n < pr->n)
        {
            tr->prev = pr->prev;
            pr->prev->next = tr;
            tr->next = pr;
            pr->prev = tr;
            tr->next->prev = pr;
            pr->next = tr->next;
            tr = tr->next;
            pr = tr->prev;
        }
        tr = tr->next;
        pr = tr->prev;
    }
}