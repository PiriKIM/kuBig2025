#include "list.h"

int main()
{
    LinkedList list1;
    // initList();

    list1.insertFirstNode(4);    // [4]
    list1.printList();

    list1.insertFirstNode(3);    // [3, 4]
    list1.printList();

    list1.insertFirstNode(1);    // [1, 3, 4]
    list1.printList();

    list1.insertNode(1, 2);      // [1, 2, 3, 4]
    list1.printList();

    list1.insertNode(3, 5);      // [1, 2, 3, 5, 4]
    list1.printList();

    list1.deleteNode(5);         // [1, 2, 3, 4];
    list1.printList();

    // cleanupList();

    return 0;
}