/***********************
Andrei Kuzmiankov
CISP400 MW 5:30-6:50pm
ULong.cpp
October 2, 2013
***********************/
#include <iostream>
#include "ULong.h"
using namespace std;

int
main()
{
	ULong n1("10");
	ULong n2("5");
	n1.display();
	n2.display();
	n1.add(n2);
	cout << "10" << "+"<<"5"<< "=";
	return 0;

}
						
