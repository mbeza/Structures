#include "Tablica.h"

Tablica::Tablica()
{
	tab = new int[0];
	size=0;
}

Tablica::~Tablica()
{
	delete [] tab;
}

void Tablica::push_back(int n)
{
	int *tmp = new int[size+1]; //deklarujemy wskaznik na tablice o 1 miejsce wieksza
	
	for(int i=0; i<size; i++)
	{ 
		tmp[i]=tab[i];			//kopiujemy ze starej do nowej
	}
	
	tmp[size]=n;				//na koniec nowej dodajemy wartosc przekazana w funkcji
	
	delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
	tab=tmp;					//wstawiamy adres nowej tablicy
	size++;
}

void Tablica::push_front(int n)
{
	size++;
	int *tmp = new int[size]; //deklarujemy wskaznik na tablice o 1 miejsce wieksza
	tmp[0]=n;
	
	for(int i=1; i<size; i++)
	{ 
		tmp[i]=tab[i-1];			//kopiujemy ze starej do nowej
	}
	
	delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
	tab=tmp;
	
}

void Tablica::pop_back()
{
	if(size!=0)
	{
		size--;
		int *tmp = new int[size]; //deklarujemy wskaznik na tablice o 1 miejsce mniejsza
		
		for(int i=0; i<size; i++)
		{ 
			tmp[i]=tab[i];			//kopiujemy ze starej do nowej
		}
					
		delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
		tab=tmp;
	}
	else cout<<"Tablica jest pusta.\n";
}

void Tablica::pop_front()
{
	if(size!=0)
	{
		size--;
		int *tmp = new int[size]; //deklarujemy wskaznik na tablice o 1 miejsce mniejsza
		
		for(int i=0; i<size; i++)
		{ 
			tmp[i]=tab[i+1];			//kopiujemy ze starej do nowej (pierwsza pozycje pomijamy)
		}
					
		delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
		tab=tmp;	
	}
	else cout<<"Tablica jest pusta.\n";

}

void Tablica::insert(int poz, int val)
{
	if (poz<=0)
	{	
		push_front(val);			//jesli zostanie podana pozycja <=0, to wstaw na poczatek
	}
	else
	{
		if(poz>=size)				// jessli podana pozycja bedzie >=size, to wstaw na koniec
		{
			
			push_back(val);
		}
		else
		{
			
			size++;
			int *tmp = new int[size]; //deklarujemy wskaznik na tablice o 1 miejsce wieksza
			
			for(int i=0; i<poz; i++)
			{ 
				tmp[i]=tab[i];			//kopiujemy ze starej do nowej do pozycji ktora zostala podana
			}
			
			tmp[poz]=val;				//dodajemy element na wskazana pozycje
			
			for(int i=poz+1; i<size; i++)
			{ 
				tmp[i]=tab[i-1];			//kopiujemy pozostala czesc tablicy
			}
			
			delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
			tab=tmp;		
		}
	}
}

void Tablica::remove(int poz)
{
	if(poz>=0 && poz<size)				//usuniecie wartosci moze nastapic tylko z pozycji ktore istnieja
	{
		if(poz==0)
		{
			pop_front();			//jesli pozycja to 0, to usuwamy glowe
		}
		else
		{
			if(poz==size-1)			//jesli pozycja to size-1 (czyli ogon) to usun ogon
			{
				pop_back();		
			}
			else
			{
				size--;
				int *tmp = new int[size]; //deklarujemy wskaznik na tablice o 1 miejsce mniejsza
				
				for(int i=0; i<poz; i++)
				{ 
					tmp[i]=tab[i];			//kopiujemy ze starej do nowej
				}

				for(int i=poz; i<=size; i++)
				{ 
					tmp[i]=tab[i+1];			//kopiujemy ze starej do nowej
				}
							
				delete tab;					//zwalniamy pamiec tam gdzie byla poprzednia tablica
				tab=tmp;				
			}
		}
	}
	else cout<<"Niepoprawny indeks.\n";
	
}

void Tablica::display()
{
	for(int i=0; i<size; i++)		//przejdz po tablicy i wyswietl
		cout<<tab[i]<<" ";
	cout<<endl;
}

void Tablica::find(int val)
{
	int i=0;
	for(i=0; i<size; i++)		
	{
		if (tab[i]==val)
		{
			cout<<"Znaleziono na pozycji: "<<i<<endl;		//przechodzimy po tablicy i jesli znajdziemy to konczymy szukanie
			break;
		}
	}
	if (i==size) cout<<"Nie znaleziono. \n";			//przypadek gdy przejdziemy cala tablice i nie znajdziemy
	
}
