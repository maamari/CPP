#ifndef USER_H
#define USER_H
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


class User {
 public:
 	User(string fullName, int year, int zip);
 	~User();
 	void add_friend(int a);
 	void delete_friend(int d);
 	int getYear();
 	int getZip();
 	string getName();
 	vector<int> getFriends();
 	int deep;
 	int prev;
 	int num;

 private:
 	string fullName_;
 	int year_;
 	int zip_;
 	vector<int> friends;
};

#endif