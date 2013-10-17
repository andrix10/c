/***********************
Andrei Kuzmiankov
CISP400 MW 5:30-6:50pm
ULong.cpp
October 12, 2013
***********************/
#ifndef _ULong_H_
#define _ULong_H_
#include <iostream>
using namespace std;
const unsigned PRECISION = 1000;
class ULong
{
	char
	_number[PRECISION];
	unsigned _num_digits;
	// index i holds the 10^i digit
	//I used these private member functions in my implementation
	void _initialize();
	// _num_digits == 1 &&
	// for 0<=i<PRECSION _number[i] == '0'
	void _mult10(unsigned n = 1); // multiply by 10 n times
	void _mult( char n );
	// multiply by n
	void _div10();
	// divide by 10
	bool _is_mult10()const;
	// is this a multiple of 10
	void _set_num_digits();
public:
	ULong ();
	ULong ( const char *);
	ULong ( unsigned long long );
	ULong (const ULong& );
	ULong& operator= ( const ULong& );
	ULong& operator+= ( const ULong& );
	ULong& operator-= ( const ULong& );
	ULong& operator*= ( const ULong& );
	ULong& operator/= ( const ULong& );
	ULong& operator%= ( const ULong& );

	friend ostream& operator<< ( ostream&, const ULong&);
	friend istream& operator>> ( istream&, ULong&);

	ULong operator+ (const ULong& ) const;
	ULong operator+ (unsigned long long) const;
	friend ULong operator+ (unsigned long long, const ULong&);

	ULong operator- (const ULong& ) const;
	ULong operator- (unsigned long long) const;
	friend ULong operator- (unsigned long long, const ULong&);

	ULong operator* (const ULong& ) const;
	ULong operator* (unsigned long long) const;
	friend ULong operator* (unsigned long long, const ULong&);

	ULong operator/ (const ULong& ) const;
	ULong operator/ (unsigned long long) const;
	friend ULong operator/ (unsigned long long, const ULong&);

	ULong operator% (const ULong& ) const;
	ULong operator% (unsigned long long) const;
	friend ULong operator% (unsigned long long, const ULong&);

	ULong operator++ (int); //post
	ULong operator-- (int); //post
	ULong& operator++ (); //pre
	ULong& operator-- (); //pre

	bool operator== (const ULong& ) const;
	bool operator== (unsigned long long) const;
	friend bool operator== (unsigned long long, const ULong&);

	bool operator< (const ULong& ) const;
	bool operator< (unsigned long long) const;
	friend bool operator< (unsigned long long, const ULong&);

	bool operator!= (const ULong& ) const;
	bool operator!= (unsigned long long) const;
	friend bool operator!= (unsigned long long, const ULong&);

	bool operator> (const ULong& ) const;
	bool operator> (unsigned long long) const;
	friend bool operator> (unsigned long long, const ULong&);

	bool operator<= (const ULong& ) const;
	bool operator<= (unsigned long long) const;
	friend bool operator<= (unsigned long long, const ULong&);

	bool operator>= (const ULong& ) const;
	bool operator>= (unsigned long long) const;
	friend bool operator>= (unsigned long long, const ULong&);
};
#endif

