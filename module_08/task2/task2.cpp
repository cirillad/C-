#include <iostream>

using namespace std;

int main()
{

	//task1

	//const int SIZE = 10;
	//int array[SIZE];

	//srand(time(nullptr));

	//for (int i = 0; i < SIZE; ++i) {
	//	array[i] = rand() % 100;
	//}

	//int min_element = array[0], max_element = array[0];
	//for (int i = 1; i < SIZE; ++i) {
	//	if (array[i] < min_element) {
	//		min_element = array[i];
	//	}
	//	if (array[i] > max_element) {
	//		max_element = array[i];
	//	}
	//}

	//cout << "Array: ";
	//for (int i = 0; i < SIZE; ++i) {
	//	cout << array[i] << " ";
	//}
	//cout << endl;

	//cout << "Minimum element: " << min_element << endl;
	//cout << "Maximum element: " << max_element << endl;


	//task2

	//int list1[12];
	//int total = 0;
	//int start, finish;

	//for (size_t i = 0; i < 12; i++)
	//{
	//	cout << "Enter the " << i + 1 << " num : ";
	//	cin >> list1[i];
	//}

	//cout << "Enter start : " << endl;
	//cin >> start;

	//cout << "Enter finish : " << endl;
	//cin >> finish;

	//int max_profit = list1[start - 1];
	//int min_profit = list1[start - 1];

	//for (size_t i = start; i <= finish; i++)
	//{
	//	if (list1[i - 1] > max_profit)
	//	{
	//		max_profit = list1[i - 1];
	//	}
	//	if (list1[i - 1] < min_profit)
	//	{
	//		min_profit = list1[i - 1];
	//	}
	//}

	//for (int i = 0; i < 12; ++i) {
	//	cout << list1[i] << " ";
	//}
	//cout << endl;
	//cout << "Min : " << min_profit << endl;
	//cout << "Max" << max_profit << endl;


	//task3


	//task1

	const int SIZE = 10;
	double array[SIZE] = { -5, -10, 1, 1, 1.5, 5.5, 33, -6, 99, 10 };

	//double min_num = array[0];
	//
	//for (size_t i = 1; i < 10; i++)
	//{
	//	if (array[i] < 0)
	//	{
	//		min_num += array[i];
	//	}
	//}

	//cout << min_num;


	//task2

	//int min_i = 0;
	//int max_i = 0;
	//double min_num = array[0];
	//double max_num = array[0];
	//double result = 1;

	//for (size_t i = 1; i < SIZE; i++)
	//{
	//	if (array[i] < min_num)
	//	{
	//		min_num = array[i];
	//		min_i = i;
	//	}
	//}

	//for (size_t i = 1; i < SIZE; i++)
	//{
	//	if (array[i] > max_num)
	//	{
	//		max_num = array[i];
	//		max_i = i;
	//	}
	//}

	//for (size_t i = min_i; i < max_i + 1; i++)
	//{
	//	result *= array[i];
	//}

	//cout << result;


	//task3

	//double result = 1;

	//for (int i = 2; i < SIZE; i += 2) {
	//	result *= array[i];
	//}

	//cout << result;


	//task4

	double result = 0;
	int first_num = 0;
	int last_num = 0;

	for (size_t i = 0; i < SIZE; i++)
	{
		if (array[i] < 0)
		{
			first_num = i;
			break;
		}
	}

	for (size_t i = SIZE - 1; i > 0; i--)
	{
		if (array[i] < 0)
		{
			last_num = i;
			break;
		}
	}

	for (size_t i = first_num + 1; i < last_num; i++)
	{
		result += array[i];
	}

	cout << result;


}
