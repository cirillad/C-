#include <iostream>

using namespace std;

int main() {
    int distance_AB, distance_BC, cargo_weight;
    float fuel_capacity = 300;

    cout << "Enter the distance between points A and B in km: ";
    cin >> distance_AB;
    cout << "Enter the distance between points B and C in km: ";
    cin >> distance_BC;
    cout << "Enter the weight of the cargo in kg: ";
    cin >> cargo_weight;

    float fuel_consumption_AB;
    if (cargo_weight <= 500)
        fuel_consumption_AB = 1;
    else if (cargo_weight <= 1000)
        fuel_consumption_AB = 4;
    else if (cargo_weight <= 1500)
        fuel_consumption_AB = 7;
    else if (cargo_weight <= 2000)
        fuel_consumption_AB = 9;
    else {
        cout << "The aircraft cannot lift cargo exceeding 2000 kg." << endl;
        return 1;
    }

    float fuel_needed_AB = distance_AB * fuel_consumption_AB;
    float fuel_needed_BC = distance_BC * fuel_consumption_AB;

    if (fuel_needed_AB + fuel_needed_BC <= fuel_capacity)
        cout << "The minimum amount of fuel needed for refueling at point B to fly from point A to point C is: "
        << fuel_needed_AB + fuel_needed_BC << " liters." << endl;
    else
        cout << "The aircraft cannot fly the required distance due to fuel capacity." << endl;

    return 0;
}
