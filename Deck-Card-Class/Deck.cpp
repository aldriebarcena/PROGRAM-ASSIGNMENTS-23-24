#include <iostream>
#include <algorithm>
#include <random>
using namespace std;

#include "Deck.h"

// Deck.h
Deck::Deck()
{
  vector<char> suits = {'c', 'd', 'h', 's'};
  char s;

  for (size_t i = 0; i < 4; i++)
  {
    s = suits.at(i);
    for (size_t j = 1; j <= 13; j++)
    {
      theDeck.push_back(Card(s, j));
    }
  }

  reverse(theDeck.begin(), theDeck.end());
}

Card Deck::dealCard()
{
  Card dealtCard;

  dealtCard = theDeck.back();
  dealtCards.push_back(theDeck.back());
  theDeck.pop_back();

  return dealtCard;
}

void Deck::shuffleDeck()
{
  for (size_t i = 0; i < dealtCards.size(); ++i)
  {
    theDeck.push_back(dealtCards.at(i));
  }
  dealtCards.clear();

  random_shuffle(theDeck.begin(), theDeck.end());
}

unsigned Deck::deckSize() const
{
  return static_cast<unsigned int>(theDeck.size());
}