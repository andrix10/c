/***********************
Alex Vasilenko
CISP400, MW, 5:30-6:50pm
ULong
October 2, 2013
***********************/
#include <iostream>
//#include <climits>
#include "ULong.h"

using namespace std;

int main(int argc, char** argv)
{
	ULong num;
	ULong num1;
	ULong num2;
	cin >> num;
	num+=5;
	cout << num<<endl;
	num*=10;
	cout<<num<<endl;
	cout<<num+5<<endl;
	num1=50;
	num2=50;
	if(num1==num2) cout<<"equals";
	else cout<<"fail";
	if(num!=num1) cout<<"not equals";
	else cout<<"fail";
	return 0;
}

