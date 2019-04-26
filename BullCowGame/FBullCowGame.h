#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum EGuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Not_Lowercase,
    Wrong_Word_Length
};

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    ~FBullCowGame(); //destructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    EGuessStatus CheckGuessValidity(FString) const; //TODO enhance return value.
    bool IsGameWon() const;

    void Reset(); //TODO enhance return value.
    FBullCowCount SubmitValidGuess(FString);

private:
    //constructor initializes these
    int32 MyCurrentTry;
    int32 MyMaxTries;
    FString MyHiddenWord;
    bool bIsGameWon;
};