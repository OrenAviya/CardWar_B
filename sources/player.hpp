#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel{}
using namespace ariel;

class Player{
    private:
        string name;
        vector <Card> stack;
        int Stsize;
        int cardesTakes;
        
    public:

    // define inline
    string getName() {return (name);}
    // define in cpp file
    void setName (string n) ;

// // Constructors:
    Player() : name{"defult"} , Stsize{0} , cardesTakes{0}  
      {
      //std::cout << "defult player" << std::endl; 

    }

    Player(string name):
   // std::cout << "Player: "+ std::to_string(z) << std::endl; 
    name {std::move(name)}  , Stsize{0} , cardesTakes{0} 
    {
    
    }

    int& stacksize();
    int &cardesTaken();
    vector <Card>& GetStack();
    void SetStacksize(int num){
    this->Stsize =  num;
    }
    void SetCardesTaken(int num){
    this->cardesTakes = num;
    }
    // Card& setStackValuesAt( Card c ) ;
    // void SetStack(list<Card> cardsToAdd);
};
