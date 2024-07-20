#include <iostream>

#include "1_Array/Array.h"
#include "2_DoubleLinkedList/DoubleLinkedList.h"
#include "3_Stack/Stack.h"
#include "4_Queue/Queue.h"

int main(void)
{
    Queue<int> q = Queue<int>();

    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Print();

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    q.Dequeue();
    q.Print();

    return 0;
}