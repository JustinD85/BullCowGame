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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
    // increment turn number
    MyCurrentTry++;

    // setup a return variable
    FBullCowCount BullCowCount;

    //loop through all letters in the guess
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 i = 0; i < HiddenWordLength; i++) {
        // compare letters against the hidden word
        for (int32 j = 0; j < Guess.length(); j++) {
            //if match
            if (MyHiddenWord[i] == Guess[j]) {
                if (i == j) {
                    //increment bulls if in same place
                    BullCowCount.Bulls++;
                }
                else {
                    BullCowCount.Cows++;
                    //increment cows if not
                }
            }
        }
    }

    return BullCowCount;
}

