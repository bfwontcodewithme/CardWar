#include <iostream>

namespace ariel{
    class Game {

        public:
            Player p1;
            Player p2;

            //constructors
            Game(Player player1, Player player2){
                p1 = player1;
                p2 = player2;
            }
            Game(){         //default game with deafult names
                p1 = Player();
                p2 = Player();
            }

            void playTurn(){};
            void printLastTurn(){};
            void playAll(){};
            void printWiner(){};
            void printLog(){};
            void printStats(){};
 
    };
}