#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
string GetGuess();

//Entry point of application
int main()
{
    do {
        PrintIntro();
        PlayGame();
    } while (AskToPlayAgain());

    return 0;
}


// Game introduction
void PrintIntro()
{
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

bool AskToPlayAgain()
{
    cout << "Do you want to play again (y/n)? ";
    string Response = "";
    getline(cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');

}

string GetGuess()
{
    // Get guess from player
    string Guess = "";
    getline(cin, Guess);

    return Guess;
}