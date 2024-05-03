#include <iostream>

using namespace std;

class DomasticAnimal
{
private:
    string name;
    string color;
    int age;

public:
    DomasticAnimal(): name(""), color(""), age(0) {}

    DomasticAnimal(string name, string color, int age): name{name}, color{color}, age{age} {}

    void Show()
    {
        cout << "Name : " << name << endl;
        cout << "Color : " << color << endl;
        cout << "Age : " << age << endl;
    }
};

class Cat : public DomasticAnimal
{
public:
    Cat(string name, string color, int age) : DomasticAnimal(name, color, age) {}
};

class Dog : public DomasticAnimal
{
public:
    Dog(string name, string color, int age) : DomasticAnimal(name, color, age) {}
};

class Parrot : public DomasticAnimal
{
public:
    Parrot(string name, string color, int age) : DomasticAnimal(name, color, age) {}
};

//=======================================================================

class String {
protected:
    char* str;
    int length;

public:
    String() {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    String(const char* s) {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }

    String(const String& other) {
        length = other.length;
        str = new char[length + 1];
        strcpy(str, other.str);
    }

    String& operator=(const String& other) {
        if (this != &other) {
            delete[] str;
            length = other.length;
            str = new char[length + 1];
            strcpy(str, other.str);
        }
        return *this;
    }

    int getLength() const {
        return length;
    }

    void clear() {
        delete[] str;
        length = 0;
        str = new char[1];
        str[0] = '\0';
    }

    ~String() {
        delete[] str;
    }

    String operator+(const String& other) const {
        String newString;
        newString.length = length + other.length;
        newString.str = new char[newString.length + 1];
        strcpy(newString.str, str);
        strcat(newString.str, other.str);
        return newString;
    }

    String& operator+=(const String& other) {
        char* temp = new char[length + other.length + 1];
        strcpy(temp, str);
        strcat(temp, other.str);
        delete[] str;
        str = temp;
        length += other.length;
        return *this;
    }

    bool operator==(const String& other) const {
        return (length == other.length) && (strcmp(str, other.str) == 0);
    }

    bool operator!=(const String& other) const {
        return !(*this == other);
    }

    friend std::ostream& operator<<(std::ostream& out, const String& s) {
        out << s.str;
        return out;
    }
};


class BitString : public String {
public:
    BitString() : String() {}

    BitString(const char* s) {
        int len = strlen(s);
        bool isValid = true;
        for (int i = 0; i < len; ++i) {
            if (s[i] != '0' && s[i] != '1') {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            length = len;
            str = new char[length + 1];
            strcpy(str, s);
        }
        else {
            length = 0;
            str = new char[1];
            str[0] = '\0';
        }
    }

    BitString(const BitString& other) : String(other) {}

    BitString& operator=(const BitString& other) {
        String::operator=(other);
        return *this;
    }

    void negate() {
        for (int i = 0; i < length; ++i) {
            if (str[i] == '0') {
                str[i] = '1';
            }
            else {
                str[i] = '0';
            }
        }
    }

    BitString operator+(const BitString& other) const {
        BitString result;
        result.length = length + other.length;
        result.str = new char[result.length + 1];
        strcpy(result.str, str);
        strcat(result.str, other.str);
        return result;
    }

    BitString& operator+=(const BitString& other) {
        *this = *this + other;
        return *this;
    }

    bool operator==(const BitString& other) const {
        return String::operator==(other);
    }

    bool operator!=(const BitString& other) const {
        return String::operator!=(other);
    }
};

int main()
{
    Cat myCat("Cat", "black", 5);
    myCat.Show();

    Dog myDog("Dog", "brown", 3);
    myDog.Show();

    Parrot myParrot("Parrot", "green", 100);
    myParrot.Show();

//=======================================================================

    String str1("Hello");
    String str2("World");

    std::cout << "str1: " << str1 << ", Length: " << str1.getLength() << std::endl;
    std::cout << "str2: " << str2 << ", Length: " << str2.getLength() << std::endl;

    String str3 = str1 + str2;
    std::cout << "str3 (str1 + str2): " << str3 << ", Length: " << str3.getLength() << std::endl;

    str1 += str2;
    std::cout << "str1 (after str1 += str2): " << str1 << ", Length: " << str1.getLength() << std::endl;

    if (str1 == str3) {
        std::cout << "str1 is equal to str3" << std::endl;
    }
    else {
        std::cout << "str1 is not equal to str3" << std::endl;
    }

    BitString bitStr1("101010");
    BitString bitStr2("110011");

    std::cout << "bitStr1: " << bitStr1 << ", Length: " << bitStr1.getLength() << std::endl;
    std::cout << "bitStr2: " << bitStr2 << ", Length: " << bitStr2.getLength() << std::endl;

    BitString bitStr3 = bitStr1 + bitStr2;
    std::cout << "bitStr3 (bitStr1 + bitStr2): " << bitStr3 << ", Length: " << bitStr3.getLength() << std::endl;

    bitStr1 += bitStr2;
    std::cout << "bitStr1 (after bitStr1 += bitStr2): " << bitStr1 << ", Length: " << bitStr1.getLength() << std::endl;

    bitStr1.negate();
    std::cout << "Negated bitStr1: " << bitStr1 << std::endl;

    if (bitStr1 != bitStr2) {
        std::cout << "bitStr1 is not equal to bitStr2" << std::endl;
    }
    else {
        std::cout << "bitStr1 is equal to bitStr2" << std::endl;
    }

}
