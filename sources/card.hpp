#include <iostream>
#include <vector>

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

enum result {Lost = -1, Draw, Win};
/*
    card contain rank and suit
    card class contain all action on cards
*/

namespace ariel{
    class Card {
        private:
            Rank rank;
            Suit suit;
        public:

            Card(Suit s, Rank r){
                rank = (Rank)r;
                suit = (Suit)s;
                
            };
            int getRank(){ return rank; }
            int getSuit(){ return suit; }
            static std::vector<Card> buildDeck();   //inside building it's shuffling
            std::string cardString(Card d);
            int compareCards(Card d1, Card d2);

    };
}

