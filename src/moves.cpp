#include "moves.hpp"
#include<iostream>
using namespace std;

bool parseMove(string &input, Move &m)
{
   int sr, sc, er, ec;
   sr = 8 - (input[1] - '0');
   sc = input[0] - 'a';
   er = 8-(input[3] - '0');
   ec = input[2] - 'a';
   if(!(sr>=0 && sr<8 && sc>=0 && sc<8 && er>=0 && er<8 && ec>=0 && ec<8))return 0;
   m.sr = sr;
   m.sc = sc;
   m.er = er;
   m.ec = ec;

   return 1;
}

string moveToString(Move &m)
{
    string s(4, 0);
    s[0] = m.sc + 'a';
    s[1] = 8 - m.sr + '0';
    s[2] = m.ec + 'a';
    s[3] = 8 - m.er +  '0';
    return s;
}
