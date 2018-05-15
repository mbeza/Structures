#include "Lista.h"

List::List()
{
	tail=NULL;
	head=NULL;
	size=0;
}

List::~List()
{
	if (head!=NULL)						//jesli glowa jest null, to znaczy, ¿e nie ma elementow
	{
		while (head->next!=NULL)		//dopoki wskaznik nastepnego elementu nie wskazuje na null
		{
			head=head->next;			//przeskakujemy da nastepnego elementu
			delete head->previous;		//zwalniamy pamiec tam, gdzie wskzauje wskaznik previous (czyli zwalniamy pamiec ktora zajmowal poprzedni element)
		}
		delete head;					//jesli jestesmy w ostatnim elemencie, to jego tez musimy zwolnic
	}
	
}

void List::push_back(int val)
{
	ElemList * elem = new ElemList();	//tworzymy nowy element
	elem->data=val;						//przypisujemy mu wartosc
	elem->previous=tail;				//do pola previous przypisujemy wskaznik na element ktory jest w ogonie
	
	if (tail==NULL)						//sprawdzamy czy ogon jest pusty
	{		
		head=elem;						//skoro ogon jest pusty, to glowa tez, wiec przypisujemy tam wskaznik na stworzony element
	}
	else								//jesli ogon nie jest pusty
	{
		tail->next=elem;				//to do od teraz pole next ktore jest w ogonie ma wskazywac na dodany przez nas element
	}
	tail=elem;							//od teraz nowo dodany element jest ogonem
	size++;
}

void List::push_front(int val)
{
	ElemList * elem = new ElemList();	//tworzymy nowy element
	elem->data=val;						//przypisujemy mu wartosc
	elem->next=head;					//do pola next przypisujemy wskaznik na element ktory jest w glowie

	if (head==NULL)						//sprawdzamy czy glowa jest pusta
	{
		tail=elem;						//skoro glowa jest pusta, to ogon tez, wiec przypisujemy tam wskaznik na stworzony element
	}
	else								//jesli glowa nie jest pusta
	{
		head->previous=elem;			//to do od teraz pole previous ktore jest w glowie ma wskazywac na dodany przez nas element
	}
	head=elem;							//od teraz nowo dodany element jest glowa
	size++;
}

void List::insert(int poz, int val)
{	
	if(poz<=0)						//jesli podana pozycja jest mniejsza albo rowna 0, to dodajemy element na poczatek listy
	{
		push_front(val);
	}
	else
	{
		if(poz>=size)				//jesli podana pozyja jest wieksza niz maksymalny indeks - czyli wieksze rowne size, to dodajemy element na koniec listy
		{
			push_back(val);
		}
		else						//jesli podana pozycja jest z przedzialu [1; size), to algorytm:
		{
			ElemList * elem = new ElemList();		//tworzymy element ktory chcemy dodac
			elem->data=val;							//w polu data przypisujemy mu wartosc przekazana w funkcji
			ElemList * iter;						//wskaznik iterujacy, przyda sie zeby dostac sie na zadana pozycje		
				
			if(((size-1)/2)-poz<0)		//szybciej bedzie isc od strony ogona (zrobi sie mniej krokow)
			{
				int steps=size-poz-1;		//liczymy ile przeskokow trzeba zrobic aby dostac sie na zadana pozycje
				iter=tail;					//zaczynamy od ogona
				while(steps>0)
				{
					iter=iter->previous;		//idziemy na zadana pozycje
					steps--;
				}
				iter->previous->next=elem;		//na pozycji na ktorej sie znajdujemy, mowimy ze wskaznik next poprzedniego elementu ma od tej pory wskazywac na nowy, dodany przez nas element
				elem->previous=iter->previous;	//wskaznik previous dodanego przez nas elementu ma wskazywac na element za ktorym zostal wstawiony
				iter->previous=elem;			//wskaznik previous pozycji na ktorej sie znajdujemy ma wskazywac na dodany przez nas element
				elem->next=iter;				//wskzanik next dodanego przez nas elementu ma wskazywaæ na element przed ktorym zostal wstawiony
					size++;
			}
			else						//szybciej bedzie isc od strony glowy
			{
				int steps=poz-1;		//trzeba przeskoczyc o jeden element przed wskazana pozycje, 
				iter=head;				//zaczynamy od glowy
				while(steps>0)
				{
					iter=iter->next;	//idziemy na pozycje o jeden mniejsza niz wskazana
					steps--;
				}
				iter->next->previous=elem;	//na pozycji na ktorej sie znajdujemy(n-1), mowimy ze wskaznik previous nastepnego elementu ma od tej pory wskazywac na nowy, dodany przez nas element
				elem->next=iter->next;		//wskaznik next dodanego przez nas elementu ma wskazywac na element przed ktorego zostal wstawiony
				iter->next=elem;			//wskaznik next pozycji na ktorej sie znajdujemy ma wskazywac na dodany przez nas element
				elem->previous=iter;		//wskzanik previous dodanego przez nas elementu ma wskazywaæ na element za ktorym zostal wstawiony
				size++;
			}	
		}
	}

}

void List::pop_front() 			//funkcja napisana bez zwracania, zeby operacja return nie miala wplywu na czas usuwania elementu
{
	if(head!=NULL)				//sprawdzamy czy jest co usuwac
	{
		if(head==tail)			//jesli glowa jest ogonem, czyli jest jeden element w liscie
		{
			head=tail=NULL;			//to ustaw wskazniki na adres 0
			size=0;					//wyzeruj rozmiar
			return;					//zwracaloby glowo-ogon
		}
		else				//jesli jest wiecej elementow na liscie
		{
			head->next->previous=NULL; 			//wskaznik prev nastepnego elementu za glowa ustaw na null
			ElemList * newHead = head->next;	//pobierz do zmiennej tymczasowej adres nastepnego elementu
			delete head;						//usun glowe
			head=newHead;						//element za stara glowa staje sie teraz glowa
			size--;
			return;								//zwracaloby glowe
		}	
	}
	else cout<<"Lista jest pusta.\n";
}

