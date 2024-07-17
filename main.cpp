#include <iostream>
#include "Array/Array.h"

int main(void)
{
    Array<char> array = Array<char>();

    array.Add('A');
    array.Add('B');
    array.Add('C');

    array.Print();

    std::cout << array[3] << std::endl;

    array.Remove(1);
    
    array.Print();

    return 0;
}