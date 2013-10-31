#include <iostream>
#include "biring.h"
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define DBG(X) cout << X
#else
#define DBG(X)
#endif


int main()
{
BiRing<int> test;/*
int q[] = { 2, 7, 14, -3, 0, 0, 1, 12 };
for (int i=0; i<8; ++i)
	test.push_back(q[i]);
BiRing<int>::iterator it(test.begin());
BiRing<int>::iterator fi = test.begin();
cout << *fi << endl;
cout << "wartosci zawarte w naszym birindziku:\n" ;
while(it != test.end())
	{
		cout << *it << endl;
		++it;
	}
++fi;
cout << "fi: " << *fi << "\nusuwam!\n";
test.remove(fi);
for(it=test.begin(); it != test.end();)
	{
		cout << *it << endl;
		++it;
	}*/
BiRing<int>::iterator it;
it = test.end();

while(true)
	{
		char wybor;
		cout << "co chcesz zrobic? + - dodaj element, - - usun element, > - przesun w prawo, < - przesun w lewo, w - wypisz wartosc, W - wypisz wszystko, s - rozmiar kontenera, # - quit\n";
		cin >> wybor;
		switch(wybor)
		{
			case '+':
			{
				cout << "podaj wartosc\n";
				int q;
				cin >> q;
				test.insert(q, it);
				break;
			}
			case '-':
			{
				cout << "usuwam element o wartosci " << *it << "\n";
				try
				{
					it=test.remove(it);
				}
				catch(char const* exc)
				{
					cout << "jeszcze raz przemyśl swoje działania\nnie można usuwać końca kontenera\n";
				}
				break;
			}
			case '>':
			{
				cout << "przesuwam >>, teraz pokazujesz na ";
				++it;
				if(it == test.end())
					cout << "koniec kontenera\n";
				else
					cout << *it << "\n";
				break;
			}
			case '<':
			{
				cout << "przesuwam <<, teraz pokazujesz na ";
				--it;
				if(it == test.end())
					cout << "koniec kontenera\n";
				else
					cout << *it << "\n";
				break;
			}
			case 'w':
			{
				cout << "teraz pokazujesz na ";
				if(it == test.end())
					cout << "koniec kontenera\n";
				else
					cout << *it << "\n";
				break;
			}
			case 'W':
			{
				cout << "wypisuje cala zawartosc:\n";
				for(BiRing<int>::iterator q=test.begin(); q!=test.end(); ++q)
					{
						cout << *q << " ";
					}
				cout << "\n";
				break;
			}
			case 's':
			{
				cout << "masz " << test.Size()  << " elementow\n";
				break;
			}
			default: return 0;
		}
	}
return 0;
}


