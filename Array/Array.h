class Array {
private:
    int *array;
    int length;

public:
    Array();
    ~Array();

    void Add(const int data);
    Array Index(const int data);
    void Remove(const int index);
    void Print();
    int Length();
};