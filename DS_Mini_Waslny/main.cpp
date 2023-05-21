// DS_Mini_Waslny.cpp : This file contains the 'main' function. Program execution begins and ends there.
#pragma once
#include <iostream>
#include <string>
#include "graph.h"
#include "algorithms.h"
#include "homePage.h"
#include <list>
#include <utility>
#include <unordered_map>
#include "files.h"
#include "dashboard.h"
#include <queue>

using namespace std;
unordered_map<string, graph> maps;

int main() {

    maps = readMultipleGraphs(".\\");

    homePage(maps);

    writeMultipleGraphs(maps, ".\\");

    return 0;
}
