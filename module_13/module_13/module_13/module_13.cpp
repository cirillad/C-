#include <iostream>
using namespace std;

int main() {
    //const int SIZE = 10;
    //int arr1[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
    //int arr2[SIZE] = {};

    //int* ap1 = arr1;
    //int* ap2 = arr2;

    //1

    //for (size_t i = 0; i < SIZE; i++)
    //{
    //    *ap2 = *ap1;
    //    ++ap1;
    //    ++ap2;
    //}

    //2

    //for (size_t i = 0; i < SIZE; i++)
    //{
    //    *(ap2 + i) = *(ap1 + i);
    //}

    //cout << "arr2 : ";
    //for (int i = 0; i < SIZE; ++i) {
    //    cout << arr2[i] << " ";
    //}


    //task2
    const int SIZE = 10;
    int arr1[SIZE] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int* startPtr = arr1;
    int* endPtr = arr1 + SIZE - 1;

    while (startPtr < endPtr) {
        int temp = *startPtr;
        *startPtr = *endPtr;
        *endPtr = temp;

        ++startPtr;
        --endPtr;
    }

    for (int i = 0; i < SIZE; ++i) {
        cout << arr1[i] << " ";
    }
    cout << endl;


    //task3

    //const int SIZE = 10;
    //int arr1[SIZE] = { 0,1,2,3,4,5,6,7,8,9 };
    //int arr2[SIZE] = {};

    //int* ap1 = arr1;
    //int* ap2 = arr2;

    //for (size_t i = 1; i < SIZE; i++)
    //{
    //    *(ap2 + i) = *(ap1 + SIZE - i);
    //}

    //cout << "arr2 : ";
    //for (int i = 0; i < SIZE; ++i) {
    //    cout << arr2[i] << " ";
    //}






}

