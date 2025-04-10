#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

void readLinkedList(Node *ptr);

int main(void)
{
    Node *ptr;
    ptr = malloc(sizeof(Node));
    ptr->data = 1;
    ptr->next = malloc(sizeof(Node));
    ptr->next->data = 3;
    ptr->next->next = malloc(sizeof(Node));
    ptr->next->next->data = 4;
    ptr->next->next->next = NULL;

    readLinkedList(ptr);

    // insert
    {
        Node *p = malloc(sizeof(Node));
        p->data = 2;
        p->next = ptr->next;
        ptr->next = p;
    }
    readLinkedList(ptr);

    // delete
    {
        Node *p = ptr->next->next;
        ptr->next->next = p->next;
        free(p);
    }
    readLinkedList(ptr);

    // free
    {
        Node *p = ptr;
        while (p != NULL)
        {
            Node *tmp = p;
            // tmp->next = NULL;
            p = p->next;
            free(tmp);
        }
    }
    // readLinkedList(ptr);

    return 0;
}

void readLinkedList(Node *ptr)
{
    Node *pr = ptr;
    printf("[");
    while (pr != NULL)
    {
        printf("%d", pr->data);
        printf((pr->next) ? ", " : "");
        pr = pr->next;
    }
    printf("]\n");
}