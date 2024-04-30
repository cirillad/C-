#include <iostream>
#include <stack>

using namespace std;

bool checkBrackets(const string& expression) {
    stack<char> stack;

    for (char c : expression) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (stack.empty()) {
                return false;
            }

            char top = stack.top();
            stack.pop();

            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return stack.empty();
}

int main() {
    string correctString = "({x-y-z} * [x + 2y] - (z + 4x)).";
    string incorrectString = "([x-y-z} * [x + 2y) - {z + 4x)].";

    if (checkBrackets(correctString)) {
        cout << "The string contains correct bracket placement." << endl;
    }
    else {
        cout << "The string contains incorrect bracket placement." << endl;
    }

    if (checkBrackets(incorrectString)) {
        cout << "The string contains correct bracket placement." << endl;
    }
    else {
        cout << "The string contains incorrect bracket placement." << endl;
    }
}