#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class NumberGuessGame {
private:
    int randomNumber;
    int numberOfGuesses;

public:
    NumberGuessGame() {
        // Initialize random seed
        srand(time(0));
        // Generate a random number between 1 and 100
        randomNumber = rand() % 100 + 1;
        numberOfGuesses = 0;
    }

    void play() {
        int guess;
        bool hasGuessedCorrectly = false;

        cout << "Welcome to the Number Guessing Game!" <<endl;

        while (!hasGuessedCorrectly) {
            cout << "Enter your guess (1-100): ";
            cin >> guess;

            numberOfGuesses++;

            if (guess < 1 || guess > 100) {
                cout << "Please enter a valid guess between 1 and 100." <<endl;
                continue; // Continue the loop if the guess is out of range
            }

            if (guess < randomNumber) {
                cout << "Too low! Try again." <<endl;
            } else if (guess > randomNumber) {
                cout << "Too high! Try again." <<endl;
            } else {
                cout << "Congratulations! You guessed the number " << randomNumber << " in "
                          << numberOfGuesses << " guesses." <<endl;
                hasGuessedCorrectly = true; // End the game if the guess is correct
            }
        }
    }
};

int main() {
    NumberGuessGame game;
    game.play(); // Start the game

    return 0;
}
