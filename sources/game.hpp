#include <iostream>

/*
    create and initialize array[26] of vector in when game is created
    ***fix throw error if two player is the same one
*/
namespace ariel{
    class Game {

        public:
            Player p1;
            Player p2;
            std::string game_log;
            std::string log_last;
            int draw_counter;
            int turn_counter;
            bool isFinished;
            //constructors
            Game(Player player1, Player player2){
                this->p1 = player1;
                this->p2 = player2;
                this->game_log = "";
                this->draw_counter = 0;
                this->turn_counter = 0;
                this->isFinished = false;
            };

            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
 
    };
}