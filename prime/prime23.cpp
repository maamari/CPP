#include <iostream>
#include <cmath>
using namespace std;

int main() {

  cout << "Enter a positive integer: ";
  int num;
  int twos = 0;
  int threes = 0;
  cin >> num;

  while((num % 2 == 0) || (num % 3 == 0))
    {
    if (num % 2 == 0) {
       twos++;
       num /= 2;
     }
    else if (num % 3 == 0) {
        threes++;
        num /= 3;
     }
    }
    if(num > 1)
    {
      cout << "No" << endl;
    }
    else{
    cout << "Yes" << endl << "Twos=" << twos << " " << "Threes=" << threes << endl;
    }

    return 0;
}
