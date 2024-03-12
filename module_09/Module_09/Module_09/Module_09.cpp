#include <iostream>

using namespace std;

//task3

const int ROWS = 2;
const int COLS = 6;

void shiftArray(int arr[][COLS], int shifts, char direction) {
    int temp[ROWS][COLS];

    if (direction == 'l' || direction == 'L') {
        shifts = COLS - (shifts % COLS);
    }
    else if (direction == 'r' || direction == 'R') {
        shifts = shifts % COLS;
    }
    else if (direction == 'u' || direction == 'U') {
        shifts = ROWS - (shifts % ROWS);
    }
    else if (direction == 'd' || direction == 'D') {
        shifts = shifts % ROWS;
    }
    else {
        cout << "Invalid direction. Please choose from l, r, u, d." << endl;
        return;
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            if (direction == 'l' || direction == 'L') {
                temp[i][(j + shifts) % COLS] = arr[i][j];
            }
            else if (direction == 'r' || direction == 'R') {
                temp[i][j] = arr[i][(j + shifts) % COLS];
            }
            else if (direction == 'u' || direction == 'U') {
                temp[(i + shifts) % ROWS][j] = arr[i][j];
            }
            else if (direction == 'd' || direction == 'D') {
                temp[i][j] = arr[(i + shifts) % ROWS][j];
            }
        }
    }

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = temp[i][j];
        }
    }
}

void displayArray(int arr[][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    //task1

    //const int SIZE = 10;
    //int array[SIZE]{};
    //int first_i;

    //cout << "Enter initial num : " << endl;
    //cin >> first_i;
    //cout << endl;

    //for (size_t i = 0; i < SIZE; i++)
    //{
    //    array[i] += first_i;
    //    first_i *= 2;
    //}

    //for (size_t i = 0; i < SIZE; i++)
    //{
    //    cout << array[i] << " " << endl;
    //}


    //task2

    //const int SIZE = 10;
    //int array[SIZE]{};
    //int first_i;

    //cout << "Enter initial num : " << endl;
    //cin >> first_i;
    //cout << endl;

    //for (size_t i = 0; i < SIZE; i++)
    //{
    //    array[i] += first_i;
    //    first_i += 1;
    //}

    //for (size_t i = 0; i < SIZE; i++)
    //{
    //    cout << array[i] << " " << endl;
    //}


    //task3

    int arr[ROWS][COLS] = {
    {1, 2, 0, 4, 5, 3},
    {4, 5, 3, 9, 0, 1}
    };

    cout << "Original array:" << endl;
    displayArray(arr);

    int shifts;
    char direction;

    cout << "Enter number of shifts: ";
    cin >> shifts;
    cout << "Enter direction (l, r, u, d): ";
    cin >> direction;

    shiftArray(arr, shifts, direction);

    cout << "Shifted array:" << endl;
    displayArray(arr);

    return 0;
}
