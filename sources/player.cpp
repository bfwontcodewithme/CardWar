#include <iostream>
#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
using namespace ariel;


std::string ariel::Player::playerMove(Card other){
    std::string str = "";
    str += this->getPlayer();
    str += " played ";
    str += other.cardString();
    str += ". ";
    return str;
}