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
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.'},
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
    return b[row][col] == '.';
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

int Board::sgn(int x)//priv
{
    return (x>0) - (x<0);
}

bool Board::isBlack(pair<int, int>s)
{
    char c = b[s.first][s.second];
    return c>='a' && c<='z';
}

bool Board::isWhite(pair<int, int>s)
{
    return !isBlack(s);
}

bool Board::isTeam(pair<int, int>a, pair<int, int>b)
{
    if(isBlack(a) && isBlack(b))return 1;
    if(isWhite(a) && isWhite(b))return 1;
    return 0;
}


bool Board::isValidKnightMove(Move m)
{
    int sr = m.sr, sc = m.sc, er = m.er, ec = m.ec;
    if(isTeam({sr, sc}, {er, ec}))return 0;
    return (abs(sr-er)==2 && abs(sc-ec)==1) || (abs(sr-er)==1 && abs(sc-ec)==2);
}

bool Board::isValidBishopMove(Move m)
{
    int sr = m.sr, sc = m.sc, er = m.er, ec = m.ec;
    if(!(abs(sr-er) == abs(sc-ec)))return 0;
    if(sr == er && sc == ec)return 0;
    int dr = er-sr;
    int dc = ec-sc;
    int delr = sgn(dr);
    int delc = sgn(dc);
    int r, c;
    r = sr + delr;
    c = sc + delc;
    while(r != er || c != ec)
    {
        if(b[r][c] != '.')return 0;
        r+=delr;
        c+=delc;
    }
    return !isTeam({sr, sc}, {er, ec}) || b[er][ec] == '.';
}
    
