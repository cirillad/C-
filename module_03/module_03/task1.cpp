#include <iostream>

using namespace std;

int main()
{
    float lenghth, time, speed;

    cout << "Enter the distance in kilometers : " << endl;

    cin >> lenghth;

    cout << "Enter the time in hours: " << endl;

    cin >> time;

    speed = lenghth / time;

    cout << "Your speed must be at least : " << speed << " km/hour" << endl;


}
