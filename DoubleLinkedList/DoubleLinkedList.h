
// Node Declaration
template <typename T> class Node {
public:
    T data;
    Node* prev;
    Node* next;

    Node();
    Node(const T initData);
};


// Double Linked List Declaration
template <typename T> class DoubleLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    DoubleLinkedList();

    void Append(const T data);
    void Prepend(const T data);
    T Pop();
    T PopFront();
    void Insert(const int index, const T data);
    T RemoveAt(const int index);
    DoubleLinkedList Index(const T data);
    void Print();
    int Length();
};


// Node Definition
template <typename T> Node<T>::Node() {}

template <typename T> Node<T>::Node(const T initData) : data(initData) { }


// Double Linked List  Definition
template <typename T> DoubleLinkedList<T>::DoubleLinkedList() : length(0) {
    head = new Node<T>();
    tail = new Node<T>();

    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
}

template <typename T> void DoubleLinkedList<T>::Append(const T data) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *lastNode = tail->prev;
    
    newNode->prev = lastNode;
    newNode->next = tail;
    lastNode->next = newNode;
    tail->prev = newNode;
    ++length;
}

template <typename T> void DoubleLinkedList<T>::Prepend(const T data) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *firstNode = head->next;

    newNode->prev = head;
    newNode->next = firstNode;
    firstNode->prev = newNode;
    head->next = newNode;
    ++length;
}

template <typename T> T DoubleLinkedList<T>::Pop() {
    Node<T> *deletedNode = tail->prev;
    T data = deletedNode->data;

    deletedNode->prev->next = tail;
    tail->prev = deletedNode->prev;
    delete deletedNode;
    --length;

    return data;
}

template <typename T> T DoubleLinkedList<T>::PopFront() {
    Node<T> *deletedNode = head->next;
    T data = deletedNode->data;

    head->next = deletedNode->next;
    deletedNode->next->prev = head;
    delete deletedNode;
    --length;

    return data;
}

template <typename T> void DoubleLinkedList<T>::Insert(const int index, const T data) {
    if (index < 0 || index > length) throw std::out_of_range("Index range error");

    if (index == 0) {
        Prepend(data);
        return;
    }

    if (index == length) {
        Append(data);
        return;
    }

    Node<T> *newNode = new Node<T>(data);
    Node<T> *originNode = head->next;
    for (unsigned int i = 0; i < index; ++i) {
        originNode = originNode->next;
    }

    newNode->prev = originNode->prev;
    newNode->next = originNode;
    newNode->prev->next = newNode;
    originNode->prev = newNode;
    ++length;
}

template <typename T> T DoubleLinkedList<T>::RemoveAt(const int index) {
    Node<T> *deleteNode = head->next;
    T data = deleteNode->data;

    for (unsigned int i = 0; i < index; ++i) deleteNode = deleteNode->next;

    deleteNode->prev->next = deleteNode->next;
    deleteNode->next->prev = deleteNode->prev;
    delete deleteNode;
    --length;

    return data;
}

template <typename T> DoubleLinkedList<T> DoubleLinkedList<T>::Index(const T data) {
    DoubleLinkedList<T> indexList = DoubleLinkedList<T>();
    Node<T> *currentNode = head->next;

    for (unsigned int i = 0; i < length; ++i) {
        if (currentNode->data == data) indexList.Append(i);
        currentNode = currentNode->next;
    }

    return indexList;
}

template <typename T> void DoubleLinkedList<T>::Print() {
    Node<T> *currentNdoe = head->next;
    while (currentNdoe != tail) {
        std::cout << currentNdoe->data;
        
        if (currentNdoe != tail->prev) std::cout << " > ";
        else std::cout << std::endl;

        currentNdoe = currentNdoe->next;
    }
}

template <typename T> int DoubleLinkedList<T>::Length() {
    return length;
}