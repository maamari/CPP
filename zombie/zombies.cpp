/********************************************************
 * CS 103 Zombie-pocalypse PA
 * Name: Karime Maamari
 * USC email: maamari@usc.edu
 * Description:
 * This program will demonstrate the number of nights that
 * it will take for a zombie apoclypse to finish
 ********************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <climits>
using namespace std;

const int MAXPOP = 100000;

int main()
{
  bool pop[MAXPOP];

  int N, k, M, seed, nights, max_nights = 0,            //variable declarations
      min_nights = INT_MAX, sum_nights = 0, personBit = 0;
  double avg_nights = 0.0;

  cout << "Enter the following: N k M seed" << endl;    //inputs
  cin >> N >> k >> M >> seed;

  int temp = M;
  int temp2 = k;

  srand(seed);

  for(int sims = 0; sims < M; sims++){ //goes through number of simulations
    nights = 0;
    k = temp2;

    for(int i = 0; i < temp2; i++){    //initializes first k values as zombies
      pop[i] = true;
    }

    for(int i = temp2; i < N; i++){    //initializes last N-k values as humans
      pop[i] = false;
    }

    while(k < N){                      //while there are still humans
      int newZomb = 0;

      for(int zombie = 0; zombie < k; zombie++){    //iterate through one night
        personBit = rand() % N;
        if(pop[personBit] == false){   //if person isn't bit yet, bite them
          pop[personBit] = true;
          newZomb++;                   //increment the number of new zombies
        }
      }
      nights++;
      k += newZomb;                    //update number of total zombies
    }

    if(nights > max_nights){           //update max
      max_nights = nights;
    }

    if(nights < min_nights){           //update min
      min_nights = nights;
    }

    sum_nights += nights;              //update sum
  }
  avg_nights = (double)sum_nights/temp;   //calculate the average

  cout << "Average Nights: " << avg_nights << endl;     //outputs
  cout << "Max Nights: " << max_nights << endl;
  cout << "Min Nights: " << min_nights << endl;
  return 0;
}
