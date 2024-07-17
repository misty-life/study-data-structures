#include <iostream>

#include "Array/Array.h"
#include "DoubleLinkedList/DoubleLinkedList.h"
#include "Stack/Stack.h"

int main(void)
{
    Stack<int> stack = Stack<int>();

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    stack.Push(5);

    return 0;
}