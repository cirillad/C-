#include <iostream>

using namespace std;

int main()
{
    float hours, minutes, seconds, time, price;

    cout << "Enter the hours : " << endl;

    cin >> hours;

    cout << "Enter the minutes : " << endl;

    cin >> minutes;

    cout << "Enter the seconds : " << endl;

    cin >> seconds;

    if (minutes >= 60 || seconds >= 60 || minutes < 0 || seconds < 0)
    {
        cout << "Invalid input for minutes or seconds. Please enter valid values between 0 and 59." << endl;
        return 1;
    }

    time = minutes + (hours * 60) + (seconds / 60);

    price = time * 2;

    cout << "Final price : " << price;


}
