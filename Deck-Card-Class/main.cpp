#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

#include "Deck.h"
#include "Card.h"

// Returns true if vector of Cards passed in contains at least 2 Cards with the same rank.
bool hasPair(const vector<Card> &hand)
{
    for (size_t i = 0; i < hand.size(); i++)
    {
        for (size_t j = i + 1; j < hand.size(); j++)
        {
            if (hand.at(i).getRank() == hand.at(j).getRank())
            {
                return true; // Found a pair
            }
        }
    }

    return false; // No pair found
}

// Sends to output stream a hand of Cards on a single line,
// each Card separated by a comma.
// If the vector is empty, do not output anything.
// Example (vector size of 3): Ace of Spades, Two of Hearts, King of Clubs
ostream &operator<<(ostream &os, const vector<Card> &hand)
{
    if (hand.empty())
    {
        return os;
    }

    for (size_t i = 0; i < hand.size(); i++)
    {
        if (i == hand.size() - 1)
        {
            os << hand.at(i);
        }
        else
        {
            os << hand.at(i) << ", ";
        }
    }

    return os;
}

double calculateProbability(int cardsPerHand, int numSims)
{
    int numPairs = 0;
    double probability;
    Deck deck;

    for (int i = 0; i < numSims; i++)
    {
        vector<Card> hand;

        deck.shuffleDeck();

        for (int j = 0; j < cardsPerHand; j++)
        {
            Card dealtCard = deck.dealCard();
            hand.push_back(dealtCard);
        }

        if (hasPair(hand))
        {
            numPairs++;
        }
        hand.clear();
    }

    probability = static_cast<double>(numPairs) / numSims;
    return probability;
}

int main()
{
    srand(2222);

    string outputFile;
    int cardsPerHand, numSims;
    string fileName;

    cout << "Do you want to output all hands to a file? (Yes/No) ";
    cin >> outputFile;
    cout << endl;

    if (outputFile == "No")
    {
        cout << "Enter number of cards per hand: ";
        cin >> cardsPerHand;
        cout << endl;

        cout << "Enter number of deals (simulations): ";
        cin >> numSims;
        cout << endl;

        cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: ";
        cout << calculateProbability(cardsPerHand, numSims) * 100 << "%" << endl;
    }
    else if (outputFile == "Yes")
    {
        cout << "Enter nameof output file: ";
        cin >> fileName;
        cout << endl;

        ofstream outFS;
        outFS.open(fileName);

        cout << "Enter number of cards per hand: ";
        cin >> cardsPerHand;
        cout << endl;

        cout << "Enter number of deals (simulations): ";
        cin >> numSims;
        cout << endl;

        // for outFS
        int numPairs;
        double probability;
        Deck deck;

        for (int i = 0; i < numSims; i++)
        {
            vector<Card> hand;

            deck.shuffleDeck();

            for (int j = 0; j < cardsPerHand; j++)
            {
                Card dealtCard = deck.dealCard();
                hand.push_back(dealtCard);
            }

            if (hasPair(hand))
            {
                numPairs++;
                outFS << "Found Pair!! " << hand << endl;
            }
            else
            {
                outFS << "             " << hand << endl;
            }

            hand.clear();
        }

        probability = static_cast<double>(numPairs) / numSims;

        cout << "Chances of receiving a pair in a hand of " << cardsPerHand << " cards is: ";
        cout << probability * 100 << "%" << endl;
    }

    return 0;
}
