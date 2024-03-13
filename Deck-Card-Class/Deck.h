#ifndef __DECK_H__
#define __DECK_H__

#include <vector>
using namespace std;

#include "Card.h"

class Deck {
 private:
    vector<Card> theDeck;
    vector<Card> dealtCards;
 public:
    Deck();

    /* Deals (returns) the top card of the deck. 
       Removes this card from theDeck and places it in dealtCards.
       As mentioned in comments for the constructor, 
       for best efficiency, the top card should come from the 
       back end of vector.
    */
    Card dealCard();


    /* Places all cards back into theDeck and shuffles them into random order.
       Use random_shuffle function from algorithm library.
       To pass test harness, this function must go forward through dealtCards
       pushing each Card onto the back end of theDeck, then clear dealtCards.
       Do not use pop_back on dealtCards.
    */
    void shuffleDeck();


    /* returns the size of the Deck (how many cards have not yet been dealt).
    */
    unsigned deckSize() const;
};

#endif

