#ifndef NETWORK_H
#define NETWORK_H
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <deque>
#include <vector>
#include "user.h"
using namespace std;

class Network {
	public:
	Network();
	~Network();
	int read_friends(const char *filename);
	int write_friends(const char *filename);
	void add_user(User temp);
	int add_connection(string name1, string name2);
	int remove_connection(string name1, string name2);
	int get_id(string username);
  	User getUser(int loc);
  	string getName(int loc);
  	void printUsers();
  	void eraseVals();

  	vector<int> shortest_path (int from, int to);
  	vector<vector<int> > groups();
  	vector<int> suggest_friends(int who, int &num);
	
	private:
	vector<User> master;
};

#endif