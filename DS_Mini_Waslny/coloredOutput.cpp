#include <iostream>
#include <Windows.h>

using namespace std;

#pragma once

void Error(string message)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 244);
	cout << message;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240);
}