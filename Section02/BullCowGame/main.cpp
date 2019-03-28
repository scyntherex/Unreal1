#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

int main() {
	
	do {
		PrintIntro();
		PlayGame();
	} while (AskToPlayAgain() == true);

	return 0;
}

void PrintIntro() {
	constexpr int WORD_LENGTH = 9;
	std::cout << "\nWelcome to Bulls and Cows!" << std::endl;
	std::cout << "Guess the " << WORD_LENGTH;
	std::cout << " letter isogram" << std::endl << std::endl;
	return;
}

void PlayGame() {
	FBullCowGame BCGame;
	constexpr int NUM_OF_TURNS = 5;
	for (int i = 0; i < NUM_OF_TURNS; i++) {
		std::string Guess = GetGuess();
		std::cout << "Your guess was " << Guess << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess() {
	std::cout << "Enter guess here: ";
	std::string Guess = "";
	getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain() {
	std::cout << "Play Again? ";
	std::string Response = "";
	getline(std::cin, Response);

	return (Response[0] == 'y' || Response[0] == 'Y');
}