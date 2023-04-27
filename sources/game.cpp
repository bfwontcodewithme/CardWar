/* the game itself calls for: 
builddeck(?) 
shuffledeck 
creating array of vector that randomaly assigned the card's index - index 0 to 25 is p1 stack
index 26 to 51 is p2 stack, by the index we know the card's turn


*/
#include <iostream>
#include "player.hpp"
#include "card.hpp"
#include "game.hpp"
using namespace ariel;


void ariel::Game::playTurn(){
    //show cards (index) 
    //compare
    //get result
    //if draw enter another draw ( move index and show cards again)
    //add cards to winner
    //loser lost cards
    if(p1.name == p2.name) throw std::string{"\nMissing player 2\n"};
    if(isFinished()) throw std::string{"\nGame Finished\n"};
    unsigned int index = 0;
    int max_draw = 0;
    int curr_turn = getTurn() +1;
    int res = playCards(index, log_last);
     //result of p1
    while(res == 0 &&  curr_turn<26){
        //draw
        log_last += "Draw.\n";
        draw_counter += 1;
        curr_draw_counter += 1;
        index += 1;
        playCards(index, log_last);

    }
    if(res == -1){
        //p1 lost, p2 win
        p1.stack_left = p1.stack_left - curr_draw_counter-1;
        p2.stack_left = p2.stack_left - curr_draw_counter-1;
        p2.cards_taken += curr_draw_counter*2 +2;
        max_draw = max_draw > curr_draw_counter ? max_draw : curr_draw_counter; 
        curr_draw_counter = 0;
        index += 1;
        log_last += p2.getPlayer() + " wins.";
        turn_counter +=  1;
        p2_win += 1;
    }
    else if(res == 1){
        p1.stack_left = p1.stack_left - curr_draw_counter -1;
        p2.stack_left = p2.stack_left - curr_draw_counter -1;
        p1.cards_taken += curr_draw_counter*2 +2;
        max_draw = max_draw > curr_draw_counter ? max_draw : curr_draw_counter; 
        curr_draw_counter=0;
        index += 1;
        log_last += p1.getPlayer() +" wins.";
        turn_counter += 1;
        p1_win += 1;
    }
    else {
        //ending in draw
    }
    game_log += log_last + "\n";
    
};
int ariel::Game::playCards(unsigned int turn, std::string &log_last){
    log_last += p1.playerMove(deck.at(turn));
    log_last += p2.playerMove(deck.at(turn + 26));
    int res = deck.at((turn)).compareCards(deck.at(turn + 26));
    return res;
}
/*
// print the last turn stats. For example:
    Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
    Alice played 6 of Hearts Bob played 6 of Spades. Draw. 
    Alice played 10 of Clubs Bob played 10 of Diamonds. draw. 
    Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
*/
void ariel::Game::printLastTurn(){
    std::cout << log_last;
};
/*calling the play turn until isFinished is true */
void ariel::Game::playAll(){
    do{
        Game::playTurn();
    }while(!isFinished());
};

void ariel::Game::printWiner(){
    if(isFinished()){
        std::string winner = "";
        if(p1.cardesTaken() == p2.cardesTaken()) std::cout << "It's a tie.\n";
        else if(p1.cardesTaken() > p2.cardesTaken()) winner += p1.getPlayer();
        else winner += p2.getPlayer();
        std::cout << winner << " won.";
    }
    
};

/*prints all the turns played one line per turn (same format as game.printLastTurn())*/
void ariel::Game::printLog(){
    std::cout << game_log;
};
// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
void ariel::Game::printStats(){
    std::cout << "Printing Stats: \n";
    std::cout << draw_counter <<" draws.\n";
    std::cout << max_draw << " draws in one turn\n";
    std::cout << "Game ended after " << turn_counter << " turn.\n";

};
