#include <iostream>
#include <stdexcept>

using namespace std;

class NegativeNumberException : public exception {
public:
	const char* what() const noexcept override {
		return "Введене число є негативним";
	}
};

class MyClass {
public:
	MyClass() {
		throw runtime_error("Exception from MyClass constructor");
	}
};

class CustomException {
private:
	int errorCode;
	string message;

public:
	CustomException(int code, const string& msg) : errorCode(code), message(msg) {}

	int getErrorCode() const {
		return errorCode;
	}

	string getMessage() const {
		return message;
	}
};

void process(int value) {
	if (value < 0) {
		throw CustomException(1001, "Negative value");
	}
	cout << value << endl;
}

void checkArrayAccess(int arr[], int size, int index) {
	if (index >= size) {
		throw out_of_range("Out of range");
	}
	cout << arr[index] << endl;
}

void divide(int a, int b) {
	if (b == 0) {
		throw runtime_error("Division by zero");
	}
	cout << "Result: " << a << " / " << b << " = " << a / b << endl;
}


void rethrowing() {
	try {
		throw runtime_error(":(");
	}
	catch (const exception& e) {
		throw;
	}
}

int main()
{
	//int a, b;

	//try {
	//	cout << "Enter a and b with the help of 'Enter': " << endl;
	//	cin >> a >> b;

	//	divide(a, b);
	//}
	//catch (const runtime_error& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//=================================

	//2

	//try 
	//{
	//	int input;

	//	cout << "Enter the positive number : ";
	//	cin >> input;
	//	process(input);
	//}
	//catch (const CustomException& e) {
	//	cout << "ERROR: " << e.getErrorCode() << " - " << e.getMessage() << endl;
	//}

	//=================================

	//3

	//int arr[3]{ 1,2,3 };
	//int a = 4;

	//try
	//{
	//	checkArrayAccess(arr, sizeof(arr) / sizeof(arr[0]), a);
	//}
	//catch (const exception& e)
	//{
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//=================================

	//4

	//int a, b, index;
	//int arr[3]{ 1,2,3 };

	//try 
	//{
	//	try
	//	{
	//		cout << "Enter a and b with the help of 'Enter': " << endl;
	//		cin >> a >> b;
	//		divide(a, b);

	//		cout << "Enter the index : " << endl;
	//		cin >> index;
	//		checkArrayAccess(arr, sizeof(arr) / sizeof(arr[0]), index);
	//	}
	//	catch (const exception& e)
	//	{
	//		cout << "ERROR: " << e.what() << endl;
	//	}
	//}
	//catch (const runtime_error& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//=================================

	//5

	//try {
	//	size_t size = 1000000000000;
	//	int* bigArray = new int[size];

	//	for (size_t i = 0; i < size; ++i) {
	//		bigArray[i] = i;
	//	}

	//	throw exception("ERROR");

	//	delete[] bigArray;
	//	cout << "Memory allocation successful" << endl;
	//}
	//catch (const exception&) {
	//	cerr << "Memory allocation failed" << endl;
	//}

	//на практиці не перевіряв, страшно

	//=================================

	//6

	//try {
	//	MyClass userClass;
	//}
	//catch (const runtime_error& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//=================================

	//7

	//try {
	//	rethrowing();
	//}
	//catch (const exception& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//=================================

	//8

	//try {
	//	divide(10, 2);
	//	divide(8, 0);
	//	divide(6, 3);
	//}
	//catch (const runtime_error& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//не зовсім зрозусів завдання 

	//=================================

	//9

	//int a, b;

	//try {
	//	cout << "Enter a and b with the help of 'Enter': " << endl;
	//	cin >> a >> b;

	//	divide(a, b);
	//}
	//catch (const runtime_error& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}
	//catch (const out_of_range& e) {
	//	cout << "ERROR: " << e.what() << endl;
	//}

	//=================================

	//10

	try {
		int input;

		cout << "Enter the positive number : ";
		cin >> input;
		process(input);
	}
	catch (const CustomException& e) {
		cout << "ERROR: " << e.getErrorCode() << " - " << e.getMessage() << endl;
	}
}