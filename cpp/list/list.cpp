#include <stdlib.h>
#include <assert.h>
#include "list.h"

// std::ostream& operator<<(std::ostream& out, const List& rhs)
// {
//     Node *p = rhs.ptr->next;
//     out << "[";
//     while (p)
//     {
//         out << p->data;
//         out << ((p->next) ? ", " : "");
//         p = p->next;
//     }
//     out << "]\n";
// }

void List::printList()
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

Node::Node(int data, Node *next)
{
    this->data = data;
    this->next = next;
}

List::List()
{
    this->ptr = new Node(-1, NULL);
}

List::~List()
{
    Node *p = this->ptr;
    while (p)
    {
        Node *tmp = p;
        p = p->next;
        delete tmp;
    }
}

void List::insertFirstNode(int data)
{
    this->ptr->next = new Node(data, this->ptr->next);
}

void List::insertNode(int prevData, int data)
{
    Node *p = this->ptr->next;
    while (p)
    {
        if (p->data == prevData)
            break;

        p = p->next;
    }

    if (p)
    {
        p->next = new Node(data, p->next);
    }
}

void List::deleteNode(int data)
{
    Node *p = this->ptr->next;
    Node *p2 = this->ptr;
    while (p)
    {
        if (p->data == data)
            break;

        p = p->next;
        p2 = p2->next;
    }

    if (p)
    {
        p2->next = p->next;
        delete p;
    }
}