#ifndef CREVIEW_H
#define CREVIEW_H

//STRUCTS
struct struc {
	char name[10];
	char letter;
	unsigned int num;
};

struct Item {
	int val;
	Item* next;
};


//CLASSES
class List {
public:
	List();
	~List();

	void push_back(int v);
	void push_front(int v);
	void pop_back(int v);
	void pop_front(int v);
	void find(int v);
private:
	Item* head;
};

class Clas {
public:
	Clas();
	~Clas();

	void classFunc(int num);
	void set_var1(int var1);
	void set_var2(std::string var2);
private:
	int classArr[100];
	int classInt;
};


#endif