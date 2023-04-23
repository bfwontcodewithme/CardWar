#include "doctest.h"
#include <stdexcept>
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;

TEST_CASE("Checking condition before starting the game"){
    Player p1("Alice");
    Player p2("Bob");

    Game g(p1,p2);
    Game g1(p1,p1);

    CHECK(p1.cardesTaken() == 0);
    CHECK(p2.cardesTaken() == 0);
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
    
    CHECK_NOTHROW(g.playTurn());
    CHECK_NOTHROW(g1.playTurn());

};

TEST_CASE("player gets cards"){         //52 cards total
    Player p1("Alice");
    Player p2("Bob");
    Game g(p1,p2);
    int total_cards;

    CHECK(p1.stacksize() == 26);    //get start cards
    CHECK(p1.cardesTaken() == 0);   //before playing any turn
    CHECK(p2.stacksize() == 26);
    CHECK(p2.cardesTaken() == 0);
    total_cards = p1.stacksize() + p2.stacksize();
    CHECK(total_cards == 52);
};

TEST_CASE("during the game"){
    Player p1("Alice");
    Player p2("Bob");
    Game g(p1,p2);

    CHECK_NOTHROW(g.playTurn());

    CHECK_NOTHROW(g.printLastTurn());
    CHECK_NOTHROW(g.playAll());
    CHECK_NOTHROW(g.printWiner());
};
TEST_CASE("checking printing logs and stats"){
    Player p1("Alice");
    Player p2("Bob");
    Game g(p1,p2);
    g.playAll();
    
    CHECK_NOTHROW(g.printLog());
    CHECK_NOTHROW(g.printStats());
    CHECK_NOTHROW(g.printWiner());
};

TEST_CASE("game finished"){
    Player p1("Alice");
    Player p2("Bob");
    Game g(p1,p2);

    g.playAll();
    int total;
    total = p1.cardesTaken() + p1.stacksize() + p2.cardesTaken() + p2.stacksize();
    CHECK(total == 52);   //checking for total crads

    CHECK_THROWS(g.playTurn()); //not posibble after game finished

};