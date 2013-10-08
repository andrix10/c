/***********************
Andrei Kuzmiankov
CISP400 MW 5:30-6:50pm
ULong.cpp
October 2, 2013
***********************/
#ifndef _ULONG_H_
#define _ULONG_H_
const unsigned PRECISION = 50; //or any other positive value
#include <iostream>
using namespace std;

class ULong
{
	char _number[PRECISION];
	unsigned _num_digits;
	void _initialize();
public:
	ULong ();
	ULong ( const char* );
	void add ( const ULong& );
	void sub ( const ULong& );
	void mult ( const ULong& );
	void div ( const ULong& );
	bool equal ( const ULong& )const;
	bool is_greater ( const ULong& )const;
	void display() const;
};
#endif

