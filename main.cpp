#include <iostream>
#include "Array/Array.h"

int main(void)
{
    Array<char> array = Array<char>();

    array.Add('A');
    array.Add('B');
    array.Add('C');

    array.Print();

    array.Remove(1);
    
    array.Print();

    return 0;
}