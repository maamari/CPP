#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;


// sum an array of numbers
int test1(int *data, int len)
{
  int sum = 0;
  for(int i=0; i < len; i++){   // deleted = from <=. array was overloaded.
    sum += data[i];
  }

  delete [] data; // deallocate data
  return sum;
}

char* test2_init(int len)
{
  char buf[80];
  cout << "Enter a word: ";
  cin >> buf;
  char* mydat = new char[strlen(buf)+1];
  strcpy(mydat, buf);
  return mydat;
}

char* test2_reverse(char* word)
{
  int len = strlen(word);
  char* otherword = new char[len+1];

  for(int i=0; i < strlen(word); i++){
    otherword[i] = word[len-i-1];
  }
  otherword[len] = '\0';  // +1 was going over the array size
  delete [] word;
  return otherword;
}

int main(int argc, char* argv[])
{
  if(argc < 2){
    cerr << "Please enter the test number you want to run [1-2]" << endl;
    return 1;
  }
  const int len = 7;
  int test = atoi(argv[1]);

  if(test == 1){
    int *data = new int[len];
    for(int i=0; i < len; i++){
      data[i] = rand()%100;
    }
    int sum = test1(data, len);
    cout << "Test 1 sum is " << sum << endl;

  }

  else if(test == 2){
    char* myword = test2_init(len);
    cout << "myword is " << myword << endl;

    char* otherword = test2_reverse(myword);
    cout << "otherword is " << otherword << endl;


    //delete [] myword;   myword never allocated
    delete [] otherword;
  }
  else {
    cout << "Unknown test number" << endl;
  }

  return 0;
}

// test1
//   deallocate array
//   deleted the = sign that was accessing memory past the end of the array

// test2
//   +1 in otherword was going over array size.
//   new myword was never allocated so no need to deallocate