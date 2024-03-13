//Card interface file
#ifndef __CARD_H__
#define __CARD_H__

#include <iostream>

using namespace std;

class Card {
 private:
    char suit;
    int rank;
 public:

    Card();
    Card(char s, int r);

    char getSuit() const;
    
    int getRank() const;
    
    friend ostream & operator<<(ostream &os, const Card &card);
};

#endif