#include "delist.h"
#include <iostream>

DEList::DEList(){
  head = NULL;
  tail = NULL;
  items = 0;
}

DEList::~DEList(){
  DEItem* temp = head;

  while(head != tail)           //while the list isn't of size 1
  {
    head = head->next;
    delete temp;                //delete the current location
  }
  delete head;                  //delete the head afterwards
}

bool DEList::empty(){
	if(!items){                   //if there are no items
		return true;
	}
	else{
		return false;
	}
}

int DEList::size(){
  return items;                 //return # of items in list
}

int DEList::front() {
  if(empty())
  {
    return -1;                  //return -1 if emtpy
  }
  else
  {
    return head->val;           //return the value in the head
  }
}

int DEList::back(){
  if(empty())
  {
    return -1;                  //return -1 if empty
  }
  else
  {
    return tail->val;           //return the value of the head
  }
}

// Adds a new integer to the front of the list
void DEList::push_front(int new_val) {

  DEItem* newItem = new DEItem; //create a new item in list
  newItem -> val = new_val;     //assign the value to that node
  newItem -> prev = NULL;       //the previous pointer should be empty

  if(empty())
  {
    newItem -> next = NULL;     //if the list is empty
    head = newItem;             //update head and tail to the new item
    tail = newItem;
  }
  else
  {
    newItem -> next = head;     //the next pointer points to the head
    head -> prev = newItem;     //the head i
    head = newItem;
  }
  items++;
}

// Adds a new integer to the back of the list
void DEList::push_back(int new_val) {

  DEItem* newItem = new DEItem;
  newItem -> val = new_val;
  newItem -> next = NULL; 

  if(empty())
  {
    newItem -> prev = NULL;
    head = newItem;
    tail = newItem;
  }
  else
  {
    newItem -> prev = tail;
    tail -> next = newItem;
    tail = newItem;
  }
  items++;
}

// Removes the front item of the list (if it exists)
void DEList::pop_front() {
  if (!empty())
  {
    if(size() == 1)
    {
      delete head;
      tail = NULL;
      head = tail;
    }
    else
    {
      DEItem* temp = head;
      head = temp -> next;
      delete temp;
    }
    items--;
  }
}

// Removes the back item of the list (if it exists)
void DEList::pop_back() {
  if (!empty())
  {
    if (size() == 1)
    {
      delete head;
      tail = NULL;
      head = NULL;
    }
    else
    {
      DEItem* temp = tail;
      tail = temp -> prev;
      delete temp;
    }
    items--;
  }
}