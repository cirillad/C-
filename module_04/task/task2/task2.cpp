#include <iostream>
#include <string>

using namespace std;

int main()
{
	//task1

	//int start = 100, finish = 999;

	//int count = 0;

	//for (int i = start; i <= finish; i++)
	//{
	//	string num = to_string(i);

	//	char first_num = num[0];
	//	char second_num = num[1];
	//	char third_num = num[2];

	//	if (first_num == second_num || second_num == third_num || first_num == third_num)
	//	{
	//		count++;
	//	}

	//}

	//cout << count;


	//task2

	//int start = 100, finish = 999;

	//int count = 0;

	//for (int i = start; i <= finish; i++)
	//{
	//	string num = to_string(i);

	//	char first_num = num[0];
	//	char second_num = num[1];
	//	char third_num = num[2];

	//	if (first_num != second_num && first_num != third_num && second_num != third_num)
	//	{
	//		count++;
	//	}

	//}

	//cout << count;


	//task3

	//int number;

	//cout << "Enter the number : ";
	//cin >> number;

	//string numberStr = to_string(number);
	//string resultStr = "";

	//for (char digit : numberStr) {
	//	if (digit != '3' && digit != '6') {
	//		resultStr += digit;
	//	}
	//}

	//cout << "Result : " << resultStr << endl;


	//task4

	//int num;
	//cout << "Enter the number: ";
	//cin >> num;

	//int result = 0;
	//int power = 1;

	//while (num != 0) {
	//	int digit = num % 10;

	//	if (digit != 3 && digit != 6) {
	//		result += digit * power;
	//		power *= 10;
	//	}

	//	num /= 10;
	//}

	//cout << "Result: " << result << endl;


	//task5

	//int A;

	//cout << "Enter any integer number A: ";
	//cin >> A;

	//cout << "Integers B satisfying the conditions: ";

	//for (int B = 1; B <= A; ++B) {
	//	if (A % (B * B) == 0 && A % (B * B * B) != 0) {
	//		cout << B << " ";
	//	}
	//}

	//cout << endl;

	//task6

	//int num;

	//cout << "Enter the number : " << endl;
	//cin >> num;

	//cout << "Result : " << endl;

	//for (int i = 1; i <= num; i++)
	//{
	//	if (num % i == 0)
	//	{
	//		cout << i << endl;
	//	}
	//}

	//task7

	int num, num2;

	cout << "Enter the first number: " << endl;
	cin >> num;

	cout << "Enter the second number: " << endl;
	cin >> num2;

    cout << "Result: " << endl;

    for (int i = 1; i <= num; i++) {
        if (num % i == 0 && num2 % i == 0) {
            cout << i << endl;
        }
    }
}
