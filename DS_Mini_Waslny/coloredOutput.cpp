#pragma once

#include <iostream>
#include <Windows.h>

using namespace std;

inline void failureMessage(string message)
{
	// Arrow
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 79);
	cout << "-> ";

	// message
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244); // 116 - 244 - 207
	cout << ' ' << message;

	// return to the default theme
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
}

inline void successMessage(string message)
{
	// Arrow
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 47);
	cout << "-> ";

	// message
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 242); // 114 - 242 - 175
	cout << message;

	// return to the default theme
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
}