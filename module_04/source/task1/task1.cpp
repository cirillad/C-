#include <iostream>

using namespace std;

int main() {
    int number;

    cout << "Enter a six-digit number: ";
    cin >> number;

    if (number < 100000 || number > 999999) {
        cout << "Error: The number must be a six-digit number." << endl;
        return 1;
    }

    int digit1 = number / 100000 % 10;
    int digit2 = number / 10000 % 10;
    int digit3 = number / 1000 % 10;
    int digit4 = number / 100 % 10;
    int digit5 = number / 10 % 10;
    int digit6 = number % 10;

    int sum_first_three = digit1 + digit2 + digit3;
    int sum_last_three = digit4 + digit5 + digit6;

    if (sum_first_three == sum_last_three) {
        cout << "The number is lucky!" << endl;
    }
    else {
        cout << "The number is not lucky." << endl;
    }
}
