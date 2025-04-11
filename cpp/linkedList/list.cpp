#include <cassert>
#include <iostream>
#include "list.h"

LinkedList::Node::Node(int data, LinkedList::Node *next)
{
    this->data = data;
    this->next = next;
}

LinkedList::LinkedList()
{
    // pList->ptr = createNode(-1, NULL);
    this->ptr = new Node(-1, nullptr);     // first node = dummy node.
}

LinkedList::~LinkedList()
{
    Node *node = this->ptr;
    while (node != nullptr)
    {
        Node *tmp = node;
        node = node->next;
        // free(tmp);
        delete tmp;
    }
}

void LinkedList::insertFirstNode(int data)
{
    this->ptr->next = new Node(data, this->ptr->next);
}

void LinkedList::insertNode(int prevData, int data)
{
    Node *node = this->ptr->next;
    while (node != nullptr)
    {
        if (node->data == prevData)
            break;

        node = node->next;
    }

    if (node != nullptr)
    {
        node->next = new Node(data, node->next);
    }
}

void LinkedList::deleteNode(int data)
{
    Node *node1 = this->ptr->next;
    Node *node2 = this->ptr;
    while (node1 != nullptr)
    {
        if (node1->data == data)
            break;

            node1 = node1->next;
            node2 = node2->next;
    }

    if (node1 != nullptr)
    {
        node2->next = node1->next;
        // free(node1);
        delete node1;
    }
}

void LinkedList::printList()
{
    Node *node = this->ptr->next;
    std::cout << "[";
    while (node != nullptr)
    {
        // printf("%d", node->data);
        // printf((node->next != nullptr) ? ", " : "");
        std::cout << node->data;
        std::cout << ((node->next != nullptr) ? ", " : "");
        node = node->next;
    }
    std::cout << "]" << std::endl;
}