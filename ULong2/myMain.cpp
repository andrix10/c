/**********************
Andrei Kuzmiankov
CISP400 MW5:30-6:50pm
October 2, 2013
***********************/
#include <iostream>
//#include <climits>
#include "ULong.h"

using namespace std;

int main(int argc, char** argv)
{
	ULong rhs;
	ULong lhs;
	cout<<"Please enter 2 numbers: \n";
	cin>>lhs>>rhs;
	cout<<"addition: ";
	cout<<lhs+rhs<<"\n";
	cout<<"subtraction: ";
	cout<<lhs-rhs<<"\n";
	cout<<"multiplication: ";
	cout<<lhs*rhs<<"\n";
	cout<<"division: ";
	cout<<lhs/rhs<<"\n";
	cout<<"mod: ";
	cout<<lhs%rhs<<"\n";
	if(lhs>rhs) cout<<lhs<<" greater then "<<rhs<<"\n";
	if(lhs<rhs) cout<<lhs<<" less then "<<rhs<<"\n";
	if(lhs==rhs) cout<<lhs<<" equals "<<rhs<<"\n";
	if(lhs!=rhs) cout<<lhs<<" does not equal "<<rhs<<"\n";
	if(lhs>=rhs) cout<<lhs<<" greater or equals "<<rhs<<"\n";
	if(lhs<=rhs) cout<<lhs<<" less or equals "<<rhs<<"\n";
	cout<<lhs++<<" "<<lhs<<" post increment"<<"\n";
	cout<<lhs--<<" "<<lhs<<" post decrement"<<"\n";
	cout<<++rhs<<" pre increment"<<"\n";
	cout<<--rhs<<" pre decrement"<<"\n";
}
