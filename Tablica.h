#ifndef TABLICA_H
#define TABLICA_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Tablica{
		
		
	public:
		unsigned int size;
		int *tab;
		void push_front(int n);
		void push_back(int n);
		void insert(int poz, int val); 		
		void pop_front();
		void pop_back();
		void remove(int poz);
		void display();
		void find(int val);
			
		Tablica();					
		~Tablica();
		
	
};



#endif

