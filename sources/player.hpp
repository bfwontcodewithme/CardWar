#include <iostream>

namespace ariel{
    class Player {
        public:
            std::string name;
            
            //constructors
            Player(std::string player_name){
                name = player_name;
            };
            Player(){
                name = "John";
            }

            int stacksize() { return 0; }
            int cardesTaken(){ return 0; }

    };
}
