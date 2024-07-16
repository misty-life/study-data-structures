#include <iostream>
#include "Array/Array.h"

int main(void)
{
    Array array = Array();

    array.Add(3);
    array.Add(2);
    array.Add(4);
    array.Add(4);
    array.Add(2);

    array.Print();

    array.Remove(5);
    
    array.Print();

    return 0;
}