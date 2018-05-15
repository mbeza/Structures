#ifndef ELEMLIST_H
#define ELEMLIST_H

#include <iostream>
#include <cstdlib>

using namespace std;

class ElemList
{
	public:
		ElemList *next;
		ElemList *previous;
		int data;
		
		ElemList();
		~ElemList();
};

#endif
