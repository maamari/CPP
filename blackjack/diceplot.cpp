#include <iostream>
#include <cmath>
#include <time.h>
#include <cstdlib>

using namespace std;
int roll();
void printHistogram(int testCounts[]);

int main(){
  srand(time(NULL));

  int testCounts[25];
  for(int i = 4; i < 25; i++){
    testCounts[i] = 0;
  }

  cout << "Enter a value: ";
  int n;
  cin >> n;

  while(n != 0){
  int sumDice = roll() + roll() + roll() + roll();

  testCounts[sumDice]++;
  n--;
  }
  printHistogram(testCounts);
}


int roll(){
  int x;
  x = rand() % 6 + 1;
  return x;
}

void printHistogram(int count[]){

  for(int i = 4; i < 25; i++){
    cout << i << ": ";
    for(int j = count[i]; j > 0; j--){
    cout << 'X';
    }
    cout << endl;
  }
}
