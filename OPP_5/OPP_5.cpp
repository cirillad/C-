#include <iostream>

using namespace std;

template<typename T>
class Array {
private:
    T* data;
    int size; 
    int capacity; 
    int grow; 

    void Resize(int newSize) {
        if (newSize <= capacity) return;

        int newCapacity = capacity + grow;
        while (newCapacity < newSize) {
            newCapacity += grow;
        }

        T* newData = new T[newCapacity];

        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }

        delete[] data;

        data = newData;
        capacity = newCapacity;
    }

public:
    Array() : size(0), capacity(0), grow(1), data(nullptr) {}

    Array(int initialSize, int initialCapacity, int growth) : size(initialSize), capacity(initialCapacity), grow(growth) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    int GetSize() const {return size}

    int GetUpperBound() const { return size - 1; }

    bool IsEmpty() const { return size == 0; }

    void FreeExtra() { if (size < capacity) capacity = size; }

    void RemoveAll() { delete[] data; size = 0; capacity = 0; data = nullptr; }

    T GetAt(int index) { return data[index] }

    void SetAt(int index, const T& value) { data[index] = value }

    T& operator[](int index) { return data[index] }

    T* GetData() { return data; }

    void Add(const T& value) {
        Resize(size + 1);
        data[size++] = value;
    }

    void Append(const Array<T>& other) {
        int newSize = size + other.GetSize();
        Resize(newSize);
        for (int i = 0; i < other.GetSize(); ++i) {
            data[size++] = other[i];
        }
    }

    Array<T>& operator=(const Array<T>& other) {
        if (this == &other) return *this;

        delete[] data;

        size = other.GetSize();
        capacity = other.capacity;
        data = new T[capacity];
        for (int i = 0; i < size; ++i) {
            data[i] = other[i];
        }

        return *this;
    }

    void InsertAt(int index, const T& value) {
        if (index < 0 || index > size) {
            cerr << "Error: Index out of range" << endl;
            exit(EXIT_FAILURE);
        }
        Resize(size + 1);
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        size++;
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= size) {
            cerr << "Error: Index out of range" << endl;
            exit(EXIT_FAILURE);
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        size--;
    }


};

int main()
{
    Array<int> arr(5, 10, 5);

    for (int i = 0; i < 10; ++i) {
        arr.Add(i * 10);
    }

    cout << "Size of the array: " << arr.GetSize() << endl;

    cout << "Elements of the array: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    arr.InsertAt(3, 999);

    cout << "Size of the array after insertion: " << arr.GetSize() << endl;

    cout << "Elements of the array after insertion: ";
    for (int i = 0; i < arr.GetSize(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
