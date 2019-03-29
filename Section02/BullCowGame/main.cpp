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
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

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

	//loop until game is won with tries remaining
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
		FText Guess = GetValidGuess();

		//Submit valid guess to the game
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
		std::cout << std::endl;
	}

	PrintGameSummary();
	return;
}

//loop continually until you get a valid guess
FText GetValidGuess() { 

	FText Guess = "";
	EGuessWordStatus Status = EGuessWordStatus::Invalid_Status;
	do {
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Attempt no. " << CurrentTry;
		std::cout << ". Enter guess here: ";
		
		getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) {
		case EGuessWordStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.";
			break;
		case EGuessWordStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.";
			break;
		case EGuessWordStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.";
			break;
		default:
			break;
		}
		std::cout << std::endl << std::endl;
	} while (Status != EGuessWordStatus::OK);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Play Again? ";
	FText Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon()) {
		std::cout << "GOOD JOB!" << std::endl;
	}
	else {
		std::cout << "YOU LOSE!" << std::endl;
	}
}