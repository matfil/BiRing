#include <iostream>
#include <iterator>
using namespace std;

//#define DEBUG
#ifdef DEBUG
#define DBG(X) cout << X
#else
#define DBG(X)
#endif

template <class T> 
class BiRing 
{
private:
	struct Node
	{
		T val;
		Node *next, *prev;

		Node(T v=0, Node *n=0, Node *p=0) : 
		val(v), next(n), prev(p) 
		{ }
	};

	Node head;
	int nElem;

public: 
	class iterator
	{
	private:
		Node *ptr;
	public:
		iterator(Node *n=nullptr) : ptr(n) {}
		iterator& operator++()
			{
				DBG("inkrementuje " << ptr << " ktory zawieral wartosc " << ptr->val << " do " << ptr->next << endl);
				this->ptr = this->ptr->next;
				return *this;
			}
		iterator& operator--()
			{
				DBG("dekrementuje " << ptr << " ktory zawieral wartosc " << ptr->val << " do " << ptr->prev << endl);
				this->ptr = this->ptr->prev;
				return *this;
			}
		T& operator*()
			{
				DBG("odwolanie do iteratora " << ptr << endl);
				return ptr->val;
			}
		bool operator!=(iterator it)
				{return it.ptr != ptr;}
		bool operator==(iterator it)
				{return it.ptr == ptr;}
		Node* operator->()
				{return ptr;}
		bool operator==(Node *wsk)
				{return ptr == wsk;}
		iterator operator=(Node *wsk)
			{
				ptr = wsk;
				return *this;
			}
	friend class BiRing;
	};

	BiRing(T init_val=0) : head( Node(init_val, &head, &head) ), nElem(0) { }
	
	int size()
		{return nElem;}

	iterator remove(iterator to_remove)
	{
		if (to_remove == nullptr || to_remove == &head)
		{
			throw("invalid pointer in remove function");
		}
		to_remove -> prev -> next = to_remove -> next;
		to_remove -> next -> prev = to_remove -> prev;
		--nElem;
		
		iterator ret_val = iterator(to_remove->next);
		delete to_remove.ptr;
		return ret_val;
	}
	
	void insert(T value, iterator where)
	{
		DBG("funkcja insert, wartosc " << value << endl);
		where.ptr->next = where.ptr->next->prev = new Node(value, where.ptr->next, where.ptr);
		++nElem;
	}
	void push_back(T value)
	{
		DBG("funkcja pushback, wartosc " << value << endl);
		head.prev = head.prev->next = new Node(value, &head, head.prev);
		++nElem;
	}
	iterator begin()
		{return iterator(head.next);}
	iterator end()
		{return iterator(&head);}

};

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
BiRing<int>::iterator it(test.end());

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
				it=test.remove(it);
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
				cout << "masz " << test.size()  << " elementow\n";
				break;
			}
			default: return 0;
		}
	}
return 0;
}


