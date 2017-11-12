#include "delist.h"
#include <iostream>

// Constructs an empty Double-Ended List
DEList::DEList() {
  head = NULL;
  tail = NULL;
}

// Destructor to clean-up memory of current list
DEList::~DEList() {
  DEItem* temp = head;

  // deletes all nodes
  while (head != tail)
  {
    head = head->next;
    delete temp;
    temp = tail;
  }

  delete head;
}

// returns a Boolean 'true' if the list is empty
bool DEList::empty() {
	if (!head && !tail){
		return true;
	}
	else{
		return false;
	}
}

// returns number of items in the list
int DEList::size() {
  	int items = 0;

  // check if list is empty
	if(empty()){
		return 0;
	}
	DEItem* loc = head;

  // try doing it from head to tail
  	while(loc){
	    items++;
	    loc = loc->next;
  	}

  return items;
}

// returns front item or -1 if empty list
int DEList::front() {
  if (empty()){
    return -1;
}
  else{
    return head->val;
}
}

// returns back item or -1 if empty list
int DEList::back(){
  if (empty()){
    return -1;
}
  else{
    return tail->val;
}
}

// Adds a new integer to the front of the list
void DEList::push_front(int new_val) {
  // Create a new list item
  DEItem* item2 = new DEItem;
  // Assign new_val to the new node
  item2->val = new_val;

  // assign the pointers for prev and next
  item2->prev = NULL; // the previous pointer is empty
  item2->next = head; // the next points to the head

  // if list empty, update both head and tail to item2
  if (empty())
  {
    head = item2;
    tail = item2;
  }
  else
  {
    // update head
    head->prev = item2;
    head = item2;
  }
}

// Adds a new integer to the back of the list
void DEList::push_back(int new_val) {
  // Create a new list item
  DEItem* item2 = new DEItem;
  // Assign new_val to the new node
  item2->val = new_val;

  // assign the pointers for prev and next
  item2->prev = tail; // the tail(last item) is now the previous
  item2->next = NULL; // the next pointer is empty

  // if list empty, update both head and tail to item2
  if (empty())
  {
    head = item2;
    tail = item2;
  }
  else
  {
    // update tail
    tail->next = item2;
    tail = item2;
  }
}

// Removes the front item of the list (if it exists)
void DEList::pop_front() {
  if (!empty())
  {
    // Special case when there is only one item in the list
    if (size())
    {
      delete head;
      tail = NULL;
      head = NULL;
    }
    else
    {
      // temp var holds the new front item
      DEItem* temp = head->next;
      // Set front to NULL
      temp->prev = NULL;
      // reasign head;
      delete head;
      head = temp;

      // delete temp;
    }
  }
  else
    std::cerr << "The list is empty! Nothing to delete" << std::endl;
}

// Removes the back item of the list (if it exists)
void DEList::pop_back() {
  if (!empty())
  {
    // Special case when there is only one item in the list
    if (size())
    {
      delete head;
      tail = NULL;
      head = NULL;
    }
    else
    {
      // temp var holds the new last item
      DEItem* temp = tail->prev;
      // Set front to NULL
      temp->next = NULL;
      // reasign head;
      delete tail;
      tail = temp;

      // delete temp;
    }
  }
  else
    std::cerr << "The list is empty! Nothing to delete" << std::endl;
}