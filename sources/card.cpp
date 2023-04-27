#include <iostream>
#include "card.hpp"
#include <vector>
#include <algorithm>
using namespace ariel;

std::vector<Card> ariel::Card::buildDeck(){
    //creating empty vector
    std::vector<Card> deck;
    
    //adding all card to vector
    for (int i = 0; i < 13; i++){
        for(int j = 0; j < 4; j++){
            deck.push_back(Card((Suit)j,(Rank)i));  //cast i&j as suit&rank
        }
    }
    //shuffling
    srand(time(0));
    std::random_shuffle(deck.begin(),deck.end());
    return deck;
};

/*return string of the card ___(rank) of ___(suit)*/
std::string ariel::Card::cardString(Card d)
{
    std::string str = "";
    switch (d.getRank())
    {
    case ACE:
        str += "Ace";
        break;
    case KING:
        str += "King";
        break;
    case QUEEN:
        str += "Queen";
        break;
    case JACK:
        str += "Jack";
        break;
    default:
        str += std::to_string(d.getRank());
        break;
    }
    str += "of";
    switch (d.getSuit())
    {
    case CLUBS:
        str += "Clubs";
        break;
    case DIAMONDS:
        str += "Diamonds";
        break;
    case HEARTS:
        str += "Hearts";
        break;
    case SPADES:
        str += "Spades";
        break;
    }
    return str;
}

int ariel::Card::compareCards(Card d1, Card d2) //win or lose defined by p1
{
    // p1 have ace
    if(d1.getRank() == 1){
        if(d2.getRank() == 2){return -1;}       //lose to 2
        else if(d1.getRank() == 1){return 0;}   //draw if equal
        else return 1;                          //anything else ace is winner
    }
    else if(d1.getRank() == 2){                 
        if(d2.getRank() == 1){return 1;}        //is p1 has 2 and p1 ace, it's a win
        else if(d2.getRank() == 2){return 0;}   //draw if equal
        else return -1;                         //anything else 2 is smaller and it's a lose
    }
    else if(d1.getRank() == d2.getRank()){return 0;}    //any other number if draw
    else return d1.getRank() > d2.getRank() ? 1 : -1;   //any other number if not draw, if true it's a win
}

