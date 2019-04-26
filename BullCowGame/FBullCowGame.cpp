#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
    Reset();
}

FBullCowGame::~FBullCowGame()
{
}

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bIsGameWon; }

int32 FBullCowGame::GetMaxTries() const
{
    //Difficulty table
    TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,7}, {5,10}, {6,14}, {7,14}, {8,16}, {9,17} };
    return WordLengthToMaxTries[GetHiddenWordLength()];
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
    TMap<char, bool> SeenLetters;

    for (auto Letter : Guess) {
        Letter = tolower(Letter);

        //Tmap sets default value to false when accessed for first time
        if (SeenLetters[Letter]) return false;
        else SeenLetters[Letter] = true;
    }

    return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
    for (auto Letter : Guess) {
        if (Letter != tolower(Letter)) return false;
    }
    return true;
}

void FBullCowGame::Reset()
{
    constexpr int32 MAX_TRIES = 8;
    const FString HIDDEN_WORD = "planet";

    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bIsGameWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
    if (!IsIsogram(Guess)) {
        return EGuessStatus::Not_Isogram;
    }
    else if (!IsLowercase(Guess)) {
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
