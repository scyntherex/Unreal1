#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

bool FBullCowGame::IsIsogram(FString Word) const
{
	//treat 0 and 1 letter words as isogram
	if (Word.length() <= 1) { return true; }

	//setup map
	TMap<char, bool> LetterSeen;

	//loop through all the letters from word 
	for (auto Letter : Word) {
		Letter = tolower(Letter);
		//if the letter is in map
		if (LetterSeen[Letter]) {
			return false;
		} else {
			// add letter to a map
			LetterSeen[Letter] = true;
		}
	}	
	return true; //for basis of 0 letters entered.
}

void FBullCowGame::Reset() {
	constexpr int32 MAX_TRIES = 3;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessWordStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
	//if guess isnt isogram, return error
	if (!IsIsogram(Guess)) {
		return EGuessWordStatus::Not_Isogram;
	}
	//if guess isnt all lowercase, return error
	else if (false) {
		return EGuessWordStatus::Not_Lowercase;
	}
	//if guess length is wrong, retun error
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessWordStatus::Wrong_Length;
	}
	//else return ok
	else {
		return EGuessWordStatus::OK;
	}
}

//receives valid guess, incerements turn, and counts bulls and cows
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCountVar;
	int32 WordLength = MyHiddenWord.length();

	//loop through all chars of hidden word
	for (int32 MyHiddenChar = 0; MyHiddenChar < WordLength; MyHiddenChar++) {

		//compare letters against guess
		for (int32 GuessChar = 0; GuessChar < WordLength; GuessChar++) {
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
	if (BullCowCountVar.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCountVar;
}

