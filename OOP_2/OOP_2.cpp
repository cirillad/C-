#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    static int count;
    char* data;
    size_t length;

public:
    MyString() {
        length = 80;
        data = new char[length + 1];
        count++;
    }

    MyString(size_t size) {
        length = size;
        data = new char[length + 1];
        count++;
    }

    MyString(const char* str) {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
        count++;
    }

    ~MyString() {
        delete[] data;
        count--;
    }

    void input() {
        cout << "Enter a string: ";
        cin.getline(data, length + 1);
    }

    void display() {
        cout << "String: " << data << endl;
    }

    static int getCount() {
        return count;
    }
};

int MyString::count = 0;

int main() {
    
    MyString str1;
    str1.input();
    str1.display();

    MyString str2(100);
    str2.input();
    str2.display();

    MyString str3("Hello, world!");
    str3.display();

    cout << "Number of String objects created: " << MyString::getCount() << endl;

    return 0;
}
