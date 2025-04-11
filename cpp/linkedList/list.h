#ifndef LIST_H
#define LIST_H

class LinkedList
{
private:
    class Node
    {
    public:
        int data;
        Node *next;
        
        Node(int data, Node *next);
    };

    Node *ptr;

public:
    LinkedList();
    ~LinkedList();

    void insertFirstNode(int data);
    void insertNode(int prevData, int data);
    void deleteNode(int data);

    void printList();
};

#endif