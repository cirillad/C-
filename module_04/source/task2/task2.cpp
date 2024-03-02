#include <iostream>

using namespace std;

int main()
{
      int number;

      cout << "enter a four-digit number: ";
      cin >> number;

      if (number < 1000 || number > 9999) {
          cout << "error: please enter a four-digit number." << endl;
          return 1;
      }

      int newnumber = (number % 100) * 100 + (number / 100);

      cout << "the modified number is: " << newnumber << endl;



}