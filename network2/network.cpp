#include "network.h"

Network::Network(){};
Network::~Network(){};

int Network::read_friends(const char *filename){

	ifstream ifile(filename);

	if(ifile.fail()){
		cout << "Couldn't read in file correctly!" << endl;
		return -1;
	}

	int userCount;
	ifile >> userCount;

	for(int i = 0; i < userCount; i++){

		int id, year, zip, temp;
		string first, last, name, end, line;

		ifile >> id;
		ifile >> first;
		ifile >> last;
		ifile >> year;
		ifile >> zip;

		getline(ifile, end);
		getline(ifile, line);

		name = first + " " + last; 
		
		User newUser(name, year, zip);
		stringstream ss(line);

		while(ss >> temp){
			newUser.add_friend(temp);
		}

		add_user(newUser);
	}

	ifile.close();

	return 0;
}


int Network::write_friends(const char *filename){

	ofstream ofile(filename);

	int size = master.size();

	ofile << size << endl;

	for(int i = 0; i < size; i++){

		ofile << i << endl;

		ofile << '\t' << (master[i]).getName() << endl;
		ofile << '\t' << (master[i]).getYear() << endl;
		ofile << '\t' << (master[i]).getZip() << endl;
		ofile << '\t';

		vector<int> uList = (master[i]).getFriends();

		for(int j = 0; j < uList.size(); j++){
			ofile << uList[j] << " ";
		}

		ofile << endl;

		if(ofile.fail()){
			return -1;
		}
	}

	ofile.close();
	return 0;
}


void Network::add_user(User u){
	master.push_back(u);
}


int Network::add_connection(string user1, string user2){

	bool same = 0;
	int count = 0;
	int id1 = 0;
	int id2 = 0;

	while(!same){
		if((master[count]).getName() == user1){
			id1 = count;
			same = true;
		}
		else if(count == master.size() - 1){
			return -1;

		}
		count++;
	}

	same = 0;
	while(!same){
		if((master[count]).getName() == user2){
			id2 = count;
			same = true; 
		}
		else if(count == master.size()-1){
			return -1;

		}
		count++;
	}

	(master[id1]).add_friend(id2);
	(master[id2]).add_friend(id1);
	return 0;
}


int Network::remove_connection(string user1, string user2){
	int usr1 = get_id(user1);
	int usr2 = get_id(user2);

	if(usr1 == -1){
		return usr1;
	}

	if(usr2 == -1){
		return usr2;
	}

	(master[usr1]).delete_friend(usr2);
	(master[usr2]).delete_friend(usr1);

	return 0;
}


int Network::get_id(string username){

	for(int i = 0; i < master.size(); i++){

		if((master[i]).getName() == username){
			return i;
		}
	}

	return -1;
}


User Network::getUser(int position){
	return master[position];
}


void Network::printUsers(){
	for(int i = 0; i < master.size(); i++){
		User temp = master[i];

		cout << i << ")  ";

		cout << temp.getName();

		for(int j = (temp.getName()).size(); j < 20; j++){
			cout << " ";
		}

		cout << temp.getYear() << "    ";
		cout << temp.getZip() << endl;
	}
}

string Network::getName(int position){
	return master[position].getName();
}

vector<int> Network::shortest_path(int in, int out){
	master[in].deep = 0;
  	deque<int> d;
  	vector<int> shortest;

  	d.push_front(in);

  	for (int i=0; i < master.size(); i++) {
		master[i].prev = -1;
		master[i].deep = -1;  
	}  

	master[in].deep = 0; 

  	if(in == out){
  		for(int i=0; i < master.size(); i++){
			master[i].num = -1;
			master[i].deep = -1;
			master[i].prev = -1;
		}
  		return shortest;
  	}

  	while(!d.empty()){  		
  		int cnt = d.front();
  		d.pop_front();

		vector<int> friends = master[cnt].getFriends();

		if(!friends.empty()){
			for(int i = 0; i < friends.size(); i++){
				if(friends[i] == out){ 
		  			while(cnt != in){
		  				shortest.push_back(cnt);
		    			cnt = master[cnt].prev;
		  			}
		  			for(int j=0; j < master.size(); j++){
						master[j].num = -1;
						master[j].deep = -1;
						master[j].prev = -1;
					}
		  			return shortest;
				}
				else{ //add to queue
					  (master[friends[i]]).prev = cnt;
					  (master[friends[i]]).deep = master[cnt].deep + 1;
					   d.push_back(friends[i]);
				}

			}
		}
  	}
  	//no path reached
  	shortest.push_back(-1);
	for(int i=0; i < master.size(); i++){
		master[i].num = -1;
		master[i].deep = -1;
		master[i].prev = -1;
	}
  	return shortest;
  }


vector<vector<int> > Network::groups(){
  	vector<vector<int> > shortest;
  	deque<int> unchecked;
  	int numz=0;

	for(int i=0; i < master.size(); i++){

		if(master[i].deep == -1){ 
			unchecked.push_back(i);

			while(! unchecked.empty()){  		
		  		int cnt = unchecked.front();
		  		unchecked.pop_front(); //remove checked
		  		master[cnt].deep = i;

				vector<int> friends = master[cnt].getFriends();
				if(!friends.empty()){
					for(int j=0; j < friends.size(); j++){
						if(master[friends[j]].deep == -1){ //not yet added
							(master[friends[j]]).deep = i;
							unchecked.push_back(friends[j]);
				  		}
					}
				}
		  	}
	  		vector<int> temp;
		  	for(int j=0; j< master.size(); j++){ //add all users
		  		if(master[j].deep == i){
		  			temp.push_back(j);
		  		}
		  	}
		  	shortest.push_back(temp);
		  	numz++;
		}
	}

  return shortest;
}


vector<int> Network::suggest_friends(int who, int &num){
  	vector<int> shortest;
  	deque<int> unchecked;
  	master[who].deep = 1; //visited
  	num = -1;

  	vector<int> frndz = master[who].getFriends();
  	for(int i=0; i < frndz.size(); i++){
  		master[frndz[i]].deep = 1; //visited
  	}

  	for(int i=0; i< frndz.size(); i++){
  		for(int j=0; j < master[frndz[i]].getFriends().size(); j++){
  			if(master[master[frndz[i]].getFriends()[j]].deep == -1){
  				if(master[master[frndz[i]].getFriends()[j]].num == -1){
  					master[master[frndz[i]].getFriends()[j]].num = 1;
  				}
  				else{
  					master[master[frndz[i]].getFriends()[j]].num++;
  				}

  				if(num < master[master[frndz[i]].getFriends()[j]].num){ //update num
  					num = master[master[frndz[i]].getFriends()[j]].num;
  				}
  			}
  		}
  	}

  	if(num == -1){
  		for(int i=0; i < master.size(); i++){
			master[i].num = -1;
			master[i].deep = -1;
			master[i].prev = -1;
		} //reset values
  		return shortest;
  	}
  	else{ 
  		int max=0;
  		for(int i=0; i< master.size(); i++){
  			if(master[i].num > max){
  				max = master[i].num; //set new max
  			}
  		}
  		for(int i=0; i< master.size(); i++){
  			if(master[i].num == max){
  				shortest.push_back(i);
  			}
  		}
  		num = max; 
  		for(int i=0; i < master.size(); i++){
			master[i].num = -1;
			master[i].deep = -1;
			master[i].prev = -1;
		} //reset values
		return shortest;
  	}
}