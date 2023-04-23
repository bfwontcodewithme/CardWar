#include <iostream>

namespace ariel{
    class Player {
        std::string name;

        public:

            int stacksize() { return 0; }
            int cardesTaken(){ return 0; }

            //constructors
            Player(std::string player_name){
                name = player_name;
            };
            Player(){
                name = "John";
            }

    };
}
