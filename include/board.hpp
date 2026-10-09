#pragma once

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
};
