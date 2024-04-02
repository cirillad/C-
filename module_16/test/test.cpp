#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

//const int MAX_ROWS = 100;
//const int MAX_COLS = 100;
//
using namespace std;

//
//void printArr(int** arr, int rows, int columns) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < columns; j++) {
//            cout << setw(3) << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//}

//task1

//void addColumn(int**& pArr, int numRows, int& numCols, int position) {
//    int** tempArr = new int* [numRows];
//
//    for (int i = 0; i < numRows; ++i) {
//        tempArr[i] = new int[numCols + 1];
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        for (int j = 0; j < position; ++j) {
//            tempArr[i][j] = pArr[i][j];
//        }
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        tempArr[i][position] = rand() % 100;
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        for (int j = position; j < numCols; ++j) {
//            tempArr[i][j + 1] = pArr[i][j];
//        }
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        delete[] pArr[i];
//    }
//    delete[] pArr;
//
//    pArr = tempArr;
//    ++numCols;
//}


//task2

//void deleteColumn(int**& pArr, int numRows, int& numCols, int position) {
//    int** tempArr = new int* [numRows];
//
//    for (int i = 0; i < numRows; ++i) {
//        tempArr[i] = new int[numCols - 1];
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        for (int j = 0; j < position; ++j) {
//            tempArr[i][j] = pArr[i][j];
//        }
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        for (int j = position; j < numCols - 1; ++j) {
//            tempArr[i][j] = pArr[i][j + 1];
//        }
//    }
//
//    for (int i = 0; i < numRows; ++i) {
//        delete[] pArr[i];
//    }
//    delete[] pArr;
//
//    pArr = tempArr;
//    --numCols;
//}


//task3

//void cyclicShift(int** matrix, int rows, int columns, int shiftCount, bool shiftRows, bool shiftRight) {
//    if (shiftRows) {
//        for (int i = 0; i < rows; ++i) {
//            int* tempRow = new int[columns];
//            for (int j = 0; j < columns; ++j) {
//                int newIndex = shiftRight ? (j + shiftCount) % columns : (j + columns - shiftCount) % columns;
//                tempRow[newIndex] = matrix[i][j];
//            }
//            delete[] matrix[i];
//            matrix[i] = tempRow;
//        }
//    } else {
//        for (int j = 0; j < columns; ++j) {
//            int* tempColumn = new int[rows];
//            for (int i = 0; i < rows; ++i) {
//                int newIndex = shiftRight ? (i + shiftCount) % rows : (i + rows - shiftCount) % rows;
//                tempColumn[newIndex] = matrix[i][j];
//            }
//            for (int i = 0; i < rows; ++i) {
//                matrix[i][j] = tempColumn[i];
//            }
//            delete[] tempColumn;
//        }
//    }
//}
//
//void printMatrix(int** matrix, int rows, int columns) {
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            cout << matrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//}


//task4


//void transposeMatrix(int** matrix, int rows, int columns) {
//    int** transposedMatrix = new int* [columns];
//    for (int i = 0; i < columns; ++i) {
//        transposedMatrix[i] = new int[rows];
//    }
//
//    for (int i = 0; i < rows; ++i) {
//        for (int j = 0; j < columns; ++j) {
//            transposedMatrix[j][i] = matrix[i][j];
//        }
//    }
//
//    cout << "Transposed matrix:" << endl;
//    for (int i = 0; i < columns; ++i) {
//        for (int j = 0; j < rows; ++j) {
//            cout << transposedMatrix[i][j] << " ";
//        }
//        cout << endl;
//    }
//
//    for (int i = 0; i < columns; ++i) {
//        delete[] transposedMatrix[i];
//    }
//    delete[] transposedMatrix;
//}


//task5

const int MAX_CONTACTS = 100;

struct Contact {
    char name[50];
    char phone[15];
};

Contact contacts[MAX_CONTACTS];

int contactsCount = 0;


void addContact(const char* name, const char* phone) {
    if (contactsCount < MAX_CONTACTS) {
        strcpy(contacts[contactsCount].name, name);
        strcpy(contacts[contactsCount].phone, phone);

        contactsCount++;

        cout << "Contact added successfully." << endl;
    }
    else {
        cout << "Cannot add more contacts. Limit reached." << endl;
    }
}

void searchByName(const char* name) {
    bool found = false;

    for (int i = 0; i < contactsCount; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
    }
}

void searchByPhone(const char* phone) {
    bool found = false;

    for (int i = 0; i < contactsCount; i++) {
        if (strcmp(contacts[i].phone, phone) == 0) {
            cout << "Name: " << contacts[i].name << ", Phone: " << contacts[i].phone << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Contact not found." << endl;
    }
}






int main() {
    //task1

    //srand(time(0));

    //int rows = 5, columns = 5;

    //int** arr = new int* [rows];

    //for (int i = 0; i < rows; i++) {
    //    arr[i] = new int[columns];
    //    for (int j = 0; j < columns; j++) {
    //        arr[i][j] = rand() % 100;
    //    }
    //}

    //cout << "Original array:" << endl;
    //printArr(arr, rows, columns);

    //addColumn(arr, rows, columns, 2);

    //cout << "\nArray after adding a column:" << endl;
    //printArr(arr, rows, columns);

    //for (int i = 0; i < rows; i++) {
    //    delete[] arr[i];
    //}
    //delete[] arr;
    //arr = nullptr;


    //task2

    //srand(time(0));

    //int rows = 5, columns = 5;

    //int** arr = new int* [rows];

    //for (int i = 0; i < rows; i++) {
    //    arr[i] = new int[columns];
    //    for (int j = 0; j < columns; j++) {
    //        arr[i][j] = rand() % 100;
    //    }
    //}

    //cout << "Original array:" << endl;
    //printArr(arr, rows, columns);

    //deleteColumn(arr, rows, columns, 2);

    //cout << "\nArray after adding a column:" << endl;
    //printArr(arr, rows, columns);

    //for (int i = 0; i < rows; i++) {
    //    delete[] arr[i];
    //}
    //delete[] arr;
    //arr = nullptr;


    //task3

    //int rows, columns;
    //cout << "Enter number of rows: ";
    //cin >> rows;
    //cout << "Enter number of columns: ";
    //cin >> columns;

    //int** matrix = new int*[rows];
    //for (int i = 0; i < rows; ++i) {
    //    matrix[i] = new int[columns];
    //}

    //cout << "Enter matrix elements:" << endl;
    //for (int i = 0; i < rows; ++i) {
    //    for (int j = 0; j < columns; ++j) {
    //        cin >> matrix[i][j];
    //    }
    //}

    //int shiftCount;
    //cout << "Enter number of shifts: ";
    //cin >> shiftCount;

    //bool shiftRows, shiftRight;
    //cout << "Shift rows? (1 for yes, 0 for no): ";
    //cin >> shiftRows;
    //cout << "Shift to the right? (1 for yes, 0 for no): ";
    //cin >> shiftRight;

    //cyclicShift(matrix, rows, columns, shiftCount, shiftRows, shiftRight);

    //cout << "Matrix after cyclic shift:" << endl;
    //printMatrix(matrix, rows, columns);

    //for (int i = 0; i < rows; ++i) {
    //    delete[] matrix[i];
    //}
    //delete[] matrix;


    //task4

    //int rows, columns;

    //cout << "Enter number of rows: ";
    //cin >> rows;

    //cout << "Enter number of columns: ";
    //cin >> columns;

    //srand(time(nullptr));

    //int** matrix = new int*[rows];

    //for (int i = 0; i < rows; ++i) {
    //    matrix[i] = new int[columns];
    //    for (int j = 0; j < columns; ++j) {
    //        matrix[i][j] = rand() % 100;
    //    }
    //}

    //cout << "Original matrix:" << endl;

    //for (int i = 0; i < rows; ++i) {
    //    for (int j = 0; j < columns; ++j) {
    //        cout << matrix[i][j] << " ";
    //    }
    //    cout << endl;
    //}

    //transposeMatrix(matrix, rows, columns);

    //for (int i = 0; i < rows; ++i) {
    //    delete[] matrix[i];
    //}
    //delete[] matrix;


    //task5

    char choice;

    do
    {
        cout << "Menu:\n";
        cout << "1. Add contact\n";
        cout << "2. Search by name\n";
        cout << "3. Search by phone\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1': {
            char name[50], phone[15];

            cout << "Enter name: ";
            cin >> name;

            cout << endl;

            cout << "Enter phone: ";
            cin >> phone;

            addContact(name, phone);

            break;
            }

        case '2': {
            char name[50];

            cout << "Enter the name you want to search : ";
            cin >> name;

            searchByName(name);

            break;
        }

        case '3': {
            char phone[15];

            cout << "Enter the name you want to search : ";
            cin >> phone;

            searchByPhone(phone);

            break;
        }

        case '4': {
            cout << "Exiting program.";

            break;
        }

        default:
            cout << "ERROR";
        }
    } while (choice != '4');

    



}
