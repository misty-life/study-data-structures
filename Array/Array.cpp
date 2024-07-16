#include <iostream>
#include "Array.h"

Array::Array() {
    array = new int;
    length = 0;
}

Array::~Array() {
    delete [] array;
}

void Array::Add(const int data) {
    int* newArray = new int[length + 1];
    for (unsigned int i = 0; i < length; ++i) {
        newArray[i] = array[i];
    }
    newArray[length] = data;
    ++length;

    delete[] array;
    array = newArray;
}

Array Array::Index(const int data) {
    Array indexArray = Array();

    for (unsigned int i = 0; i < length; ++i) {
        if (array[i] == data) {
            indexArray.Add(i);
        }
    }

    return indexArray;
}

void Array::Remove(const int index) {
    if (index < 0 || index > length - 1) return;

    int* newArray = new int[length - 1];
    
    for (unsigned int i = 0; i < index; ++i) {
        newArray[i] = array[i];
    }
    for (unsigned int i = index; i < length; ++i) {
        newArray[i] = array[i + 1];
    }

    --length;
    delete [] array;
    array = newArray;
}

void Array::Print() {
    for (unsigned int i = 0; i < length; ++i) {
        std::cout << i << " : " << array[i] << std::endl;
    }
}

int Array::Length() {
    return length;
}