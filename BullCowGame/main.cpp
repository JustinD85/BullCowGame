#include <iostream>
#include <string>

using namespace std;

void PrintIntro() {
	constexpr int WORD_LENGTH = 7;
	cout << "Welcome to Bulls and Cows." << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of?\n";
}
int main() {
	// Game introduction
	PrintIntro();

	// Get guess from player
	string Guess = "";
	getline(cin, Guess);
	cout << "your guess was " << Guess << endl;
	// repeat the guess back to player
	return 0;
}