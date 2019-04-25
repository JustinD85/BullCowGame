#include <iostream>
#include <string>
#include "FBullCowGame.h"

FBullCowGame BCGame; //instantiates a new game
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
std::string GetGuess();

int main()
{
    do {
        PrintIntro();
        PlayGame();
    } while (AskToPlayAgain());

    return 0;
}

void PrintIntro()
{
    constexpr int WORD_LENGTH = 7;
    std::cout << "Welcome to Bulls and Cows." << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
    // loop for number of turns asking for guesses
    for (int i = 0; i < BCGame.GetMaxTries(); i++) {
        std::string Guess = GetGuess();
        std::cout << "your guess was " << Guess << std::endl;
    }
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    std::string Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');

}

std::string GetGuess()
{
    std::cout << "Try " << BCGame.GetCurrentTry() << std::endl;
    std::string Guess = "";
    std::getline(std::cin, Guess);

    return Guess;
}