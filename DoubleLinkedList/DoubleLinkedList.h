
// Node Declaration
class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(const int inotData);
};


// Double Linked List Declaration
class DoubleLinkedList {
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoubleLinkedList();

    void Append(const int data);
    void Prepend(const int data);
    int Pop();
    int PopFront();
    void Insert(const int index, const int data);
    int RemoveAt(const int index);
    DoubleLinkedList Index(const int data);
    void Print();
    int Length();
};


// Node Definition
Node::Node(const int inotData) : data(inotData) { }


// Double Linked List  Definition
DoubleLinkedList::DoubleLinkedList() : length(0) {
    head = new Node(-1);
    tail = new Node(-1);

    head->prev = nullptr;
    head->next = tail;
    tail->prev = head;
    tail->next = nullptr;
}

void DoubleLinkedList::Append(const int data) {
    Node* newNode = new Node(data);
    Node* lastNode = tail->prev;
    
    newNode->prev = lastNode;
    newNode->next = tail;
    lastNode->next = newNode;
    tail->prev = newNode;
    ++length;
}

void DoubleLinkedList::Prepend(const int data) {
    Node* newNode = new Node(data);
    Node* firstNode = head->next;

    newNode->prev = head;
    newNode->next = firstNode;
    firstNode->prev = newNode;
    head->next = newNode;
    ++length;
}

int DoubleLinkedList::Pop() {
    Node* deletedNode = tail->prev;
    int data = deletedNode->data;

    deletedNode->prev->next = tail;
    tail->prev = deletedNode->prev;
    delete deletedNode;
    --length;

    return data;
}

int DoubleLinkedList::PopFront() {
    Node* deletedNode = head->next;
    int data = deletedNode->data;

    head->next = deletedNode->next;
    deletedNode->next->prev = head;
    delete deletedNode;
    --length;

    return data;
}

void DoubleLinkedList::Insert(const int index, const int data) {
    if (index < 0 || index > length) throw std::out_of_range("Index range error");

    if (index == 0) {
        Prepend(data);
        return;
    }

    if (index == length) {
        Append(data);
        return;
    }

    Node* newNode = new Node(data);
    Node* originNode = head->next;
    for (unsigned int i = 0; i < index; ++i) {
        originNode = originNode->next;
    }

    newNode->prev = originNode->prev;
    newNode->next = originNode;
    newNode->prev->next = newNode;
    originNode->prev = newNode;
    ++length;
}

int DoubleLinkedList::RemoveAt(const int index) {
    Node* deleteNode = head->next;
    int data = deleteNode->data;

    for (unsigned int i = 0; i < index; ++i) deleteNode = deleteNode->next;

    deleteNode->prev->next = deleteNode->next;
    deleteNode->next->prev = deleteNode->prev;
    delete deleteNode;
    --length;

    return data;
}

DoubleLinkedList DoubleLinkedList::Index(const int data) {
    DoubleLinkedList indexList = DoubleLinkedList();
    Node* currentNode = head->next;

    for (unsigned int i = 0; i < length; ++i) {
        if (currentNode->data == data) indexList.Append(i);
        currentNode = currentNode->next;
    }

    return indexList;
}

void DoubleLinkedList::Print() {
    Node* currentNdoe = head->next;
    while (currentNdoe != tail) {
        std::cout << currentNdoe->data;
        
        if (currentNdoe != tail->prev) std::cout << " > ";
        else std::cout << std::endl;

        currentNdoe = currentNdoe->next;
    }
}

int DoubleLinkedList::Length() {
    return length;
}