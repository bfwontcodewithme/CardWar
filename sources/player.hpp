#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include "card.hpp"
namespace ariel{
    class Player {
        
        public:
            std::string name;
            int stack_left = 0;
            int cards_taken = 0;
            //constructors
            Player(std::string player_name): name(std::move(player_name)){};

            std::string getPlayer() const {return name;}

            //prints the amount of cards left
            int stacksize() const {return stack_left;}

            // prints the amount of cards this player has won.
            int cardesTaken() const {return cards_taken;}
            std::string playerMove(Card other);
    };
}
#endif