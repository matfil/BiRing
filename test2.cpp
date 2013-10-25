#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BIRING.cpp"

const int SIZE = 50, MAXS = 10000;

int main(int argc, char ** argv)
{
BiRing<int> test;
BiRing<int>::iterator it;
if (argc >= 2)
	{
	srand(atoi(argv[1]));
	}
else
	srand( time(NULL) );
for(int i=0; i< SIZE; ++i)
	{
	test.push_back(rand() % (2*MAXS) - MAXS);
	}
int q;
q=0;
for(it = test.begin(); it != test.end(); ++it)
	{
	++q;
	cout.width(5);
	cout << *it;
	if(!(q%5)) cout << endl;
	else cout << " ";
	}
cout << "size: " << test.size() << endl;
for(int i=0; i < SIZE/5; ++i)
	{
	int to_del = rand() % test.size();
	it = test.begin();
	for(int j=0; j<to_del; ++j)
		++it;
	test.remove(it);
	}
q=0;
for(it = test.begin(); it != test.end(); ++it)
	{
	++q;
	cout.width(5);
	cout << *it;
	if(!(q%5)) cout << endl;
	else cout << " ";
	}
cout << "size: " << test.size() << endl;
return 0;
}
