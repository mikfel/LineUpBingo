#include "cNumberOfMoves.h"

cNumberOfMoves::~cNumberOfMoves()
{
    //dtor
}

cNumberOfMoves cNumberOfMoves::operator++(int n)
{
    cNumberOfMoves temp = *this;
    if (n!=0)
        value+= n;
    else
        value++;
   return temp;
}
cNumberOfMoves cNumberOfMoves::operator--(int n)
{
    cNumberOfMoves temp = *this;
    if (n!=0)
        value-= n;
    else
        value--;
   return temp;
}
