#include "user.h"


User::User(string fullName, int year, int zip){
	fullName_ = fullName;
	year_ = year;
	zip_ = zip;
	deep = -1;
	prev = -1;
	num = -1;
};

User::~User(){};

string User::getName(){
	return fullName_;
};
int User::getYear(){
	return year_;
};
int User::getZip(){
	return zip_;
};
vector<int> User::getFriends(){
	return friends;
}

void User::add_friend(int a){
	bool seen = 0;

	for(int i=0; i < friends.size(); i++){
		if(a == friends[i]){
			seen = 1;
			break;
		}
	}

	if(!seen){
		friends.push_back(a);
	}
};

void User::delete_friend(int d){
	bool seen=0;
	int s = friends.size();
	for(int i=0; i< s && !seen; i++){
		int temp = (friends[i]);

		if(d == temp){
			friends.erase(friends.begin()+i);
			seen=1;
		}
	}
};