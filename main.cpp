#include <iostream>
#include "Array/Array.h"
#include "DoubleLinkedList/DoubleLinkedList.h"

int main(void)
{
    DoubleLinkedList<char> list = DoubleLinkedList<char>();

    list.Append('a');
    list.Append('b');
    list.Append('c');

    list.Insert(1, 'd');

    list.Print();

    return 0;
}