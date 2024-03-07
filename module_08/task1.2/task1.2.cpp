#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(0));

    int userScore = 0;
    int computerScore = 0;

    cout << "Welcome to the Dice Game!\n";

    for (int round = 1; round <= 3; ++round) {
        int userTotal = rollDice() + rollDice();
        int computerTotal = rollDice() + rollDice();

        userScore += userTotal;
        computerScore += computerTotal;

        cout << "Round " << round << " - Your total: " << userTotal << ", Computer's total: " << computerTotal << endl;
    }

    cout << "\nFinal Scores:\n";
    cout << "Your total score: " << userScore << endl;
    cout << "Computer's total score: " << computerScore << endl;

    if (userScore > computerScore) {
        cout << "Congratulations! You win!\n";
    }
    else if (userScore < computerScore) {
        cout << "Sorry! Computer wins.\n";
    }
    else {
        cout << "It's a tie!\n";
    }

    return 0;
}
