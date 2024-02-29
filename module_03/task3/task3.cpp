#include <iostream>

using namespace std;

int main()
{
    float distance, fuel_consumption, price_gasoline1, price_gasoline2, price_gasoline3;

    cout << "Enter the distance (in km): ";
    cin >> distance;

    cout << "Enter fuel consumption per 100 km (in liters): ";
    cin >> fuel_consumption;

    cout << "Enter price of gasoline 1: ";
    cin >> price_gasoline1;

    cout << "Enter price of gasoline 2: ";
    cin >> price_gasoline2;

    cout << "Enter price of gasoline 3: ";
    cin >> price_gasoline3;

    float cost_gasoline1 = (distance / 100) * fuel_consumption * price_gasoline1;
    float cost_gasoline2 = (distance / 100) * fuel_consumption * price_gasoline2;
    float cost_gasoline3 = (distance / 100) * fuel_consumption * price_gasoline3;

    cout << "\nCost of trip using gasoline 1: $" << cost_gasoline1 << endl;
    cout << "Cost of trip using gasoline 2: $" << cost_gasoline2 << endl;
    cout << "Cost of trip using gasoline 3: $" << cost_gasoline3 << endl;
}
