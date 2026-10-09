#include "board.hpp"
#include "moves.hpp"
#include<iostream>
using namespace std;

int main()
{
    Board board;
    board.print();
    Move m;
    string s = "e2e3";
    parseMove(s, m);
    cout<<m.sr<<' '<<m.er<<' '<<m.sc<<' '<<m.ec<<'\n';
    string r = moveToString(m);
    cout<<r<<endl;
}
