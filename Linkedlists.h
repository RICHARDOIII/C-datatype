#ifndef LIST_H_
#include <iostream>
#include <string>
#include "link.h"
class List {

private:
	Link *head,*tail;
public:
	List();
	void insert(int data);
	void print();
	};	




#define LIST_H_ 
#endif