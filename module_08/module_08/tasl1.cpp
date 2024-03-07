#include <iostream>
#include <thread>
#include <chrono>

using namespace std;
using namespace this_thread;
using namespace chrono;


void printHorizontalLine(char symbol, int speed)
{
    if (speed == 1)
    {
        for (size_t i = 0; i < 30; i++)
        {
            cout << symbol;
            sleep_for(milliseconds(100));
        }
    }

    if (speed == 2)
    {
        for (size_t i = 0; i < 30; i++)
        {
            cout << symbol;
            sleep_for(milliseconds(50));
        }
    }

    if (speed == 3)
    {
        for (size_t i = 0; i < 30; i++)
        {
            cout << symbol;
            sleep_for(milliseconds(10));
        }
    }
}

void printVerticalLine(char symbol, int speed)
{
    if (speed == 1)
    {
        for (size_t i = 0; i < 30; i++)
        {
            cout << symbol << endl;
            sleep_for(milliseconds(100));
        }
    }

    if (speed == 2)
    {
        for (size_t i = 0; i < 30; i++)
        {
            cout << symbol << endl;
            sleep_for(milliseconds(50));
        }
    }

    if (speed == 3)
    {
        for (size_t i = 0; i < 30; i++)
        {
            cout << symbol << endl;
            sleep_for(milliseconds(10));
        }
    }
}

int main()
{
    int direction, speed;
    char symbol;

    cout << "If yo want horizontal line enter {1}, if you want vertical line enter {2} : " << endl;
    cin >> direction;

    cout << "Enter the symbol you want : " << endl;
    cin >> symbol;

    cout << "Choose speed you want {1} - slow, {2} - normal, {3} - fast : " << endl;
    cin >> speed;

    if (direction == 1)
    {
        printHorizontalLine(symbol, speed);
    }
    else if (direction == 2)
    {
        printVerticalLine(symbol, speed);
    }
    else
    {
        cout << "ERROR";
        return 1;
    }

}


