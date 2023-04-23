#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("jksks"){
    Player p1("Alice");
    Player p2("Bob");

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);

};