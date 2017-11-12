/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Karime Maamari
 * USC email: maamari@usc.edu
 * Comments: Use command line to seed (./twentyone 37)
 ******************************************************************************/

#include <iostream>
#include <cstdlib>

using namespace std;

void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

const char suit[4] = {'H','S','D','C'};
const char* type[13] = {"2","3","4","5","6","7",
                        "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};


void shuffle(int cards[]){            //shuffle function
  int j, temp;

  for(int i = 0; i < NUM_CARDS; i++){ //initialize cards
    cards[i] = i;
  }

  for(int i = 51; i > 0; i--){        //randomize
    j = (rand() % (i+1));
    temp = cards[i];
    cards[i] = cards[j];
    cards[j] = temp;
  }
}


void printCard(int id)                //prints single card
{
  cout << type[id % 13] << "-";       //output number

  if(id < 13){                        //output suit
    cout << suit[0];
  }
  if(id >= 13 && id < 26){
    cout << suit[1];
  }
  if(id >= 26 && id < 39){
    cout << suit[2];
  }
  if(id >= 39 && id < 52){
    cout << suit[3];  
  }
}


int cardValue(int id)                 //returns value of card
{
  return value[id % 13];
}


void printHand(int hand[], int numCards) //prints all cards in hand
{
  for(int i = 0; i < numCards; i++){  
    printCard(hand[i]);
    cout << " ";
  }
  cout << endl;
}


int getBestScore(int hand[], int numCards){ //outputs score
  int score = 0;                      

  for(int i = 0; i < numCards; i++){  //add value of each card to total score
    score += cardValue(hand[i]);
  }

  if(score > 21){                     //if you bust
    for(int i = 0; i < numCards; i++){
      if(cardValue(hand[i]) == 11){   //and you have an ace
        score -= 10;                  //change value to 1
      }
    }
  }
  return score;
}


int main(int argc, char* argv[])
{

  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------


  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);

  int cards[52];
  int dhand[9];
  int phand[9];


  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------
                                        
    char hitStay;                      //whether user hits or stays
    char yesNo = 'y';                  //play again?
    int element = 0;                   //position in deck
    int countP = 2;                    //number of cards player has
    int countD = 2;                    //number of cards dealer has

while(yesNo == 'y'){

  countP = 2;                          //reset variables at top of each loop
  countD = 2;
  element = 0;
  hitStay = 'x';

  shuffle(cards);                      //shuffle
       
  phand[0] = cards[element++];         //deal cards
  dhand[0] = cards[element++];
  phand[1] = cards[element++];
  dhand[1] = cards[element++];

  cout << "Dealer: "; 
  cout << "? ";
  printCard(dhand[1]);
  cout << endl;

  cout << "Player: ";
  printHand(phand, countP);

    while(getBestScore(phand, countP) <= 21 && hitStay != 's'){

      if(getBestScore(phand, countP) != 21){
        cout << "Type 'h' to hit and 's' to stay: " << endl;
        cin >> hitStay;
      }

      else if(getBestScore(phand, countP) == 21){
        hitStay = 's';
      }

      if(hitStay == 'h'){                 //if you hit
        countP++;                         
        phand[countP-1] = cards[element]; //deal new card
        element++;                        
        cout << "Player: ";
        printHand(phand, countP);
      }

      if(hitStay == 's'){

        while(getBestScore(dhand, countD) < 17){  //if under 17
          countD++;                         
          dhand[countD-1] = cards[element];       //deal new card
          element++;                       
        }
        cout << "Dealer: ";
        printHand(dhand, countD);


        if(getBestScore(dhand, countD) > 21){     //W/L/T cases
          cout << "Dealer busts" << endl << "Win " << getBestScore(phand, countP)
               << " " << getBestScore(dhand, countD) << endl;
        }
        else if(getBestScore(dhand, countD) > getBestScore(phand, countP)){
          cout << "Lose " << getBestScore(phand, countP) 
               << " " << getBestScore(dhand, countD) << endl;
        } 
        else if(getBestScore(dhand, countD) == getBestScore(phand, countP)){
          cout << "Tie " << getBestScore(phand, countP) 
               << " " << getBestScore(dhand, countD) << endl;
        } 
        else{
          cout << "Win " << getBestScore(phand, countP) 
               << " " << getBestScore(dhand, countD) << endl;
        }
      }

      if(getBestScore(phand, countP) > 21){
        cout << "Player busts" << endl;
        cout << "Lose " << getBestScore(phand, countP) 
             << " " << getBestScore(dhand, countD) << endl;
      }
    }

  cout << endl;
  cout << "Play again? [y/n]: " << endl;
  cin >> yesNo;

  }
return 0;
}
