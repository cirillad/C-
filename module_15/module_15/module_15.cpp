#include <iostream>

using namespace std;

//task1

void deleteOneChar(char* text, int deleteChar)
{
    if (deleteChar < 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        int length = strlen(text);
        int count = 0;

        for (size_t i = 0; i < length; i++)
        {
            if (text[i] == deleteChar)
            {
                for (int j = i; j < length - 1; j++)
                {
                    text[j] = text[j + 1];
                }
                length--;
                i--;
                break;
            }
        }
        text[length] = '\0';
    }
}



//task2

void deleteAllChar(char* text, int deleteChar)
{
    if (deleteChar < 0)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        int length = strlen(text);
        int count = 0;

        for (size_t i = 0; i < length; i++)
        {
            if (text[i] == deleteChar)
            {
                for (int j = i; j < length - 1; j++)
                {
                    text[j] = text[j + 1];
                }
                length--;
                i--;
            }
        }
        text[length] = '\0';
    }
}


//task3



void SwapChar(char* text, int deleteChar, int index)
{
    int length = strlen(text);

    if (deleteChar < 0)
    {
        cout << "ERROR" << endl;
        return;
    }

    if (index < 0 || index > length)
    {
        cout << "ERROR" << endl;
        return;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (i == index)
        {
            text[i] = deleteChar;
        }
    }
}


//task4

void deletePoints(char* text)
{
    int length = strlen(text);

    for (size_t i = 0; i < length; i++)
    {
        if (text[i] == 46)
        {
            text[i] = 33;
        }
    }
}


//task5

void charCount(char* text, int symbol)
{
    int length = strlen(text);
    int count = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (text[i] == symbol)
        {
            count++;
        }
    }
    cout << count;
}


//task6

void countCharacters(const char* text, int& letters, int& digits, int& others) {
    letters = digits = others = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            letters++;
        }
        else if (text[i] >= '0' && text[i] <= '9') {
            digits++;
        }
        else {
            others++;
        }
    }
}


int main()
{
    //task1, 2

    //char text[10] = "Hello! 11";
    //int symbol;

    //cout << "Enter the num of a char you want to delete : " << endl;
    //cin >> symbol;

    //deleteChar(text, symbol);
    //deleteAllChar(text, symbol);

    //cout << text;


    //task3

    //char text[20] = "Hello! 11";
    //int index;
    //int symbol;

    //cout << "Enter the num of a char : " << endl;
    //cin >> symbol;

    //cout << "Enter the index of a char : " << endl;
    //cin >> index;

    //SwapChar(text, symbol, index);

    //cout << text;


    //task4

    //char text[20] = "Hello. 12.3";

    //deletePoints(text);

    //cout << text << endl;


    //task5

    //char text[20] = "Hello. 12.3";
    //int symbol;

    //cout << "Enter the num of char : " << endl;
    //cin >> symbol;

    //cout << text << endl;

    //charCount(text, symbol);


    //task6

    const int MAX_LENGTH = 100;
    char text[MAX_LENGTH];

    cout << "Enter a string: ";
    cin.getline(text, MAX_LENGTH);

    int letters, digits, others;
    countCharacters(text, letters, digits, others);

    cout << "Number of letters: " << letters << endl;
    cout << "Number of digits: " << digits << endl;
    cout << "Number of other characters: " << others << endl;

}