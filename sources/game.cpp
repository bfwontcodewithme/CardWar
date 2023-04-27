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

/*the function advanced the index by one, then comaparing the card and decide the result  */
void ariel::Game::playTurn(){
    //show cards (index) 
    //compare
    //get result
    //if draw enter another draw ( move index and show cards again)
    //add cards to winner
    //loser lost cards

};
/*
// print the last turn stats. For example:
    Alice played Queen of Hearts Bob played 5 of Spades. Alice wins.
    Alice played 6 of Hearts Bob played 6 of Spades. Draw. 
    Alice played 10 of Clubs Bob played 10 of Diamonds. draw. 
    Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
*/
void ariel::Game::printLastTurn(){

};
/*calling the play turn fto play a whole game, in loop int i=0 ;i<26 */
void ariel::Game::playAll(){

};

void ariel::Game::printWiner(){

};

/*prints all the turns played one line per turn (same format as game.printLastTurn())*/
void ariel::Game::printLog(){

};
// for each player prints basic statistics: win rate, cards won, <other stats you want to print>. Also print the draw rate and amount of draws that happand. (draw within a draw counts as 2 draws. )
void ariel::Game::printStats(){

};