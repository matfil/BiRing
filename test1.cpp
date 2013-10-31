#include <iostream>
#include "biring.h"

const int STOP = 1<<31;

int main()
{
BiRing<int> test;
BiRing<int>::iterator it;
int data[] = { 1, 2, -3, 10, 10, 10, 8, 7, 14, 5, 0, STOP};
for(int i=0; data[i]!=STOP; ++i)
	{
	test.push_back(data[i]);
	}
for(it = test.begin(); it != test.end(); ++it)
	{
	cout << *it << " ";
	}
cout << endl;
return 0;
}
