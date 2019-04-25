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
    int MyCurrentTry = 1;
    int MyMaxTries = 5;
    bool IsIsoGram();
};