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
		iterator(Node *n) : ptr(n) {}
		iterator& operator++()
			{
				DBG("inkrementuje " << ptr << " ktory zawieral wartosc " << ptr->val << " do " << ptr->next << endl);
				this->ptr = this->ptr->next;
				return *this;
			}

		T& operator*()
			{
				DBG("odwolanie do iteratora " << ptr << endl);
				return ptr->val;
			}
		bool operator!=(iterator it)
			{
				return it.ptr != ptr;
			}
	};

	BiRing(T init_val=0) : head( Node(init_val, &head, &head) ), nElem(0)
	{ }
	
	iterator remove(iterator * to_remove)
	{
		if (to_remove == nullptr || to_remove == head)
		{
			throw("invalid pointer in remove function");
		}
		to_remove -> prev -> next = to_remove -> next;
		to_remove -> next -> prev = to_remove -> prev;
		--nElem;
		return delete to_remove, to_remove->next;
		//DO SPRAWDZENia
	}
	
	void push_back(T value)
	{
		DBG("funkcja pushback, wartosc " << value << endl);
		head.prev = head.prev->next = new Node(value, &head, head.prev);
		++nElem;
	}
	//do zdefiniowania: ++, =, !=, konstruktor, *, ==


	iterator begin()
	{
		return iterator(head.next);
	}

	iterator end()
	{
		return iterator(&head);
	}

};

int main()
{
BiRing<int> test;
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
/*try
{
	test.remove(test.head);
}*/
return 0;
}


