#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <cstdlib>
#include "ElemList.h"

using namespace std;

class List{
		
		
	public:
		ElemList *head;
		ElemList *tail;
		unsigned int size;
		
		void push_front(int val);
		void push_back(int val);
		void insert(int poz, int val); //pozycja na ktorej ma sie znalezc, liczona od glowy		
		void pop_front();
		void pop_back();
		void remove(int poz);
		void find(int val);
		void display();
			
		List();			
		~List();
		
	
};



#endif

