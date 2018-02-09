#include <iostream>
#include <sstream>								//stringstream
#include <fstream>								//ifstream and ofstream
#include <string>						
#include <cstdlib>								//atoi, atof, rand
#include <cmath>								//function calls
#include <string.h>								//strncpy
#include "cReview.h"
using namespace std;



//FUNCTION DEFINITIONS
void simplePass(int input1, int input2);
void arrayPass(char array[]);							//overloaded, but okay
//double example(int input1, int input2);			//not okay because func name/arguments are same
void headRecursion(int input);
void tailRecursion(int input);
void objectPass(struc myEx);



//CLASSES
Clas::Clas() {
	for(int i = 0; i < 100; i++){
		classArr[i] = i+1;
	}
	
	classInt = 2;
};

Clas::~Clas(){};

void Clas::classFunc(int num){
	cout << classInt*num << endl;
}



//LINKED LIST
List::List(){};
List::~List(){};

void List::push_back(int v){
	if(head == NULL){
		head = new Item;
		head -> val = v;
		head -> next = NULL;
	}
}
void List::push_front(int v){
	//...
}
void List::pop_back(int v){
	//...
}
void List::pop_front(int v){
	//...
}
void List::find(int v){
	//...
}



//MAIN
int main(int argc, char* argv[]){

	// cout << "C++ REVIEW:" << endl << "--------------------" << endl; 

	// //BASIC DATA TYPES
	// int integer = 16;
	// unsigned int integer2 = 17;
	// double dbl = 2.000000000000001;			
	// float flt = 3.1415926;					
	// string cnvrt = "16";	
	// string word = "one";



	// //MODIFICATIONS
	// cout << "*** MODIFICATION ***" << endl;

	// cout << 5/3 << endl;					
	// cout << 5.0/3 << endl;					
	// cout << (double)5/3 << endl;					//casting

	// word.c_str();								//.c_str()
	// cout << word[0] << endl;

	// int cnvrtd = atoi(cnvrt.c_str());			//atoi
	// cout << dbl/cnvrtd << endl;	

	// int cnvrtd2 = atof(cnvrt.c_str());			//atof
	// cout << integer/cnvrtd2 << endl;

	// cout << endl;



	// //INPUT/OUTPUT
	// cout << "*** I/O ***" << endl;

	// cout << "Please input two integer values: " << endl; 
	// int int1, int2;
	// cin >> int1 >> int2;							//cin
	// cout << int1 << " + " << int2 
	// 	 << " = " << int1+int2 << endl;		

	// cout << "Please enter your full name: " << endl;
	// cin.ignore();								//cin.ignore()
	// string inputName;
	// getline(cin, inputName);						//getline
	// cout << "Hello, " << inputName << endl;
	
	// int in1 = 456789;
	// int in2 = 2;
	// int in3 = 90;

	// ifstream ifile;								//ifstream
	// ifile.open("test.txt");
	// if(ifile.fail()){
	// 	cout << "Couldn't open" << endl;
	// 	return 1;
	// }

	// ifile >> in1 >> in2 >> in3;
	// if(ifile.fail()){
	// 	cout << "Please enter valid values" << endl;
	// 	return 1;
	// }

	// cout << "ice" << in1 << in2 << in3 << endl;
	// ifile.close();

	// stringstream ss;								//streamstream
	// string str;
	// ss << integer;
	// ss >> str;
	// cout << str << endl;
	// str.c_str();
	// cout << str[0] << endl;

	// cout << endl;



	// //FUNCTION CALLS
	// cout << "*** FUNCTION CALLS ***" << endl;

	// cout << sqrt(integer) << endl;
	// cout << pow(2,3) << endl;
	// cout << sin(3*flt/2) << endl;
	// cout << cos(0) << endl;
	// cout << abs(-1) << endl;
	// cout << max(1, 10) << endl;
	// cout << min(1, 10) << endl;

	// cout << endl;



	// //INCREMENT/DECREMENT
	// cout << "*** INCREMENT/DECREMENT ***" << endl;
	
	// int pre = 1;
	// int post = 1;

	// cout << ++pre << endl;
	// cout << post++ << endl;

	// cout << endl;



	// //OPERATORS/CONDITIONALS
	// cout << "*** OPERATORS ***" << endl;

	// bool t = true;
	// bool f = false;
	// int small = 1;
	// int big = 100;

	// if(small == big){
	// 	cout << "equality" << endl;
	// }
	// else if(small != big){
	// 	cout << "inequality" << endl;
	// }
	
	// if(small < big){
	// 	cout << "less than" << endl;
	// }
	// else if(small >= big){
	// 	cout << "greater than/equal to" << endl;
	// }

	// if((!f && t) || f){
	// 	cout << "order or operations: !, &&, ||" << endl;
	// }
	
	// cout << endl;



	// //LOOPS
	// cout << "*** LOOPS ***" << endl;

	// int countdown = 3;
	// while(countdown){							//while
	// 	cout << "while" << endl;
	// 	countdown--;
	// }

	// int countdown2 = 0;
	// do{											//do-while
	// 	cout << "do-while" << endl;
	// }while(countdown2);

	// for(int i = 0; i < 3; i++){					//for
	// 	cout << "for1" << endl;
	// }

	// for(int j = 0; j < 3; j++){
	// 	if(j == 1){
	// 		cout << "break" << endl;
	// 		break;
	// 	}
	// 	cout << "for2" << endl;
	// }

	// for(int k = 0; k < 3; k++){
	// 	if(k == 1){
	// 		cout << "continue" << endl;
	// 		continue;
	// 	}
	// 	cout << "for3" << endl;
	// }

	// cout << endl;



	// //RAND
	// cout << "*** RAND ***" << endl;

	// cout << rand() << endl;						//random between 0 and RAND_MAX
	// cout << rand() % 10 << endl;					//0 to 9
	// cout << rand() % 10 + 1 << endl;				//1 to 10

	// srand(100);									//random based on seed
	// cout << rand() % 10 + 1 << endl;
	// cout << rand() % 10 + 1 << endl;

	// srand(time(0));								//truly random, based on time
	// cout << rand() % 10 + 1 << endl;
	// cout << rand() % 10 + 1 << endl;	

	// return 0;

	// cout << endl;



	// //ARRAYS
	// cout << "*** ARRAYS ***" << endl;

	// int regArr[5] = {1, 2, 3, 4, 5};

	// char string[] = "Hello";

	// int twoD[2][3];
	// twoD[0][0] = 2;

	// int *dynamic = new int[100];

	// cout << regArr[0] << endl;
	// cout << string[0] << endl;
	// cout << twoD[0][0] << endl;

	// delete [] dynamic;

	// arrayPass(string);

	// cout << endl;



	// //FUNCTION CALLS
	// cout << "*** FUNCTIONS ***" << endl;

	// simpleFunc(regArr[0], regArr[1]);

	// cout << endl;



	// //POINTERS
	// cout << "*** POINTERS ***" << endl;

	// int ptdTo[2] = {1, 2};
	// int *ptr;

	// ptr = &ptdTo[0];
	// cout << *ptr << endl;

	// ptr++;
	// cout << *ptr << endl;

	// cout << endl;



	// //COMMAND LINE
	// cout << "*** COMMAND LINE ARGUMENTS ***" << endl;

	// cout << argc << endl;
	// cout << argv[1] << endl;

	// cout << endl;



	// //RECURSION CALL
	// cout << "*** RECURSION ***" << endl;

	// headRecursion(3);
	// cout << endl;
	// tailRecursion(3);

	// cout << endl;



	// //STRUCTS
	// cout << "*** STRUCTS ***" << endl;

	// struc ex, *ex_ptr;

	// strncpy(ex.name, "Cindy", 10);
	// ex.letter = 'a';
	// ex.num = 1;

	// cout << ex.letter << endl;
	// cout << ex.num << endl;

	// ex_ptr = &ex;
	// (*ex_ptr).num = 2;
	// ex_ptr -> letter = 'b';

	// objectPass(ex);

	// cout << endl;



	// //TYPEDEFS
	// cout << "*** TYPEDEFS ***" << endl;

	// typedef int score;
	// typedef double weight;

	// score basketBall = 97;
	// weight karime = 135.5;

	// cout << basketBall << endl << karime << endl;

	// cout << endl;



	//CLASSES
	cout << "*** CLASSES ***" << endl;

	Clas c, c2;
	c.classFunc(2);
	c2.classFunc(3);



	//LINKED LISTS
	List mylist;
	mylist.push_back(3);
	mylist.push_back(9);



	//
}



//FUNCTIONS
void simpleFunc(int input1, int input2) {
	cout << input1 + input2 << endl;
}

void arrayPass(char array[]) {
	cout << array[0] << endl;
}

void objectPass(struc myEx) {
	cout << myEx.letter << endl << myEx.num << endl;
}



//RECURSION
void headRecursion(int input) {
	if(input == 1) {
		cout << "head!" << endl;
	}
	else {
		headRecursion(input-1);
		cout << "recurse!" << endl;
	}
}

void tailRecursion(int input) {
	if(input == 1) {
		cout << "tail!" << endl;
	}
	else{
		cout << "recurse!" << endl;
		tailRecursion(input-1);
	}
}