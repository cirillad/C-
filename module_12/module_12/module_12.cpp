#include <iostream>
#include <iomanip>
#include <algorithm>  
#include <string>
#define SIZE 5

using namespace std;

//task1

//template<typename T>
//void initialize_arr(T arr[SIZE][SIZE], int size)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        for (size_t j = 0; j < size; j++)
//        {
//            arr[i][j] = (rand() % 100);
//        }
//    }
//}
//
//template<typename T>
//void show_arr(T arr[SIZE][SIZE], int size)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        for (size_t j = 0; j < size; j++)
//        {
//            cout << setw(5) << arr[i][j];
//        }
//        cout << endl;
//    }
//}
//
//template<typename t>
//void min_max_arr(t arr[SIZE][SIZE], int size)
//{
//    t min = arr[0][0];
//    t max = arr[0][0];
//    
//    for (size_t i = 0; i < size; i++)
//    {
//        for (size_t j = 0; j < size; j++)
//        {
//            if (i == j)
//            {
//                if (arr[i][j] < min)
//                {
//                    min = arr[i][j];
//                }
//                if (arr[i][j] > max)
//                {
//                    max = arr[i][j];
//                }
//            }
//        }
//    }
//
//    cout << "min : " << min << endl;
//    cout << "max : " << max << endl;
//}
//
//template<typename T>
//void sort_arr(T arr[SIZE][SIZE], int size)
//{
//    for (size_t i = 0; i < size; i++)
//    {
//        sort(arr[i], arr[i] + size);
//    }
//}


//task2

//int gcd(int a, int b) {
//    if (b == 0) {
//        return a;
//    }
//    else {
//        return gcd(b, a % b);
//    }
//}


//task3

string generateSecretNumber() {
    string secretNumber;
    bool isUnique[10] = { false };

    while (secretNumber.length() < 4) {
        int digit = rand() % 10;
        if (!isUnique[digit]) {
            secretNumber += to_string(digit);
            isUnique[digit] = true;
        }
    }

    return secretNumber;
}

void compareNumbers(string secretNumber, int attempts) {
    string guess;
    cout << "Enter your guess (4-digit number): ";
    cin >> guess;

    if (guess.length() != 4 || !isdigit(guess[0]) || !isdigit(guess[1]) || !isdigit(guess[2]) || !isdigit(guess[3])) {
        cout << "Please enter a valid 4-digit number." << endl;
        compareNumbers(secretNumber, attempts);
        return;
    }

    int bulls = 0, cows = 0;
    for (int i = 0; i < 4; ++i) {
        if (secretNumber[i] == guess[i]) {
            bulls++;
        }
        else if (secretNumber.find(guess[i]) != string::npos) {
            cows++;
        }
    }

    cout << "Bulls: " << cows << ", Cows: " << bulls << endl;

    if (bulls == 4) {
        cout << "Congratulations! You've guessed the number in " << attempts << " attempts." << endl;
    }
    else {
        compareNumbers(secretNumber, attempts + 1);
    }
}

int main() {
 //   task1

	//srand(time(0));
 //   int arr[SIZE][SIZE]{};
	//initialize_arr(arr, SIZE);
	//show_arr(arr, SIZE);
 //   min_max_arr(arr, SIZE);
 //   sort_arr(arr, SIZE);
 //   show_arr(arr, SIZE);

	
	//task2

    //int num1, num2;
    //cout << "Enter first number: ";
    //cin >> num1;
    //cout << "Enter second number: ";
    //cin >> num2;

    //int result = gcd(num1, num2);
    //cout << "GCD of " << num1 << " and " << num2 << " is " << result << endl;

    //return 0;


    //task3

    srand(time(0));
    string secretNumber = generateSecretNumber();
    cout << "Welcome to the Bulls and Cows game! Try to guess the 4-digit number." << endl;
    compareNumbers(secretNumber, 1);
    return 0;



}
