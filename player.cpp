#include "player.hpp"
using namespace std;

void Player :: setName (string n){
    name = n;
}
int& Player:: stacksize(){
return this->Stsize;
}
int& Player::cardesTaken(){
return this->cardesTakes;
}
/// @brief function that 
/// @param numToOut - how much cards to delete from the stack
// void Player :: SetStack(list<Card> cardsToOut){

// }

// void Player::SetStacksize(int num){
// this->Stsize =  num;
// }
// void Player::SetCardesTaken(int num){
// this->cardesTakes = num;
// }
vector <Card>& Player ::GetStack(){
return this->stack;
}
//  Card& Player :: setStackValuesAt( int i ){
//     return this->stack[i];   // return a reference to the ith element
//  }
 