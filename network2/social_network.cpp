#include "network.h"
#include "user.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	Network connection;

	if(connection.read_friends(argv[1])==-1){
		cout<<"Error reading file"<<endl;
	}

	int exit = 1;

	while(exit){
		cout << "Enter 1 to add a user (1 First Last D.O.B Zip)" << endl;
		cout << "Enter 2 to add a connection (2 First1 Last1 First2 Last2)" 
			 << endl;
		cout << "Enter 3 to remove a connection (3 First1 Last1 First2 Last2)"
			 << endl;
		cout << "Enter 4 to print users (4)" << endl;
		cout << "Enter 5 to list a user's friends (5 First Last)" << endl;
		cout << "Enter 6 to write data to file (6 output.txt)" << endl;
		cout << "Enter 7 for shortest connection (7 First1 Last1 First2 Last2)" << endl;
		cout << "Enter 8 for disjoint sets (8)" << endl;
		cout << "Enter 9 for friend suggestions (9 First Last)" << endl;
		cout << "Any other character to exit" << endl;

		int option, year, zip;

		string first_name, last_name, fullName, fullName2;
		string header = "ID  Name 		Year 	Zip";
		cin >> option;

		if(option == 1){ 
			cin >> first_name >> last_name >> year >> zip;
			fullName = first_name + " " + last_name;

			User temp(fullName, year, zip);
			connection.add_user(temp);
		}

		else if(option == 2){ 

			cin >> first_name >> last_name;
			fullName = first_name + " " + last_name;

			cin >> first_name >> last_name;
			fullName2 = first_name + " " + last_name;

			if(connection.add_connection(fullName, fullName2) == -1){
				cout << "No such user!" <<endl;
			}
		}

		else if(option == 3){
			cin >> first_name >> last_name;
			fullName = first_name + " " + last_name;

			cin >> first_name >> last_name;
			fullName2 = first_name + " " + last_name;

			if(connection.remove_connection(fullName, fullName2) == -1){
				cout<< "No such user!" <<endl;
			}
		}

		else if(option == 4){
			cout << header << endl;

			for(int i=0; i<37; i++){
				cout << "~";
			}

			cout << endl;
			connection.printUsers();
		}

		else if(option == 5){ 
			cin >> first_name >> last_name;
			fullName = first_name + " " + last_name;
			int person = connection.get_id(fullName);

			if(person == -1){
				cout << "No such user!" << endl;
			}

			else{
				cout << header << endl;

				for(int i=0; i<37; i++){
				cout << "~";
				}

				cout << endl;
			
				vector<int> uList = (connection.getUser(person)).getFriends();

				for(int i=0; i<uList.size(); i++){
					User temp = connection.getUser(uList[i]);
					
					cout << uList[i] << ")  ";
					cout << temp.getName();

					for(int j = (temp.getName()).size(); j < 20; j++){
						cout<< " ";
					}

					cout << temp.getYear() << "    ";
					cout << temp.getZip() << endl;
				}
			}
		}

		else if(option == 6){
			string ofile;
			cin >> ofile;
			const char* str = ofile.c_str();
			connection.write_friends(str);
		}

		else if(option == 7){
			cin >> first_name >> last_name;
			fullName = first_name + " " + last_name;

			cin >> first_name >> last_name;
			fullName2 = first_name + " " + last_name;

			if(connection.get_id(fullName) == -1 || connection.get_id(fullName2) == -1){ //invalid users
				cout << "User does not exist" << endl;
			}
			else{
				vector<int> hold = connection.shortest_path(connection.get_id(fullName) , connection.get_id(fullName2));
				if(connection.get_id(fullName) == connection.get_id(fullName2)){ //vector empty
					cout << "Distance: 0" << endl << fullName << endl;
				}
				else if(hold.empty()){
					cout << "Distance: 1" << endl;
					cout << fullName<< " -> "<< fullName2<< endl;
				}
				else if(hold[0] == -1){
					cout << "None" << endl;
				}
				else{
					cout << "Distance: " << hold.size()+1 << endl;
					cout << fullName << " -> ";
					for(int i=0; i< hold.size(); i++){
						cout << connection.getName(hold[ hold.size()-i-1 ]) << " -> ";
					}
					cout << fullName2 << endl;
				}
			}
		} 

		else if(option == 8){
			vector<vector<int> > otherVec = connection.groups();

			for(int i = 0; i < otherVec.size(); i++){
				cout<< "Set "<< i+1 << ": ";

				vector<int> vec = otherVec[i];
				for(int j = 0; j < vec.size(); j++){
					cout << connection.getName(vec[j]);
					if(j != vec.size() - 1){ 
						cout<< ", ";
					}
				}
				cout << endl;
			}
		}

		else if(option == 9){
			int suggs = 0;

			cin >> first_name >> last_name;
			fullName = first_name + " " + last_name;

			int us3r = connection.get_id(fullName);

			if(us3r == -1){ //user dne
				cout << "User does not exist"<<endl;
			}

			else{
				vector<int> suggestions = connection.suggest_friends(us3r, suggs);

				if(suggestions.empty()){ //no new friendz
					cout << '\t' << "You have no new friends to be made! Go out and enjoy your life" <<endl;
				}

				for(int i=0; i< suggestions.size(); i++){
					cout << '\t' << "You have " << suggs << " new connection(s) to be made: ";
					cout << connection.getName(suggestions[i]) << endl;
				}
			}
		}
		else {
			exit = 0;
		}
	}
}