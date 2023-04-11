
#include "game.hpp"
#include "card.hpp"
#include "player.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using namespace std;
namespace ariel{}
using namespace ariel;



void Game :: playTurn(){
    if (GameOver)
        throw invalid_argument("Game has already ended");
    if (this->AllTurns.size() > 51){
         throw invalid_argument("There is no option to more than 52 turns");
    }

if ( !this->AllTurns.empty() && this->AllTurns.back() != "\n "+this->LastTurn ) 
    this->AllTurns.push_back( "\n "+this->LastTurn);
bool stopturn = false;
int num_of_rounds =0;

    if (p1.stacksize() >0 && p2.stacksize() >0){
         GameOver = false;
        // each player play a card
        Card card1 = p1.GetStack().back();
        Card card2 = p2.GetStack().back();
        // delete this card from the stacks 
        // //and update the stacksize
        // p1.GetStack().back();
        // p2.GetStack().back();

        p1.SetStacksize(p1.stacksize()-1);
        p2.SetStacksize(p2.stacksize()-1);

// special - Ace:
        if (card1.GetRank() == 0 &&  card2.GetRank()!= 1 && !stopturn){
            //p1 won the 2 cards
            p1.SetCardesTaken(p1.cardesTaken()+2);
            //update "last turn"
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString() +". "+ p1.getName()+" wins");
            AddToWinners( p1.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn=true;
        }
         if (card2.GetRank() == 0 &&  card1.GetRank()!= 1 && !stopturn){
            //p2 won the 2 cards
            p2.SetCardesTaken(p2.cardesTaken()+2);
            //update "last turn"
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString() + ". "+ p2.getName()+" wins");
            AddToWinners( p2.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn=true;
         }
        
         else if (card1.GetRank() < card2.GetRank() && !stopturn){
            //p2 won the 2 cards
            p2.SetCardesTaken(p2.cardesTaken()+2);
            //update "last turn"
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString() + ". "+ p2.getName()+" wins");
            AddToWinners( p2.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn=true;
        }

        else if (card1.GetRank() > card2.GetRank() && !stopturn){
            //p1 won the 2 cards
            p1.SetCardesTaken(p1.cardesTaken()+2);
            //update "last turn"
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString() +". "+ p1.getName()+" wins");
            AddToWinners( p1.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn=true;
        }
        if (p1.stacksize() ==1  && p2.stacksize() ==1 && (card1.GetRank() == card2.GetRank() ) && !stopturn){
           p1.SetCardesTaken(p1.cardesTaken() +1);
            p2.SetCardesTaken(p2.cardesTaken() +1);

         p1.GetStack().pop_back();
        p2.GetStack().pop_back();
    //and update the stacksize
        p1.SetStacksize(p1.stacksize()-1);
        p2.SetStacksize(p2.stacksize()-1);
        GameOver=true;
        stopturn=true;
        }
        
        while ((card1.GetRank() == card2.GetRank() ) &&  p1.stacksize() >1 &&  p2.stacksize() >1 && !GameOver && !stopturn){
            (this-> num_of_draws) ++;
             num_of_rounds ++;
            //update "last turn":
            this->LastTurn  = (p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString()+". Draw. ");
             this->AllTurns.push_back( "\n "+this->LastTurn);

            // Alice played 6 of Hearts Bob played 6 of Spades. Draw. Alice played 10 of Clubs Bob played 10 of Diamonds.
            // draw. Alice played Jack of Clubs Bob played King of Diamonds. Bob wins.
        
            // another close and open cards , and if again:
        // delete one card (the close) from the stacks 
        p1.GetStack().pop_back();
        p2.GetStack().pop_back();
    //and update the stacksize
        p1.SetStacksize(p1.stacksize()-1);
        p2.SetStacksize(p2.stacksize()-1);
        // the open - 
        Card card1 = p1.GetStack().back();
        Card card2 = p2.GetStack().back();
        // //delete from stack and updete...
        // p1.GetStack().back();
        // p2.GetStack().back();

        p1.SetStacksize(p1.stacksize()-1);
        p2.SetStacksize(p2.stacksize()-1);

        // special - Ace:
        if (card1.GetRank() == 0 &&  card2.GetRank()!= 1 && !stopturn){
            //p1 won the 2 cards
            p1.SetCardesTaken(p1.cardesTaken()+(2+4*num_of_rounds));
            //update "last turn"
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString() +". "+ p1.getName()+" wins");
             this->AllTurns.push_back( "\n "+this->LastTurn);
            AddToWinners( p1.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn = true;
        }
         if (card2.GetRank() == 0 &&  card1.GetRank()!= 1 && !stopturn){
            //p2 won the 2 cards
            p2.SetCardesTaken(p2.cardesTaken()+(2+4*num_of_rounds));
            //update "last turn"
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played " + card2.ToString() + ". "+ p2.getName()+" wins");
             this->AllTurns.push_back( "\n "+this->LastTurn);
            AddToWinners( p2.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn = true;
         }

        else if (card1.GetRank() < card2.GetRank() && !stopturn){
            //p2 won all the cards
            p2.SetCardesTaken(p2.cardesTaken()+(2+4*num_of_rounds));
            this->LastTurn = (p1.getName() + " played " + card1.ToString() +
            " "+ p2.getName()+ " played "+ card2.ToString() +". "+ p2.getName()+" wins");
             this->AllTurns.push_back( "\n "+this->LastTurn);
            AddToWinners(p2.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn = true;

        }

        else if (card1.GetRank() > card2.GetRank() && !stopturn){
            //p1 won all the cards
            p1.SetCardesTaken(p1.cardesTaken()+(2+4*num_of_rounds));
            this->LastTurn =(p1.getName() + " played " + card1.ToString() +" "+ p2.getName()+ " played " 
            + card2.ToString() +". "+ p1.getName()+" wins");
             this->AllTurns.push_back( "\n "+this->LastTurn);
            getWinners().push_back(p1.getName());
            // delete the cards from stack 
            p1.GetStack().pop_back();
            p2.GetStack().pop_back();
            stopturn = true;
        }
        
        if (p1.stacksize() == 0 || p2.stacksize()==0 && !GameOver ){
           p1.SetCardesTaken (p1.cardesTaken() + ((2+4*num_of_rounds)/2));
            p2.SetCardesTaken(p2.cardesTaken() +  ((2+4*num_of_rounds)/2)) ;   
            GameOver = true;
        }
        }
    }
     if ((p1.stacksize() == 0 || p2.stacksize()==0 ) && !GameOver)
        GameOver = true;


if (GameOver){
    if ( p1.cardesTaken() > p2.cardesTaken()){
        AddToWinners( p1.getName());
    }
    if (p1.cardesTaken() < p2.cardesTaken()){
        AddToWinners( p2.getName());
    }
    else if ( p1.cardesTaken() == p2.cardesTaken()){
        AddToWinners( p1.getName() + " , " + p2.getName());
    }
}

}

void Game :: printLastTurn(){
    cout << LastTurn<< "\n";
}


void Game ::  playAll(){
     if (GameOver)
        throw invalid_argument("Game has already ended");

    while (p1.stacksize() != 0 && p2.stacksize()!=0){
            playTurn();
    }
}

void Game ::  printWiner(){
   if (this->winners.size() == 0){
    throw invalid_argument("error - there is no winner");
   }
   cout<< this->winners.front();

}
void Game :: printLog(){
    // print all turns until now
    for (auto elem : this->AllTurns) {
        cout << elem << ",\n";
    }
    cout << endl;
}


void Game :: printStats(){
    int countWins1 = 0 ;
    int countWins2 = 0 ;
    for (auto element : this->winners){
        if (element == p1.getName()){
            countWins1++;
    }
        if (element == p2.getName()){
        countWins2++;
    }
        else if (element == p1.getName() + " , " + p2.getName()){
            countWins1++;
            countWins2++;
        }
     } 
    cout<< p1.getName() + " has won " << (double)countWins1/26*100 << "\% from turns and "<<
    p2.getName() + " has won " << (double)countWins2/26*100 << "\% from turns. \n";

    cout<< p1.getName() +" has won " << p1.cardesTaken() <<" cards and "
    +p2.getName() +" has won " << p2.cardesTaken() << " cards. \n";

    cout << "number of draws : " << this->num_of_draws;
    cout << " draws rate: " << (double)num_of_draws/26*100<<"\n ";
}

vector<string>& Game::getWinners(){
    return this->winners;
}

string Game ::getLastTurn(){
    return this->LastTurn;
}
int Game:: getdraws(){
    return this->num_of_draws;
}

void Game :: AddToWinners (string name){
    this->winners.push_back(name);
}