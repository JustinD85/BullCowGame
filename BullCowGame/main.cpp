/*
This is the console executable, that makes use of the BullCow class
This acts as the view in MVC pattern, and is responsible for all
user interaction. For game logic see FBullCowGame class.
*/
#include <iostream>
#include <string>
#include "FBullCowGame.h"

//To make code Unreal *friendly*
using FText = std::string;

FBullCowGame BCGame; //instantiates a new game
void PrintIntro();
void PlayGame();
bool AskToPlayAgain();
FText GetValidGuess();
void PrintGameSummary();
void PrintCharmander();

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
    system("CLS");
    std::cout << "Welcome to Bulls and Cows." << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
    PrintCharmander();
}

void PlayGame()
{
    BCGame.Reset();
    FBullCowCount BullCowCount;

    // loop for number of turns asking for guesses
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= BCGame.GetMaxTries()) {
        FText Guess = GetValidGuess();

        //Submit valid guess to game
        BullCowCount = BCGame.SubmitValidGuess(Guess);

        std::cout << "Bulls = " << BullCowCount.Bulls << std::endl;
        std::cout << "Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;

    }

    PrintGameSummary();
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again (y/n)? \n";
    FText Response = "";
    std::getline(std::cin, Response);

    return (Response[0] == 'y' || Response[0] == 'Y');
}

// loop continously until valid guess is entered
FText GetValidGuess()
{
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do {
        std::cout << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". ";
        std::cout << "Enter a guess: ";
        FText Guess = "";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
        case EGuessStatus::Wrong_Word_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "Please a word without repeating letters." << std::endl;
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter all lowercase characters." << std::endl;
            break;
        default:
            return Guess;
        }
    } while (true);

}

void PrintGameSummary()
{
    if (BCGame.IsGameWon()) {

        std::cout << "CONGRATULATIONS, YOU WON!!!\n";
    }
    else {
        std::cout << "Better Luck Next Time!\n";
    }
}

void PrintCharmander()
{
    std::cout << R"(
                          ,-'`\
                  _,"'    j
           __....+       /               .
       ,-'"             /               ; `-._.'.
      /                (              ,'       .'
     |            _.    \             \   ---._ `-.
     ,|    ,   _.'  Y    \             `- ,'   \   `.`.
     l'    \ ,'._,\ `.    .              /       ,--. l
  .,-        `._  |  |    |              \       _   l .
 /              `"--'    /              .'       ``. |  )
.\    ,                 |                .        \ `. '
`.                .     |                '._  __   ;. \'
  `-..--------...'       \                  `'  `-"'.  \
      `......___          `._                        |  \
               /`            `..                     |   .
              /|                `-.                  |    L
             / |               \   `._               .    |
           ,'  |,-"-.   .       .     `.            /     |
         ,'    |     '   \      |       `.         /      |
       ,'     /|       \  .     |         .       /       |
     ,'      / |        \  .    +          \    ,'       .'
    .       .  |         \ |     \          \_,'        / j
    |       |  L          `|      .          `        ,' '
    |    _. |   \          /      |           .     .' ,'
    |   /  `|    \        .       |  /        |   ,' .'
    |   ,-..\     -.     ,        | /         |,.' ,'
    `. |___,`    /  `.   /`.       '          |  .'
      '-`-'     j     ` /."7-..../|          ,`-'
                |        .'  / _/_|          .
                `,       `"'/"'    \          `.
                  `,       '.       `.         |
             __,.-'         `.        \'       |
            /_,-'\          ,'        |        _.
             |___.---.   ,-'        .-':,-"`\,' .
                  L,.--"'           '-' |  ,' `-.\
                                        `.
)" << std::endl;
}
