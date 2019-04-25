#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
string GetGuess();

//Entry point of application
int main() {
	
	PrintIntro();
	GetGuess();
	return 0;
}

// Game introduction
void PrintIntro() {
	constexpr int WORD_LENGTH = 7;
	cout << "Welcome to Bulls and Cows." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}

// Get guess from player
string GetGuess() {
	string Guess = "";
	getline(cin, Guess);
	// repeat the guess back to player
	cout << "your guess was " << Guess << endl;
	return Guess;
}