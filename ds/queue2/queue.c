int queue[100];
int rear;       // enqueue location
int front;      // dequeue location

void push(int data)
{
    queue[rear] = data;
    rear++;
}

int pop(void)
{
    int i = front;
    front++;
    return queue[i];
}