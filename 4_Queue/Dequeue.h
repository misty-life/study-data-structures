#include <iostream>
#include "../Base/Node.h"

// Dequeue Declaration
template <typename T> class Dequeue {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    Dequeue();
    void Append(const T data);
    void Prepend(const T data);
    T Pop();
    T PopFront();
    bool IsEmpty();
    int Size();
    void Print();
};


// Dequeue Definition
template <typename T> Dequeue<T>::Dequeue() : size(0) {
    front = new Node<T>();
    rear = new Node<T>();
    
    front->next = rear;
    rear->prev = front;
}

template <typename T> void Dequeue<T>::Append(const T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->prev = rear->prev;
    newNode->next = rear;
    rear->prev->next = newNode;
    rear->prev = newNode;
    ++size;
}

template <typename T> void Dequeue<T>::Prepend(const T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->prev = front;
    newNode->next = front->next;
    front->next->prev = newNode;
    front->next = newNode;
    ++size;
}

template <typename T> T Dequeue<T>::Pop() {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");

    Node<T> *deletedNode = rear->prev;
    deletedNode->prev->next = rear;
    rear->prev = deletedNode->prev;
    delete deletedNode;
    --size;;
}

template <typename T> T Dequeue<T>::PopFront() {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");

    Node<T> *deletedNode = front->next;
    front->next = deletedNode->next;
    deletedNode->next->prev = front;
    delete deletedNode;
    --size;;
}

template <typename T> bool Dequeue<T>::IsEmpty() {
    return size == 0;
}

template <typename T> int Dequeue<T>::Size() {
    return size;
}

template <typename T> void Dequeue<T>::Print() {
    Node<T> *currentNdoe = front->next;
    while (currentNdoe != rear) {
        std::cout << currentNdoe->data;
        
        if (currentNdoe != rear->prev) std::cout << " - ";
        else std::cout << std::endl;

        currentNdoe = currentNdoe->next;
    }
}