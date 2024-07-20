#include <iostream>

// Declaration
template <typename T> class Array {
private:
    T *array;
    int length;

public:
    Array();
    ~Array();

    T operator[](int index);

    void Add(const T data);
    Array<int> Index(const T data);
    void Remove(const int index);
    void Print();
    int Length();
};


// Definition
template <typename T> Array<T>::Array() {
    array = new T;
    length = 0;
}

template <typename T> Array<T>::~Array() {
    delete [] array;
}

template <typename T> T Array<T>::operator[](int index) {
    if (index < 0 || index > length - 1) throw std::out_of_range("Index range error");
    
    return array[index];
}

template <typename T> void Array<T>::Add(const T data) {
    T* newArray = new T[length + 1];
    for (unsigned int i = 0; i < length; ++i) {
        newArray[i] = array[i];
    }
    newArray[length] = data;
    ++length;

    delete[] array;
    array = newArray;
}

template <typename T> Array<int> Array<T>::Index(const T data) {
    Array<T> indexArray = Array<T>();

    for (unsigned int i = 0; i < length; ++i) {
        if (array[i] == data) {
            indexArray.Add(i);
        }
    }

    return indexArray;
}

template <typename T> void Array<T>::Remove(const int index) {
    if (index < 0 || index > length - 1) return;

    T* newArray = new T[length - 1];
    
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

template <typename T> void Array<T>::Print() {
    for (unsigned int i = 0; i < length; ++i) {
        std::cout << i << " : " << array[i] << std::endl;
    }
}

template <typename T> int Array<T>::Length() {
    return length;
}