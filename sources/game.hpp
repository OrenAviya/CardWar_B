// #ifndef GAME
// #define GAME 
#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "player.hpp"
#include "card.hpp"
namespace ariel{}
using namespace ariel;

class Game{
    private: 
        Player &p1;
        Player &p2;
        std:: vector <Card> cards_;
        //add something that help to know how won last turn
        string LastTurn;
        vector <string> winners;
        vector<string> AllTurns;
        int num_of_draws;
        bool GameOver;
    public:
//constructors
Game (Player &pl1, Player &pl2) :
    p1(pl1),
    p2(pl2)
  {
  if (p1.stacksize() > 0 || p2.stacksize() > 0) {
        throw invalid_argument("One of players has already registered");
    }
    if(&pl1 == &pl2)
        GameOver = true;
    else 
        GameOver = false;

 // Initialize the deck with 52 cards
        for (int suit = Card::Hearts; suit <= Card::Spades; ++suit) {
            for (int rank = Card::Ace; rank <= Card::King; ++rank) {
                cards_.push_back(Card(static_cast<Card::Suit>(suit), static_cast<Card::Rank>(rank)));
          }
        }
// Shuffle the deck
        std::random_shuffle(this->cards_.begin(), this->cards_.end());

 // Dealing the cards to the two players
    for (int i=0; i<cards_.size()-1  ; i+=2)
    {
      Card c1 = static_cast<Card>(cards_[static_cast<size_t>(i)]);
      Card c2 = static_cast<Card>(cards_[static_cast<size_t>(i+1)]);
      //p1.setStackValuesAt(i)
      p1.GetStack().push_back(c1); 
      p2.GetStack().push_back(c2);

    }
    p1.SetStacksize(p1.GetStack().size());
    p2.SetStacksize(p2.GetStack().size());
    this->LastTurn = "";
    this->num_of_draws= 0;
    
  }  

void playTurn();
void printLastTurn();

void playAll();
void printWiner(); 
void printLog();
void printStats();
void AddToWinners (string name);
vector<string>& getWinners();
string getLastTurn();
int getdraws();

};

// #endif GAME
