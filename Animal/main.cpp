#include <iostream>
#include "animal.h"
#include "bird.h"
#include "eagle.h"
using namespace std;

int
main()
{
	Eagle ea("Bird");
	Animal *a = &ea;
	ea.FeedingCycle(1.6);
	ea.Name("Big Bird");
	ea.Display();
	cout<<endl;
	a->Name("Big Bird2");
	ea.Display();
}

