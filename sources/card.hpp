//#ifndef Card
//#define Card
#pragma once
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
//#include "player.hpp"
namespace ariel{}
using namespace ariel;


class Card {
    public:
    enum Suit { Hearts, Diamonds, Clubs, Spades };
    enum Rank { Ace, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

    Card(Suit suit, Rank rank) : suit_(suit), rank_(rank) {}
 
 // Getters for suit and rank
    Suit GetSuit() const { return suit_; }
    Rank GetRank() const { return rank_; }

 // String representation of the card
    std::string ToString() const {
        std::string suit_str, rank_str;

 switch (suit_) {
            case Hearts:   suit_str = "Hearts";   break;
            case Diamonds: suit_str = "Diamonds"; break;
            case Clubs:    suit_str = "Clubs";    break;
            case Spades:   suit_str = "Spades";   break;
        }

        switch (rank_) {
            case Ace:   rank_str = "Ace";   break;
            case Two:   rank_str = "2";   break;
            case Three: rank_str = "3"; break;
            case Four:  rank_str = "4";  break;
            case Five:  rank_str = "5";  break;
            case Six:   rank_str = "6";   break;
            case Seven: rank_str = "7"; break;
            case Eight: rank_str = "8"; break;
            case Nine:  rank_str = "9";  break;
            case Ten:   rank_str = "10";   break;
            case Jack:  rank_str = "Jack";  break;
            case Queen: rank_str = "Queen"; break;
            case King:  rank_str = "King";  break;
        }

        return rank_str + " of " + suit_str;
    }

        private:
    Suit suit_;
    Rank rank_;
};



//#endif Card