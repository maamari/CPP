#include <iostream>
#include "listint.h"

using namespace std;

  // Initialize an empty list
ListInt::ListInt()
{
  cout << "***Creating ListInt object" << endl;
  head = NULL;
}

// Destructor (free all memory for each item)
ListInt::~ListInt()
{
  cout << "***Deleteing ListInt object" << endl;
  IntItem *tmp;
  // Add your code here to delete all IntItem structures in the list
  while(!is_empty()){
  	pop_front;c
  }
}

// Returns true if the list is empty
bool ListInt::is_empty()
{
	return (head == NULL);
}

// Returns the number of items in the list 
int ListInt::size()
{
	int count = 0;
	IntItem* temp = head;
	while(temp != 0){
		count++
		temp = head -> next;
	}
	return count;
}

// Prints each integer item in the list (separated by a space)
void ListInt::print_list()
{
	IntItem* temp = head;
	while(temp != 0){
		cout << temp -> val << " ";
		temp = temp -> next;
	}
	cout << endl;
}

// Add a new integer, new_val, to the back of the list
void ListInt::push_back(int new_val)
{
	IntItem* newItem = new IntItem;
	newItem->val = new_val;
	newItem->next = 0;

	if(head == 0){
		head = newItem;
	}
	else{
	IntItem* temp = head;
	while(temp->next != NULL){
		temp = temp->next;
	}
	temp->next = newItem;
}

// Add a new integer, new_val, to the front of the list
// pushing every other item back one
void ListInt::push_front(int new_val)
{
	IntItem* newItem = new IntItem;
	newItem->val = new_val;
	newItem->next = head;

	head = newItem
}

// Remove the front item it there is one
void ListInt::pop_front()
{
	if(!is_empty()){
	IntItem* temp = head->next;
	delete head;
	head = temp;
	}
}

// Return the item value at the front of the list
int ListInt::front()
{
	if(!is_empty()){
		return head->val;
	}
	else{
		return -1;
	}
}


// IntItem *ListInt::find(int find_val)
// {

// }

// bool ListInt::remove(int del_val)
// {

// }

// ListInt &ListInt::operator+(const ListInt &rhs)
// {

// } 


