#include <iostream>
#include <cmath>
using namespace std;

/*
-Pick a random element of ordered array
-Set it as initial value of random array
-Remove that element from ordered array
-Go through and find new random element
-Set it as second value of random array
-Remove, repeat
*/


int main(){

  int deck[52];
  int index, temp;

  for(int i = 1; i < 53; i++){
    deck[i-1] = i;
  }

  for (int i = 0; i < 52; i++){
    index = rand() % 52;
    temp = deck[i];
    deck[i] = deck[index];
    deck[index] = temp;
  }

  for (int i = 0; i < 52; i++)
  {
      cout << deck[i] << endl;
  }

  return 0;
}
