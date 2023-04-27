#include <iostream>

namespace ariel{
    class Player {
        
        public:
            std::string name;
            int stack_left;
            int cards_taken;
            //constructors
            Player(std::string player_name){
                this->name = player_name;
                this->stack_left = 0;
                this->cards_taken = 0;
            };

            std::string getPlayer(){return name;}

            //prints the amount of cards left
            int stacksize(){return stack;}

            // prints the amount of cards this player has won.
            int cardesTaken(){return cards_taken;}
            std::string playerMove(){};
    };
}
