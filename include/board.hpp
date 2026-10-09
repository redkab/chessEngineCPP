#pragma once
#include<utility>
#include "move.hpp"
class Board
{
    private:
        char b[8][8];

    public:
        Board();

        void reset();
        void print();
        bool isInside(int row, int col);
        bool isEmpty(int row, int col);
        char getPiece(int row, int col);
        void setPiece(int row, int col, char piece);
        int sgn(int x);
        bool isTeam(std::pair<int, int>a, std::pair<int, int>b);
        bool isValidKnightMove(Move m);
        bool isBlack(std::pair<int, int>s);
        bool isWhite(std::pair<int, int>s);
        bool isValidBishipMove(Move m);
};
