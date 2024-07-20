#include <iostream>
#include "../Base/Node.h"

// Queue Declaration
template <typename T> class Queue {
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    Queue();
    void Enqueue(const T data);
    T Dequeue();
    bool IsEmpty();
    int Size();
    void Print();
};


// Queue Definition
template <typename T> Queue<T>::Queue() : size(0) {
    front = new Node<T>();
    rear = new Node<T>();
    
    front->next = rear;
    rear->prev = front;
}

template <typename T> void Queue<T>::Enqueue(const T data) {
    Node<T> *newNode = new Node<T>(data);
    newNode->prev = rear->prev;
    newNode->next = rear;
    rear->prev->next = newNode;
    rear->prev = newNode;
    ++size;
}

template <typename T> T Queue<T>::Dequeue() {
    if (IsEmpty()) throw std::out_of_range("Queue is empty");

    Node<T> *deletedNode = front->next;
    front->next = deletedNode->next;
    deletedNode->next->prev = front;
    delete deletedNode;
    --size;;
}

template <typename T> bool Queue<T>::IsEmpty() {
    return size == 0;
}

template <typename T> int Queue<T>::Size() {
    return size;
}

template <typename T> void Queue<T>::Print() {
    Node<T> *currentNdoe = front->next;
    while (currentNdoe != rear) {
        std::cout << currentNdoe->data;
        
        if (currentNdoe != rear->prev) std::cout << " - ";
        else std::cout << std::endl;

        currentNdoe = currentNdoe->next;
    }
}


// 원형 큐 구현

// 우선 순위 큐 구현

// Dequeue 구현