#ifndef KOPIEC_H
#define KOPIEC_H

#include <iostream>
#include <cstdlib>

using namespace std;

class Heap{
		
		
	public:
		unsigned int size;
		int *tab;
		void add(int n);
		void remove();
		void display();
		void find(int val);
			
		Heap();					
		~Heap();
		
	
};



#endif

