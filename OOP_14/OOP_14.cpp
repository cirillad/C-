#include <iostream>

using namespace std;

namespace mathemetic
{
	int Adding(int a, int b)
	{
		return a + b;
	}

	int Subtracting(int a, int b)
	{
		return a - b;
	}

	int Multiplying(int a, int b)
	{
		return a * b;
	}

	double Dividing(int a, int b)
	{
		if (b == 0)
		{
			cout << "Error" << endl;
			return 0;
		}
		return static_cast<double>(a) / b;
	}
}

namespace hello_world
{
	void HelloWorld()
	{
		cout << "Hello world";
	}
}

int main()
{
	cout << "2 + 2 = " << mathemetic::Adding(2, 2) << endl;
	cout << "4 - 2 = " << mathemetic::Subtracting(4, 2) << endl;
	cout << "3 * 3 = " << mathemetic::Multiplying(3, 3) << endl;
	cout << "10 / 2 = " << mathemetic::Dividing(10, 2) << endl;

	hello_world::HelloWorld();
}
