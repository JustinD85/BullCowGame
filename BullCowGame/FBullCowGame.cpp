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
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bIsGameWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (false) {
        return EGuessStatus::Not_Isogram;
    }
    else if (false) {
        return EGuessStatus::Not_Lowercase;
    }
    else if (Guess.length() != GetHiddenWordLength()) {
        return EGuessStatus::Wrong_Word_Length;
    }
    else {
        return EGuessStatus::OK;
    }
}

//receives a VALID guess ,increments turn, returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
    MyCurrentTry++;
    FBullCowCount BullCowCount;

    //loop through all letters in the hidden word
    for (int32 i = 0; i < GetHiddenWordLength(); i++) {
        // compare letters against the hidden guess
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
    if (BullCowCount.Bulls == GetHiddenWordLength()) {
        bIsGameWon = true;
    }

    return BullCowCount;
}