void List::pop_back()			//funkcja napisana bez zwracania, zeby operacja return nie miala wplywu na czas usuwania elementu
{
	if(tail!=NULL)				//sprawdzamy czy jest co usuwac
	{
		if(tail==head)			//ten sam warunek co wyzej
		{
			tail=head=NULL;
			size=0;
			return;				//zwracaloby glowo-ogon
		}
		else
		{
			tail->previous->next=NULL;				//wskaznik next poprzedniego elementu ustaw na null
			ElemList * newTail = tail->previous;	//pobierz do zmiennej tymczasowej adres poprzedniego elementu
			delete tail;							//usun glowe
			tail=newTail;							//element przed starym ogoenm staje sie  ogonem
			size--;
			return;									//zwracaloby ogon
		}	
	}
	else cout<<"Lista jest pusta.\n";
	
}

void List::remove(int poz)
{
	if(poz>=0 && poz<size)		//algorytm zadziala tylko dla wartosci ktore istnieja
	{
		if(poz==0)
		{
			pop_front();		//jesli przekazana pozycja = 0 to usuwamy glowe
		}
		else
		{
			if(poz==size-1)
			{
				pop_back();		//jesli przekazana pozycja = size-1 to usuwamy ogon
			}
			else
			{
				ElemList * iter;			//zmienna pomocnicza, ktora bedziemy przechodzic liste
				if(size/2>=poz+1)			//blizej bedzie isc od glowy
				{
					int steps=poz;			//liczba krokow zeby dostac sie do wskazanej pozycji
					iter=head;				//startujemy od glowy
					while(steps>0)
					{
						iter=iter->next;	//przeskakujemy na wskazana pozycje
						steps--;
					}
					iter->next->previous=iter->previous;	//ustawiamy, zeby wskaznik 'previous' nastepnego elementu wskazywa³ na poprzedni element
					iter->previous->next=iter->next;		//tutaj ustawiamy, zeby wskaznik 'next' poprzedniego elementu wskazywal na nastepny element
					delete iter;							//usuwamy ten element, czyli zwalniamy pamiec
					size--;
					return;								//konczymy funkcje, gdyby funkcja miala cos zwracac, to by zwrocila wartosc elementu ktury byl na tej pozycji
				}
				else							//blizej bedzie isc od strony ogona
				{
					int steps=size-poz-1;		//liczba krokow, zeby dostac sie na wskazana pozycje
					iter=tail;					//startujemy od ogona
					while(steps>0)
					{
						iter=iter->previous;		//przeskakujemy na wskazana pozycje
						steps--;
					}
					iter->previous->next=iter->next;		//ustawiamy, zeby wskaznik 'next' poprzedniego elementu wskazywal na nastepny element
					iter->next->previous=iter->previous;	//ustawiamy zeby wskaznik 'previous' nastepnego elementu wskazywal na poprzedni element
					delete iter;							//usuwamy ten element, zwalniajac pamiec
					size--;
					return;				//ewentualnie zwracamy wartosc
				}
			}
		}
	}
	else cout<<"Nie ma takiego indeksu.\n";
	
}


void List::display()
{
	if(head!=NULL)				//jesli glowa jest pusta, to lista jest pusta i nie ma co wyswietlac
	{
		ElemList * iter;			//deklarujemy zmienna pomocnicza, do przechodzenia przez liste
		iter=head;					//zaczynamy od glowy
		while(iter->next!=NULL)			//idziemy tak dlugo az wskzanik 'next' nie bedzie pokazywal null, czyli ze dalej nic nie ma
		{
			cout<<iter->data<<" ";		//wyswietlamy wartosc elementu
			iter=iter->next;			//przechodzimy do nastepnego elementu
		}
		cout<<iter->data<<"\n";			//wyswietlamy ostatni element 
	}
	
}

void List::find(int val) 
{
	if(head!=NULL)					//jesli lista nie jest pusta
	{
		int poz=0;					//tworzymy zmienna zeby liczyla ktora to pozycja od glowy (glowa to 0)
		ElemList * iter;			//zmienna pomocnicza do przejscia przez liste
		iter=head;					//zaczynamy od glowy 
		while(iter->next!=NULL)			//sprawdzamy tak dlugo az wskaznik 'next' nie wskazuje na null
		{
			if(iter->data==val)		//jesli znalezlismy, to wskazujemy na ktorej pozycji
			{
				cout<<"Znaleziono na pozycji "<<poz<<endl;
				return;				//konczymy funkcje (mogloby zwracac pozycje)
			}		
			iter=iter->next;		//jesli nie znaleziono, to idziemy do nastepnego elementu
			poz++;					//i zwiekszamy zmienna informujaca na ktorej pozycji jestesmy
		}
		if(iter->data==val)			//jesli przeszlismy cala liste, to jeszcze musimy sprawdzic, czy dana wartosc nie wystepuje w ostatnim elemencie
		{
			cout<<"Znaleziono na pozycji "<<poz<<endl;
			//return;										//jesli tak, to wyswietlamy
		}
		else
		{
			cout<<"Nie znaleziono.\n"; //a jesli nie, to mowimy ze nie znaleziono
			//return;
		}	
	}
	else cout<<"Nie znaleziono.\n"; //jesli lista jest pusta to na pewno nie znajdzie
}








