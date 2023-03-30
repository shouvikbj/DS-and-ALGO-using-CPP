// #    34, 45, 46, 67, 78, 89, 23, 34
// #    0,  1,  2,  3,  4,  5,  6,  7
// #        R   F
// #
// #    (rear + 1) % size == front)
// #    (front == 0 && rear == size-1) ||(rear == (front - 1) % (size - 1))
// #

#include <iostream>
using namespace std;

struct Queue
{
    int rear, front;
    int size;
    int *arr;

    Queue(int s)
    {
        front = rear = -1;
        size = s;
        arr = new int[s];
    }
    void enQueue(int data);
    int deQueue();
};

void Queue::enQueue(int data)
{
    if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
    {
        cout << "Queue is already full";
        return;
    }
    else if (front == -1)
    {
        front = rear = 0;
        arr[rear] = data;
    }
    else
    {
        rear++;
        arr[rear] = data;
    }
}

int Queue::deQueue()
{
    if (front == -1)
    {
        cout << "Queue is empty";
        return -1;
    }
    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size - 1)
    {
        front = 0;
    }
    else
    {
        front++;
    }
    return data;
}