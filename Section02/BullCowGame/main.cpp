/* Console executable that makes use BullCow class
Acts as MVC pattern and is responsible for interaction.
Game logic is in FBullCowClass
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate new game

int main() {

	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro() {
	constexpr int32 WORD_LENGTH = 9;
	std::cout << "\nWelcome to Bulls and Cows!" << std::endl;
	std::cout << "Guess the " << WORD_LENGTH;
	std::cout << " letter isogram" << std::endl << std::endl;
	return;
}

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//TODO change to WHILE when validating tries
	for (int32 i = 0; i < MaxTries; i++) {
		FText Guess = GetGuess(); //TODO make loop checking valid

		//Submit valid guess to the game
		//Print number of bulls and cows

		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}

	//TODO summarise game
}

FText GetGuess() {
	std::cout << "Attempt no. " << BCGame.GetCurrentTry();
	std::cout << ". Enter guess here: ";
	FText Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Play Again? ";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}