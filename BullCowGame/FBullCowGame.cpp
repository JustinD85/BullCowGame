#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
    Reset();
}

FBullCowGame::~FBullCowGame()
{
}

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;

    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;

    MyCurrentTry = 1;
}


bool FBullCowGame::IsGameWon() const
{
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
    return false;
}

//receives a VALID guess ,increments turn, returns count
FBullCowCount FBullCowGame::SubmitGuess(FString)
{
    // increment turn number
    MyCurrentTry++;
    // setup a return variable
    FBullCowCount BullCowCount;
    //loop through all letters in the guess
        // compare letters against the hidden word
            //if match
                //increment bulls if in same place
                //increment cows if not

    return BullCowCount;
}

