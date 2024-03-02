#include <iostream>

using namespace std;

int main()
{
    int numbers[7];
    int maxNumber = numbers[0];
    
    cout << "Enter 7 digits : " << endl;

    for (int i = 0; i < 7; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> numbers[i];
    }

    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] > maxNumber)
        {
            maxNumber = numbers[i];
        }
    }

    cout << "Max number : " << maxNumber << endl;

}