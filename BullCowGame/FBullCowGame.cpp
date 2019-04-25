#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
    FBullCowGame::Reset();
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

BullCowCount FBullCowGame::SubmitGuess(FString)
{
    return BullCowCount();
}

bool FBullCowGame::IsIsoGram()
{
    return false;
}
