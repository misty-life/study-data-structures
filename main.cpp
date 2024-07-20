#include <iostream>

#include "1_Array/Array.h"
#include "2_DoubleLinkedList/DoubleLinkedList.h"
#include "3_Stack/Stack.h"
#include "4_Queue/Queue.h"
#include "4_Queue/Dequeue.h"

int main(void)
{
    Dequeue<int> dq = Dequeue<int>();

    dq.Append(1);
    dq.Append(2);
    dq.Append(3);

    dq.Print();

    dq.Prepend(4);
    dq.Prepend(5);
    dq.Prepend(6);

    dq.Print();

    dq.Pop();
    dq.Pop();
    dq.Print();

    dq.PopFront();
    dq.PopFront();
    dq.Print();

    dq.PopFront();
    dq.Print();

    dq.PopFront();
    dq.Print();

    dq.PopFront();
    dq.Print();


    return 0;
}