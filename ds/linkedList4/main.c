#include <stdio.h>
#include "list.h"

void printChar(const void *pData)
{
    printf("%c", *(char *)pData);
}

void printInt(const void *pData)
{
    printf("%d", *(int *)pData);
}

void printDouble(const void *pData)
{
    printf("%f", *(double *)pData);
}

int main(void)
{
    List list1, list2, list3;
    initList(&list1, sizeof(int));
    initList(&list2, sizeof(double));
    initList(&list3, sizeof(char));

    int i;
    i = 4;      insertFirstNode(&list1, &i);  // [4]
    i = 3;      insertFirstNode(&list1, &i);  // [3, 4]
    i = 1;      insertFirstNode(&list1, &i);  // [1, 3, 4]

    int j = 1;
    i = 2;      insertNode(&list1, &j, &i);   // [1, 2, 3, 4]
    i = 3;      deleteNode(&list1, &i);       // [1, 2, 4]
    printList(&list1, printInt);

    double d;
    d = 4.4;      insertFirstNode(&list2, &d);  // [4.4]
    d = 3.3;      insertFirstNode(&list2, &d);  // [3.3, 4.4]
    d = 1.1;      insertFirstNode(&list2, &d);  // [1.1, 3.3, 4.4]

    double f = 1.1;
    d = 2.2;      insertNode(&list2, &f, &d);   // [1.1, 2.2, 3.3, 4.4]
    d = 3.3;      deleteNode(&list2, &d);       // [1.1, 2.2, 4.4]
    printList(&list2, printDouble);

    char c;
    c = 'P';      insertFirstNode(&list3, &c);  // [4.4]
    c = 'd';      insertFirstNode(&list3, &c);  // [3.3, 4.4]
    c = 'K';      insertFirstNode(&list3, &c);  // [1.1, 3.3, 4.4]

    char h = 'K';
    c = 'D';      insertNode(&list3, &h, &c);   // [1.1, 2.2, 3.3, 4.4]
    c = 'd';      deleteNode(&list3, &c);       // [1.1, 2.2, 4.4]
    printList(&list3, printChar);

    cleanupList(&list1);
    cleanupList(&list2);
    cleanupList(&list3);

    return 0;
}