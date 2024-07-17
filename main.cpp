#include <iostream>
#include "Array/Array.h"
#include "DoubleLinkedList/DoubleLinkedList.h"

int main(void)
{
    DoubleLinkedList list = DoubleLinkedList();

    list.Append(0);
    list.Append(1);
    list.Append(2);

    list.Insert(3, 5);

    list.Print();

    return 0;
}