#include<iostream>

using namespace std;

int main()
{
	//task1
	//double R1, R2, R3, R0;

	//R1 = 2;

	//R2 = 4;

	//R3 = 8;

	//R0 = 1 / ((1 / R1) + (1/ R2) + (1 / R3));

	//cout << R0 << endl;

	//task2
	
	//double L, R, S;
	//const double Pi = 3.14;

	//cout << "Enter the lenghth of a circle : ";
	//cin >> L;

	//R = L / (2 * Pi);

	//S = Pi * R * R;

	//cout << "S : " << S << endl;

	//task3

	double v, t, a, S;

	cout << "Enter the velocity (v): ";
	cin >> v;

	cout << "Enter the time (t): ";
	cin >> t;

	cout << "Enter the acceleration (a): ";
	cin >> a;

	S = v * t + (a * t * t) / 2;

	cout << "Distance traveled (S): " << S << endl;

}