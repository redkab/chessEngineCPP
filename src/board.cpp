#include "board.hpp"

#include<iostream>
using namespace std;

Board::Board()
{
    reset();
}

void Board::reset()
{
    char startPos[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}, 
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'}, 
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'}, 
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };
    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            b[i][j] = startPos[i][j];
        }
    }
}

void Board::print()
{
    for(int i=0; i<8; i++)
    {
        cout<<8-i<<"  ";
        for(int j=0; j<8; j++)
        {
            cout<<b[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<"\n   a b c d e f g h\n\n";
}

bool Board::isInside(int row, int col)
{
    return (row>=0 && row<7 && col>=0 && col<8);
}

bool Board::isEmpty(int row, int col)
{
    if(!isInside(row, col))return 0;
    return b[row][col] == ' ';
}

char Board::getPiece(int row, int col)
{
    if(!isInside(row, col))return '\0';
    return b[row][col];
}

void Board::setPiece(int row, int col, char piece)
{
    if(!isInside(row, col))return;
    b[row][col] = piece;
}

