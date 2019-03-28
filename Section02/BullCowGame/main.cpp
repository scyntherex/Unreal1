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
	std::cout << "\nWelcome to Bulls and Cows!" << std::endl;
	std::cout << "Guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram" << std::endl << std::endl;
	return;
}

void PlayGame() {

	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	//TODO change to WHILE when validating tries
	for (int32 count = 0; count < MaxTries; count++) {
		FText Guess = GetGuess(); //TODO make loop checking valid

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		//Print number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;

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