#ifndef CNUMBEROFMOVES_H
#define CNUMBEROFMOVES_H
#include <iostream>

class cNumberOfMoves
{
private:
    int value;
public:
    cNumberOfMoves() : value(0){}
    virtual ~cNumberOfMoves();
    void display_moves(){std::cout<<"Ilosc rozegranych ruchow: "<<value<<std::endl;}
    void display_reset(){std::cout<<"Wartosc po wyzerowaniu: "<<value<<std::endl;}
    cNumberOfMoves operator++(int n);
    cNumberOfMoves operator--(int n);

};

#endif // CNUMBEROFMOVES_H
