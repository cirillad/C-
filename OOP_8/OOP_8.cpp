#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;

    Node() : value(0), next(nullptr) {}

    Node(int value, Node* next) : value{ value }, next{ next } {}
};

class Stack {
    Node* top;
    int size;
    int capacity;

public:
    Stack(int capacity = 10) : top(nullptr), size(0), capacity(capacity) {}

    bool isEmpty() const {
        return size == 0;
    }

    void Push(int value) {
        if (size == capacity)
        {
            capacity *= 2;
            Node* newStack = new Node[capacity];
            Node* current = top;
            int i = 0;

            while (current != nullptr)
            {
                newStack[i].value = current->value;
                current = current->next;
                i++;
            }

            delete[] top;
            top = newStack;
        }

        Node* newNode = new Node(value, top);
        top = newNode;
        size++;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack is empty.";
            return -1;
        }

        Node* current = top;
        top = current->next;
        int poppedValue = current->value;
        delete current;
        size--;
        return poppedValue;
    }

    void printStack() {
        if (isEmpty())
        {
            cout << "Stack is empty.";
            return;
        }

        Node* current = top;

        while (current != nullptr)
        {
            cout << current->value << " ";
            current = current->next;
        }

        cout << endl;
    }

    Stack* clone() const {
        Stack* clonedStack = new Stack();
        Node* current = top;

        while (current != nullptr) {
            clonedStack->Push(current->value);
            current = current->next;
        }

        return clonedStack;
    }


    Stack* operator+(const Stack& other) const {
        Stack* combinedStack = this->clone();
        Node* current = other.top;

        while (current != nullptr) {
            combinedStack->Push(current->value);
            current = current->next;
        }

        return combinedStack;
    }

    Stack* operator*(const Stack& other) const {
        Stack* commonStack = new Stack();
        Node* current = top;

        while (current != nullptr) {
            Node* otherCurrent = other.top;
            while (otherCurrent != nullptr) {
                if (current->value == otherCurrent->value) {
                    commonStack->Push(current->value);
                    break;
                }
                otherCurrent = otherCurrent->next;
            }
            current = current->next;
        }

        return commonStack;
    }

    int GetSize() const {
        return size;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

};

int main() {
    Stack stack1, stack2;

    stack1.Push(1);
    stack1.Push(2);
    stack1.Push(3);

    stack2.Push(2);
    stack2.Push(3);
    stack2.Push(4);

    cout << "Stack 1 size: " << stack1.GetSize() << endl;
    cout << "Stack 2 size: " << stack2.GetSize() << endl;

    Stack* clonedStack = stack1.clone();
    cout << "Clone size: " << clonedStack->GetSize() << endl;

    Stack* combinedStack = stack1 + stack2;
    cout << "Combined size: " << combinedStack->GetSize() << endl;

    Stack* commonStack = stack1 * stack2;
    cout << "Common size: " << commonStack->GetSize() << endl;

    delete clonedStack;
    delete combinedStack;
    delete commonStack;
}
