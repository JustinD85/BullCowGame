#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();

//Entry point of application
int main() {

    PrintIntro();

    PlayGame();
    return 0;
}


// Game introduction
void PrintIntro() {
    constexpr int WORD_LENGTH = 7;
    cout << "Welcome to Bulls and Cows." << endl;
    cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
    // loop for number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 5;
    for (int i = 0; i < NUMBER_OF_TURNS; i++) {
        string Guess = GetGuess();
        cout << "your guess was " << Guess << endl;
    }
}

string GetGuess() {
    // Get guess from player
    string Guess = "";
    getline(cin, Guess);

    return Guess;
}