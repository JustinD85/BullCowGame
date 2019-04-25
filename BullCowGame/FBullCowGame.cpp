#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
    FBullCowGame::Reset();
}

FBullCowGame::~FBullCowGame()
{
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::Reset()
{
    constexpr int MAX_TRIES = 8;
    MyMaxTries = MAX_TRIES;
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

bool FBullCowGame::IsIsoGram()
{
    return false;
}
