#pragma once
#include<string>

struct Move
{
    int sr, sc, er, ec;
};

bool parseMove(std::string &input, Move &m);
std::string moveToString(Move &m);
