#include "Kopiec.h"

int potega (int podst, int wykl)
{
	int wynik=podst;
	while(wykl>1)
	{
		wynik*=podst;
		wykl--;
	}
	return wynik;
}


Heap::Heap()
{
	size=0;
	tab= new int[1];
	tab[0]=NULL;
}

Heap::~Heap()
{	
	delete [] tab;	
}

void Heap::add(int n)
{	
	int *tmp = new int[size+1]; //deklarujemy wskaznik na tablice o 1 miejsce wieksza
	
	for(int i=0; i<size; i++)
	{ 
		tmp[i]=tab[i];			//kopiujemy ze starej do nowej
	}
	
	tmp[size]=n;				//na koniec nowej dodajemy wartosc przekazana w funkcji
	
	delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
	tab=tmp;					//aktualizujemy wskaznik na tablice
	
	int iter=size;				//tworzymy zmienna pomocnicza, ktora bedzie iteratorem dodanego elementu
	
	while(iter>0)
	{
		if(tab[(iter-1)/2]<tab[iter])
		{
			int tmp2=tab[(iter-1)/2];
			tab[(iter-1)/2]=tab[iter];	//zamiana ojca z synem jesli ojciec jest mniejszy niz rozpatrywany syn
			tab[iter--]=tmp2;			//postdekrementacja, bo trzeba odjac 1 i dopiero podzielic przez 2
			iter/=2;
		}
		else break;
	}
	
	size++;						//zwiekszamy rozmiar	
	
}


void Heap::remove()
{
	//int root=tab[0];				//gdyby by³a potrzebne wykorzystanie tego elementu
	if(size!=0)
	{
		tab[0]=tab[--size];				//zamiana korzenia z ostatnim elementem kopca, przy okazji zmniejszenie rozmiaru kopca
		
		int *tmp = new int[size];		//nowa tablica o mniejszym rozmiarze
	
		for(int i=0; i<size; i++)
		{ 
			tmp[i]=tab[i];			//kopiujemy ze starej do nowej
		}	
	
		delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
		tab=tmp;					//aktualizujemy wskaznik na tablice
		
	
		int iter=0;					//zmienna pomocnicza do poruszania sie po kopcu. iter=0 oznacza, ze zaczynamy od korzenia
		
		while((2*iter+1)<size)		
		{
			if((2*iter+2<size) && tab[2*iter+1]<tab[2*iter+2])		//jesli istnieje prawy syn i jest wiekszy od lewego 
			{
				if(tab[2*iter+2]>tab[iter])								//jesli prawy syn wezla ktory rozpatrujemy jest od niego wiekszy
				{				
					int tmp2=tab[2*iter+2];
					tab[2*iter+2]=tab[iter];								//zamien rodzica z prawym synem
					tab[iter]=tmp2;
	
					iter=2*iter+2;											//przesun iterator na wezel ktory zamieniono
				}
				else break;												//jesli prawy syn nie jest wiekszy, to koniec algorytmu
			}
			else													// jesli lewy syn jest wiekszy, lub nie istnieje prawy
			{
				if(tab[2*iter+1]>tab[iter])								//sprawdzamy czy lewy syn wezla ktory rozpatrujemy jest od niego wiekszy
				{
					int tmp2=tab[2*iter+1];
					tab[2*iter+1]=tab[iter];								//zamien rodzica z lewym synem
					tab[iter]=tmp2;	
					iter=2*iter+1;											//przesun iterator na wezel ktory zamieniono
					
				}
				else break;
			}
		}	
	}
	else cout<<"Kopiec jest pusty.\n";	
	//return root;					//zwracamy korzen
}


void Heap::display()
{
	int level=1;					//wyswietlanie poziomami 
	for(int i=0; i<size; i++)
	{
		cout<<tab[i]<<"  ";
		if(potega(2,level)-2==i)		//jesli numer wezla jest ostatnim w danym poziomie
		{
			cout<<endl;				//to przejdz do nowej linii 
			level++;
		}
	}
		
	cout<<endl;
}

void Heap::find(int val)
{
	if(size!=0)	//jesli kopiec nie jest pusty
	{
		int i;
		
		for(i=0; i<size; i++)
		{
			if(tab[i]==val)				//przechodz po tablicy 
			{
				cout<<"Znaleziono "<<val<<" pod indeksem "<<i<<endl; //jesli znajdzie to wyswietl gdzie
				return;
			}
			else continue;
		}
		if(i==size) cout<< "Nie znaleziono. \n";			//jesli przejdzie cala tablice i nie znajdzie, to wyswietl informacje
	}
	else cout<<"Nie znaleziono. \n";					//jesli kopiec jest pusty to na pewno nie znajdzie 
}




















