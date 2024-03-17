#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

//task1

//void degree_equation(int num, int degree)
//{
//    int result = 1;
//
//    for (size_t i = 0; i < degree; i++)
//    {
//        result *= num;
//    }
//
//    cout << result << endl;
//}


//task2

//void sum_of_diapazon(int start, int finish)
//{
//    int result = 0;
//
//    for (size_t i = start + 1; i < finish; i++)
//    {
//        result += i;
//    }
//
//    cout << result;
//}


//task3

//int sumOfDivisors(int n) {
//    int sum = 0;
//    for (int i = 1; i < n; ++i) {
//        if (n % i == 0) {
//            sum += i;
//        }
//    }
//    return sum;
//}
//
//void ideal_num(int start, int end)
//{
//    cout << "Ideal nums [" << start << ", " << end << "]:" << endl;
//    for (int num = start; num <= end; ++num) {
//        if (sumOfDivisors(num) == num) {
//            cout << num << endl;
//        }
//    }
//}

//task4

//void printCard(char value, char suit) {
//    string cardValue;
//
//    switch (value) {
//    case '2': cardValue = "2"; break;
//    case '3': cardValue = "3"; break;
//    case '4': cardValue = "4"; break;
//    case '5': cardValue = "5"; break;
//    case '6': cardValue = "6"; break;
//    case '7': cardValue = "7"; break;
//    case '8': cardValue = "8"; break;
//    case '9': cardValue = "9"; break;
//    case 'T': cardValue = "10"; break;
//    case 'J': cardValue = "Jack"; break;
//    case 'Q': cardValue = "Queen"; break;
//    case 'K': cardValue = "King"; break;
//    case 'A': cardValue = "Ace"; break;
//    default: cardValue = "Invalid value";
//    }
//
//    string cardSuit;
//
//    switch (suit) {
//    case 'S': cardSuit = "Spades"; break;
//    case 'H': cardSuit = "Hearts"; break;
//    case 'D': cardSuit = "Diamonds"; break;
//    case 'C': cardSuit = "Clubs"; break;
//    default: cardSuit = "Invalid suit";
//    }
//
//    cout << "Your card is: " << cardValue << " of " << cardSuit << endl;
//}


//task5

//void lucky_num(int num)
//{
//    string str_num = to_string(num);
//
//    int firstHalfSum = 0;
//    for (int i = 0; i < 3; ++i) {
//        firstHalfSum += str_num[i] - '0';
//    }
//
//    int secondHalfSum = 0;
//    for (int i = 3; i < 6; ++i) {
//        secondHalfSum += str_num[i] - '0';
//    }
//
//    if (firstHalfSum == secondHalfSum)
//    {
//        cout << "It is lucky num!!";
//    }
//    else
//    {
//        cout << "It is not lucky num :(";
//    }
//}


//task2.1

//void line_search(int arr[], int size, int key)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        if (arr[i] == key)
//        {
//            cout << "arr[" << i << "]" << endl;
//        }
//    }
//}
//
//void show_arr(int arr[], int size)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        cout << arr[i] << ",  ";
//    }
//    cout << endl;
//}


//task2.2

//void show_arr(int arr[], int size)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        cout << arr[i] << ",  ";
//    }
//    cout << endl;
//}
//
//void binary_search(int arr[], int size, int key)
//{
//    int left = 0, right = size - 1, mid;
//
//    while (right >= left)
//    {
//        mid = left + (right - left) / 2;
//
//        if (arr[mid] == key)
//        {
//            cout << "Key found at index " << mid << endl;
//            return;
//        }
//        else if (arr[mid] < key)
//        {
//            left = mid + 1;
//        }
//        else
//        {
//            right = mid - 1;
//        }
//    }
//}


//task2.3

int binary_to_decimal(string binary) {
    int decimal = 0;
    int power = 0;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += pow(2, power);
        }
        power++;
    }

    return decimal;
}



int main()
{
    //task1

    //int num, degree_num;

    //cout << "Enter the number : " << endl;
    //cin >> num;

    //cout << "Enter the degree equation : " << endl;
    //cin >> degree_num;

    //degree_equation(num, degree_num);


    //task2

    //int first_num, second_num;

    //cout << "Enter the initial number : " << endl;
    //cin >> first_num;

    //cout << "Enter the last number : " << endl;
    //cin >> second_num;

    //sum_of_diapazon(first_num, second_num);


    //task3

    //int start = 1, finish = 500;

    //ideal_num(start, finish);


    //task4

 /*   char value, suit;

    cout << "Enter the value of the card (2-9, T, J, Q, K, A): ";
    cin >> value;
    cout << "Enter the suit of the card (S, H, D, C): ";
    cin >> suit;

    printCard(value, suit);*/



    //task5

    //int number;

    //cout << "Enter the number : " << endl;
    //cin >> number;

    //lucky_num(number);


    //task2.1

    //const int SIZE = 10;
    //int arr[SIZE]{ 1, 4, 2, 5, 3, 0, 9 , 8 , 7, 6 };
    //int key;
    //
    //show_arr(arr, SIZE);

    //cout << "Enter the key : " << endl;
    //cin >> key;

    //line_search(arr, SIZE, key);


    //task2.2

    //const int SIZE = 10;
    //int arr[SIZE]{ 1, 4, 2, 5, 3, 0, 9 , 8 , 7, 6 };
    //int key;

    //show_arr(arr, SIZE);

    //sort(arr, arr + SIZE);

    //show_arr(arr, SIZE);

    //cout << "Enter the key : " << endl;
    //cin >> key;

    //binary_search(arr, SIZE, key);


    //task2.3

    string binary_number;
    cout << "Enter a binary number: ";
    cin >> binary_number;

    int decimal_number = binary_to_decimal(binary_number);

    cout << "Decimal equivalent: " << decimal_number << endl;

}