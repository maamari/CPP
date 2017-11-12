#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main() {

/*

//step 1
  for(int r = 0; r < 31; r++){
    for (int c = 0; c < r; c++){
      cout << "*";
    }
    cout << "*" << endl;
  }

//step 2
  cout << "Enter a value for theta: ";
  int theta;
  cin >> theta;


  for(int r = 0; r < 31; r++){
  double c2 = tan(theta * (M_PI/180)) * r;
      for (int c = 0; c < c2; c++){
        cout << "*";
    }
    cout << "*" << endl;
  }

*/

//step 3
  cout << "Enter a value for theta: ";
  double theta;
  cin >> theta;


  for(int r = 0; r < 31; r++){
    double c2 = tan(theta * (M_PI/180)) * r;
    if(c2 >= 20 && c2 <= 30){
      c2 = 20;
    }
      for (int c = 0; c < c2; c++){
          cout << "*";
    }
  cout << "*" << endl;
  }
}
