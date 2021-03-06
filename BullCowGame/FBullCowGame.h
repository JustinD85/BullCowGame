/*
    The Game logic (no view code or direct user interaction)
    The game is a simple clone of the game Mastermind: 'https://en.wikipedia.org/wiki/Mastermind_(board_game)'
*/
#pragma once
#include <string>

//To make code Unreal *friendly*
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
    EGuessStatus CheckGuessValidity(FString) const;
    bool IsGameWon() const;

    void Reset();
    FBullCowCount SubmitValidGuess(FString);


private:
    bool IsIsogram(FString) const;
    bool IsLowercase(FString) const;

    //constructor initializes these
    int32 MyCurrentTry;
    FString MyHiddenWord;
    bool bIsGameWon;
};