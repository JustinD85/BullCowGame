#pragma once
#include <string>

class FBullCowGame {
public:
    FBullCowGame(); //constructor
    ~FBullCowGame(); //destructor

    int GetMaxTries() const;
    int GetCurrentTry() const;
    bool IsGameWon() const;

    void Reset(); //TODO enhance return value.
    bool CheckGuessValidity(std::string); //TODO enhance return value.
    // provide a function for counting bulls and cows & increasing try number

private:
    //constructor initializes these
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsoGram();
};