#include "dll.h"
#include <stdio.h>


static DLLNode *DLL_new_node(void *data)
{
    DLLNode *new_node = (DLLNode *)malloc(sizeof(DLLNode));

    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;

    return new_node;
}

static void append(void *data, DLL *self)
{
    DLLNode *temp = self->head;
    DLLNode *new = DLL_new_node(data);

    if (!self->head)
    {
        self->head = new;
        return;
    }

    while (temp->next)
        temp = temp->next; /* Go to last node */

    temp->next = new;
    new->prev = temp;
}

static void print_str(DLL *self)
{
    DLLNode *temp = self->head;
    
    while (temp)
    {
        printf("%s ", *((char **)temp->data));
        temp = temp->next;
    }

    printf("\n");

}

DLL DoublyLinkedList()
{
    DLL new_list;

    new_list.head = NULL;
    new_list.size = 0;
    new_list.append = append;
    new_list.print_str = print_str;
    return new_list;
}
