#include <iostream>
#include <vector>

enum Suit {CLUBS, DIAMONDS, HEARTS, SPADES};

enum Rank {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

namespace ariel{
    class Card {
    
        public:
            Rank rank;
            Suit suit;

            Card();
            Card(Suit s, Rank r){
                rank = r;
                suit = s;
                
            };
            void buildDeck();
            void shuffleDeck();



    
    };
}

// card is a vector (rank, suit, owner, turn,..turn2, t3...)