#include <iostream>
#include <cstdlib>
#include "Kopiec.h"
#include "Lista.h"
#include "Tablica.h"
#include <fstream>
#include <windows.h>
#include <ctime>
#include <conio.h>

using namespace std;

double freq = 0.0;
LARGE_INTEGER fr;	
LARGE_INTEGER start;	//ms
LARGE_INTEGER stop;		//ms

void Start()
{
    QueryPerformanceFrequency(&fr);
    freq = double(fr.QuadPart)/1000.0;
    QueryPerformanceCounter(&start);
}

double Stop()
{
    QueryPerformanceCounter(&stop);
    return double(stop.QuadPart-start.QuadPart)/freq;
}

int potega2(int podst, int wykl)
{
	int wynik=podst;
	while(wykl>1)
	{
		wynik*=podst;
		wykl--;
	}
	return wynik;
}

	Heap kopiec;
	Tablica tablica;
	List lista;
	

int main() {
	
	srand(time(NULL));
	int pozycja;
	string nazwapliku;
	ofstream fout;
	ifstream fin;
	
	int val;
	

	
	do{				//glowna petla programu
				
		cout<<"		Wybierz strukture\n"
			<<"		1 - Tablica\n"
			<<"		2 - Lista\n"
			<<"		3 - Kopiec\n"
			<<"		4 - Generowanie pliku z danymi\n"
			<<"		8 - Zakoncz\n\n";
		
			pozycja=0-'0'; 
							
			switch (pozycja+=getch()) // sposob na obsluge menu bez wciskania klawisza enter
			{
				case 1:
				{
					do{			
						system("cls");
			
						cout<<"TABLICA		Co chcesz zrobic?\n"
							<<"		1 - Dodaj element na koncu\n"
							<<"		2 - Dodaj element na poczatku\n"
							<<"		3 - Wstaw element w dowolne miejsce\n"
							<<"		4 - Usun element z konca\n"
							<<"		5 - Usun element z poczatku\n"
							<<"		6 - Usun element z dowolnego miejsca\n"
							<<"		7 - Wyswietl zawartosc tablicy\n"
							<<"		8 - Sprawdz czy istnieje konkretna wartosc\n"
							<<"		p - Wypisz tablice do pliku\n"
							<<"		r - Wczytaj dane z pliku\n"
							<<"		9 - Powrot do menu ze strukturami\n\n";
						
							pozycja=0-'0'; 
											
							switch (pozycja+=getch())
							{
								case 1:
								{
									system("cls");
									int cododac;
									double akt=0.0;
									cout<<"Podaj wartosc ktora chcesz dodac\n";
									cin>>cododac;
									Start();
									tablica.push_back(cododac);
									akt=Stop();
									cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
									system("pause");
				
									break;
								}
								case 2:
								{
									system("cls");
									int cododac;
									double akt=0.0;
									cout<<"Podaj wartosc ktora chcesz dodac\n";
									cin>>cododac;
									Start();
									tablica.push_front(cododac);
									akt=Stop();
									cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
									system("pause");	
									break;
								}
								case 3:
								{
									system("cls");
									int cododac,gdzie;
									double akt=0.0;
									cout<<"Podaj wartosc ktora chcesz dodac\n";
									cin>>cododac;
									cout<<"\nPodaj pozycje na ktorej ma sie znalezc.\n";
									cin>>gdzie;
									Start();
									tablica.insert(gdzie,cododac);
									akt=Stop();
									cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
									system("pause");				
									break;
								}
								case 4:
								{
									system("cls");
									double akt=0.0;
									Start();
									tablica.pop_back();
									akt=Stop();
									cout<<"\nTrwalo to "<<akt<<" ms.\n";
									system("pause");				
									break;
								}
								case 5:
								{
									system("cls");
									double akt=0.0;
									Start();
									tablica.pop_front();
									akt=Stop();
									cout<<"\nTrwalo to "<<akt<<" ms.\n";
									system("pause");				
									break;
								}
								case 6:
								{
									system("cls");
									int gdzie;
									double akt=0.0;
									cout<<"Podaj pozycje z ktorej usunac element\n";
									cin>>gdzie;
									Start();
									tablica.remove(gdzie);
									akt=Stop();
									cout<<"\nTrwalo to "<<akt<<" ms.\n";
									system("pause");					
									break;	
								}	
								case 7:
								{
									system("cls");
									tablica.display();
									system("pause");
									break;	
								}
								case 8:
								{
									system("cls");
									int coszukac;
									double akt=0.0;
									cout<<"Podaj wartosc do znalezienia\n";
									cin>>coszukac;
									Start();
									tablica.find(coszukac);
									akt=Stop();
									cout<<"Przeszukiwanie trwalo: "<<akt<<" ms.\n";
									system("pause");
									break;
								}
								case 9:
								{
									system("cls");
									break;
								}
								case 64:
								{
									system("cls");
									cout<<"Podaj nazwe pliku z rozszerzeniem\n";
									cin>>nazwapliku;
									fout.open(nazwapliku.c_str());
									for(int i=0; i<tablica.size; i++)
										fout<<tablica.tab[i]<<endl;
									fout.close();	
									cout<<"\nTablica zostala wygenerowana do pliku "<<nazwapliku<<endl;
									Sleep(2000);
									break;
								}
								case 66:
								{
									system("cls");
									cout<<"Podaj nazwe pliku z rozszerzeniem\n";
									cin>>nazwapliku;
									fin.open(nazwapliku.c_str());
									int rozmiar,liczba;
									fin>>rozmiar;
									for(int i=0; i<rozmiar; i++)
										{	
											fin>>liczba;
											tablica.push_back(liczba);	
										}
									fin.close();	
									cout<<"\nDane zostaly wczytane.";
									Sleep(1500);
																	
									break;
								}
								default:
								{
									cout<<"Bledna komenda!";
									Sleep(1500);
									system("cls");
									break;
								}
							}
						}while(pozycja!=9);

						break;
					}
				case 2:
					{		
						do{			
						system("cls");
				
						cout<<"LISTA		Co chcesz zrobic?\n"
							<<"		1 - Dodaj element na koncu\n"
							<<"		2 - Dodaj element na poczatku\n"
							<<"		3 - Wstaw element w dowolne miejsce\n"
							<<"		4 - Usun element z konca\n"
							<<"		5 - Usun element z poczatku\n"
							<<"		6 - Usun element z dowolnego miejsca\n"
							<<"		7 - Wyswietl zawartosc listy\n"
							<<"		8 - Sprawdz czy istnieje konkretna wartosc\n"
							<<"		p - Wypisz liste do pliku\n"
							<<"		r - Wczytaj dane z pliku\n"
							<<"		9 - Powrot do menu ze strukturami\n\n";
						
							pozycja=0-'0'; 
							
							switch (pozycja+=getch())
							{
								case 1:
								{
									system("cls");
									int cododac;
									double akt=0.0;
									cout<<"Podaj wartosc ktora chcesz dodac\n";
									cin>>cododac;
									Start();
									lista.push_back(cododac);
									akt=Stop();
									cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
									system("pause");
				
									break;
								}
								case 2:
								{
									system("cls");
									int cododac;
									double akt=0.0;
									cout<<"Podaj wartosc ktora chcesz dodac\n";
									cin>>cododac;
									Start();
									lista.push_front(cododac);
									akt=Stop();
									cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
									system("pause");	
									break;
								}
								case 3:
								{
									system("cls");
									int cododac,gdzie;
									double akt=0.0;
									cout<<"Podaj wartosc ktora chcesz dodac\n";
									cin>>cododac;
									cout<<"\nPodaj pozycje na ktorej ma sie znalezc.\n";
									cin>>gdzie;
									Start();
									lista.insert(gdzie,cododac);
									akt=Stop();
									cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
									system("pause");				
									break;
								}
								case 4:
								{
									system("cls");
									double akt=0.0;
									Start();
									lista.pop_back();
									akt=Stop();
									cout<<"\nTrwalo to "<<akt<<" ms.\n";
									system("pause");				
									break;
								}
								case 5:
								{
									system("cls");
									double akt=0.0;
									Start();
									lista.pop_front();
									akt=Stop();
									cout<<"\nTrwalo to "<<akt<<" ms.\n";
									system("pause");				
									break;
								}
								case 6:
								{
									system("cls");
									int gdzie;
									double akt=0.0;
									cout<<"Podaj pozycje z ktorej usunac element\n";
									cin>>gdzie;
									Start();
									lista.remove(gdzie);
									akt=Stop();
									cout<<"\nTrwalo to "<<akt<<" ms.\n";
									system("pause");					
									break;	
								}	
								case 7:
								{
									system("cls");
									lista.display();
									system("pause");
									break;	
								}
								case 8:
								{
									system("cls");
									int coszukac;
									double akt=0.0;
									cout<<"Podaj wartosc do znalezienia\n";
									cin>>coszukac;
									Start();
									lista.find(coszukac);
									akt=Stop();
									cout<<"Przeszukiwanie trwalo: "<<akt<<" ms.\n";
									system("pause");
									break;
								}
								case 9:
								{
									system("cls");
									break;
								}
								case 64:
								{
									system("cls");
									cout<<"Podaj nazwe pliku z rozszerzeniem\n";
									cin>>nazwapliku;
									fout.open(nazwapliku.c_str());
									if(lista.head!=NULL)
									{
										ElemList * iter;
										iter=lista.head;
										while(iter->next!=NULL)
										{
											fout<<iter->data<<endl;
											iter=iter->next;
										}
										fout<<iter->data<<"\n";
									}
									fout.close();	
									cout<<"\nLista zostala wygenerowana do pliku "<<nazwapliku<<endl;
									Sleep(2000);
									break;
								}
								case 66:
								{
									system("cls");
									cout<<"Podaj nazwe pliku z rozszerzeniem\n";
									cin>>nazwapliku;
									fin.open(nazwapliku.c_str());
									int rozmiar,liczba;
									fin>>rozmiar;
									for(int i=0; i<rozmiar; i++)
										{	
											fin>>liczba;
											lista.push_back(liczba);	
										}
									fin.close();
									cout<<"\nDane zostaly wczytane.";
									Sleep(1500);								
									break;
								}
								default:
								{
									cout<<"Bledna komenda!";
									Sleep(1500);
									system("cls");
									break;
								}
							}
						}while(pozycja!=9);
					break;
					}
				case 3:
					{
						do{			
							system("cls");
							cout<<"KOPIEC		Co chcesz zrobic?\n"
								<<"		1 - Dodaj element\n"
								<<"		2 - Usun korzen\n"
								<<"		3 - Wyswietl strukture kopca\n"
								<<"		4 - Sprawdz czy istnieje konkretna wartosc\n"
								<<"		p - Wypisz kopiec do pliku\n"
								<<"		r - Wczytaj dane z pliku\n"
								<<"		5 - Powrot do menu ze strukturami\n\n";
							
								pozycja=0-'0'; 
												
								switch (pozycja+=getch())
								{
									case 1:
									{
										system("cls");
										int cododac;
										double akt=0.0;
										cout<<"Podaj wartosc ktora chcesz dodac\n";
										cin>>cododac;
										Start();
										kopiec.add(cododac);
										akt=Stop();
										cout<<"Element dodano. Trwalo to "<<akt<<" ms.\n";
										system("pause");
										break;
									}
									case 2:
									{
										system("cls");
										double akt=0.0;
										Start();
										kopiec.remove();
										akt=Stop();
										cout<<"\nTrwalo to "<<akt<<" ms.\n";
										system("pause");													
										break;
									}
									case 3:
									{
										system("cls");
										kopiec.display();
										system("pause");
										break;
									}
									case 4:
									{
										system("cls");
										int coszukac;
										double akt=0.0;
										cout<<"Podaj wartosc do znalezienia\n";
										cin>>coszukac;
										Start();
										kopiec.find(coszukac);
										akt=Stop();
										cout<<"Przeszukiwanie trwalo: "<<akt<<" ms.\n";
										system("pause");									
										break;
									}
									case 5:
									{
										system("cls");
										break;
									}
									case 64:
									{
										system("cls");
										cout<<"Podaj nazwe pliku z rozszerzeniem\n";
										cin>>nazwapliku;
										fout.open(nazwapliku.c_str());
										int level=1;
										for(int i=0; i<kopiec.size; i++)
										{
											fout<<kopiec.tab[i]<<"  ";
											if(potega2(2,level)-2==i)
											{
												fout<<endl;
												level++;
											}
										}
										fout.close();	
										cout<<"\nKopiec zostal wygenerowany do pliku "<<nazwapliku<<endl;
										Sleep(2000);
										break;
									}
									case 66:
									{
										system("cls");
										cout<<"Podaj nazwe pliku z rozszerzeniem\n";
										cin>>nazwapliku;
										fin.open(nazwapliku.c_str());
										int rozmiar,liczba;
										fin>>rozmiar;
										for(int i=0; i<rozmiar; i++)
											{	
												fin>>liczba;
												kopiec.add(liczba);	
											}
										cout<<"\nDane zostaly wczytane.";
										fin.close();
										Sleep(1500);										
										break;
									}									
									default:
									{
										cout<<"Bledna komenda!";
										Sleep(1500);
										system("cls");
										break;
									}
								}
						}while(pozycja!=5);
					break;
					}
				case 4:
					{
						system("cls");
						string nazwapliku;
						ofstream out;
						int liczba,los;
						cout<<"Podaj nazwe pliku wraz z rozszerzeniem do ktorego wygenerowac dane \n";
						cin>>nazwapliku;
						out.open(nazwapliku.c_str());
						cout<<"\nIle liczb wygenerowac?\n";
						cin>>liczba;
						out<<liczba<<endl;
						for(int i=0; i<liczba; i++)
						{
							los=rand()-16384;
							out<<los<<endl;
						}
						out.close();
						cout<<"\nWygenerowano "<<liczba<<" liczb.";
						Sleep(1500);
						system("cls");
						break;
					}	
				case 8:
					{
						system("cls");
						cout<<"Do widzenia!"<<endl;
					break;
					}
				default:
					{
						cout<<"Bledna komenda!";
						Sleep(1500);
						system("cls");
					break;
					}
			}
	}while(pozycja!=8);
	
	
	


	system ("pause");
	return 0;
}
