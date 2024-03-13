#include <iostream>
#include <vector>
using namespace std;

#include "Card.h"

// Card.h
Card::Card()
{
  suit = 'c';
  rank = 2;
}

Card::Card(char s, int r)
{
  if (r < 1 || r > 13)
  {
    rank = 2;
  }
  else
  {
    rank = r;
  }

  if (isupper(s))
  {
    s = tolower(s);
  }

  if (s != 's' && s != 'c' && s != 'd' && s != 'h')
  {
    suit = 's';
  }
  else
  {
    suit = s;
  }
}

char Card::getSuit() const
{
  return suit;
}

int Card::getRank() const
{
  return rank;
}

ostream &operator<<(ostream &os, const Card &card)
{

  vector<string> rankNames = {"", "Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10",
                              "Jack", "Queen", "King"};

  string convertedSuit;

  if (card.suit == 'c')
  {
    convertedSuit = "Clubs";
  }
  else if (card.suit == 's')
  {
    convertedSuit = "Spades";
  }
  else if (card.suit == 'd')
  {
    convertedSuit = "Diamonds";
  }
  else if (card.suit == 'h')
  {
    convertedSuit = "Hearts";
  }

  os << rankNames.at(card.rank) << " of " << convertedSuit;

  return os;
}
