#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <vector>
#include "player.hpp"
#include "card.hpp"

#define START_STACK 26;
/*
    create and initialize array[26] of vector in when game is created
    ***fix throw error if two player is the same one
*/
namespace ariel{
    class Game {

        public:
            Player &p1;
            Player &p2;
            std::vector<Card> deck;
            std::string game_log;
            std::string log_last;
            int draw_counter;
            int curr_draw_counter;
            int turn_counter;
            int max_draw;
            int p1_win;
            int p2_win;
            //constructors
            Game(Player &player1, Player &player2):p1(player1), p2(player2)
            {
                deck = ariel::Card::buildDeck();
                p1.stack_left = START_STACK;
                p2.stack_left = START_STACK;
                p1.cards_taken = 0;
                p2.cards_taken = 0;
                p1_win = 0;
                p2_win = 0;
                game_log = "";
                draw_counter = 0;
                turn_counter = 0;
                curr_draw_counter = 0;
            };
            int getTurn(){return turn_counter;}
            bool isFinished(){return (p1.stacksize() == 0 && p2.stacksize() ==0);}
            int playCards(unsigned int t, std::string &str);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
 
    };
}
#endif