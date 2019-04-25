#pragma once
#include <string>

class FBullCowGame {
public:
    void Reset(); //TODO enhance return value.
    int GetMaxTries();
    int GetCurrentTry();
    bool IsGameWon();
    bool CheckGuessValidity(std::string); //TODO enhance return value.

private:
    int MyCurrentTry;
    int MyMaxTries;
    bool IsIsoGram();
};