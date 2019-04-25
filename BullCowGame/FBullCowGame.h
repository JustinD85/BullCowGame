#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    ~FBullCowGame(); //destructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //TODO enhance return value.
    bool CheckGuessValidity(FString); //TODO enhance return value.
    FBullCowCount SubmitGuess(FString);

private:
    //constructor initializes these
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
};