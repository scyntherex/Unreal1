#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {
public:
	FBullCowGame(); //constructor

	void Reset();

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;

	bool IsGameWon() const;
	bool CheckGuessValidity(FString);
	//provide method for counting bulls and cows, and incresing method number

private:
	//see constructor for initialization
	int32 MyCurrentTry;
	int32 MyMaxTries;
};