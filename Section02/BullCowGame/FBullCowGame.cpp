#include "FBullCowGame.h"

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "bloooop";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

bool FBullCowGame::IsGameWon() const { return false; }

EWordStatus FBullCowGame::CheckGuessValidity(FString) const {
	return EWordStatus::OK; //TODO make actual error
}

//receives valid guess, incerements turn, and counts bulls and cows
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment the turn number
	MyCurrentTry++;

	//setup a return variable
	FBullCowCount BullCowCountVar;

	//loop thrugh all letters in the guess
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 MyHiddenChar = 0; MyHiddenChar < HiddenWordLength; MyHiddenChar++) {

		//compare letters against hidden word
		for (int32 GuessChar = 0; GuessChar < HiddenWordLength; GuessChar++) {
			//if match, 
			if (Guess[GuessChar] == MyHiddenWord[MyHiddenChar]) {


				//if matching in place, increment bulls if letters in same place
				if (MyHiddenChar == GuessChar) {
					BullCowCountVar.Bulls++;
				}	
				//else, //increment cows if not
				else {
					BullCowCountVar.Cows++;
				}	
			}	
		}
	}
	return BullCowCountVar;
}

