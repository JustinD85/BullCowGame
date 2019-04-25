#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    ~FBullCowGame(); //destructor

    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //TODO enhance return value.
    bool CheckGuessValidity(FString); //TODO enhance return value.
    // provide a function for counting bulls and cows & increasing try number

private:
    //constructor initializes these
    int32 MyCurrentTry;
    int32 MyMaxTries;
    bool IsIsoGram();
};