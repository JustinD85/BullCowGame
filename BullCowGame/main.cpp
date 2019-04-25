/*
This is the console executable, that makes use of the BullCow class
This acts as the view in MVC pattern, and is responsible for all
user interaction. For game logic see FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = FString;
using int32 = int;

FBullCowGame BCGame; //instantiates a new game
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetGuess();

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
    constexpr int32 WORD_LENGTH = 7;
    std::cout << "Welcome to Bulls and Cows." << std::endl;
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

void PlayGame()
{
    BCGame.Reset();
    // loop for number of turns asking for guesses
    //TODO change to while loop after checking for valid guess function is complete
    for (int32 i = 0; i < BCGame.GetMaxTries(); i++) {
        FText Guess = GetGuess();//TODO check for valid guess

        //Submit valid guess to game
        //Print number of bulls and cows
        std::cout << "your guess was " << Guess << std::endl;
    }

    // TODO summarize game
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? ";
    FText Response = "";
    std::getline(std::cin, Response);
    return (Response[0] == 'y' || Response[0] == 'Y');

}

FText GetGuess()
{
    std::cout << "Try " << BCGame.GetCurrentTry() << std::endl;
    FText Guess = "";
    std::getline(std::cin, Guess);

    return Guess;
}