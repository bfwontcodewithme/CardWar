#include <iostream>
#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
using namespace ariel;


std::string ariel::Player::playerMove(Card d){
    std::string str = "";
    str += this->getPlayer();
    str += " played ";
    str += d.cardString();
    str += ". ";
    return str;
}