
// Declaration
template <typename T> class Stack {
private:
    T *stack;
    int top;
    int size;

public:
    Stack();

    void Push(const T data);
    T Pop();
    T Peek();
    bool IsEmpty();
    void Print();
    int Size();    
};

// Definition
template <typename T> Stack<T>::Stack() {
    top = -1;
    size = 1;
    stack = new T[1];
}

template <typename T> void Stack<T>::Push(const T data) {
    stack[++top] = data;

    if (top == size - 1) {
        T* newStack = new T[size * 2];
        for (unsigned int i = 0; i < size; ++i) {
            newStack[i] = stack[i];
        }
        delete [] stack;
        stack = newStack;
        size *= 2;
    }
}

template <typename T> T Stack<T>::Pop() {
    T poppedData = stack[top];
    --top;
    return poppedData;
}

template <typename T> T Stack<T>::Peek() {
    return stack[top];
}

template <typename T> bool Stack<T>::IsEmpty() {
    return top == -1;
}

template <typename T> void Stack<T>::Print() {
    if (IsEmpty()) return;
    
    for (int i = top; i >= 0; --i) {
        std::cout << stack[i] << std::endl;
    }
}

template <typename T> int Stack<T>::Size() {
    return size;
}