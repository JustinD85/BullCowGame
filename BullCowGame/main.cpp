#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

//Entry point of application
int main() {

    PrintIntro();

    // loop for number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 0; i < NUMBER_OF_TURNS; i++) {
        GetGuess();
    }
    return 0;
}

// Game introduction
void PrintIntro() {
    constexpr int WORD_LENGTH = 7;
    cout << "Welcome to Bulls and Cows." << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

string GetGuess() {
    // Get guess from player
    string Guess = "";
    getline(cin, Guess);
    // repeat the guess back to player
    cout << "your guess was " << Guess << endl;
    return Guess;
}