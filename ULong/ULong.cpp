/***********************
Andrei Kuzmiankov
CISP400 MW 5:30-6:50pm
ULong.cpp
October 2, 2013
***********************/
#include <iostream>
#include <cstdlib>
#include "ULong.h"
using namespace std;

ULong::ULong()
{
    	_initialize();
}

ULong::ULong(const char* num)
{
	unsigned i=0,k=0;
	while(k < PRECISION)
    {
       	if( num[k] >= '0' && num[k] <= '9' )
       	{
               	i++;
       	}
	else
	{		
			k=PRECISION;
	}
	k++;
   }
    _num_digits = i;
  	for(k = 0; k < _num_digits; k++)
	{
		_number[_num_digits - k - 1] = num[k];
	}
	
	for(k = _num_digits; k < PRECISION; k++)
	{
		_number[k]='0';
	}
}

void ULong::_initialize()
{
    for(unsigned i = 0; i < PRECISION; i++)
   	{
       	_number[i] = '0';
   	}
 	_num_digits =1;
}

 
bool ULong::equal(const ULong& l) const
{
    	for(unsigned i = 0; i < PRECISION; i++)
    	{
        	if(_number[i] != l._number[i])
            	return false;
    	}
    	return true;
}

bool ULong::is_greater(const ULong& l) const
{
	bool greater=true;
	unsigned k = _num_digits;
	if (_num_digits < l._num_digits) k=l._num_digits;
    for(unsigned i = 0; i < k; i++)
    {
		//cout<< _num_digits;
		//cout<<endl<<_number[i]<<endl<<l._number[i];
		if(_number[i] < l._number[i]) greater= false;	
		else if(_number[i]!=l._number[i]) greater = true;
    }	
	return greater;
}
  

 
void ULong::display() const
{
  	for(unsigned i = _num_digits-1;i>0; i--)
    	{	
        	cout << _number[i];
    	}
	cout<<_number[0]<<endl;
    	
}

void ULong::add ( const ULong& l )
{
	ULong temp;
	bool increase = false; //will we have to increase _num_digits?
	if ( l._num_digits > _num_digits ) //the number of digits will be
	{
		_num_digits = l._num_digits;
	}
	//at least as large as the largest of the two numbers
	char carry = 0;
	for ( unsigned i=0; i<PRECISION; i++ )
	{
		//I have stored as characters
		//so convert to number to do the addition:u
		temp._number[i] = (_number[i]-'0') + (l._number[i]-'0') + carry;
		//check for overflow
		if ( temp._number[i] > 9 )
		{
			temp._number[i] -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		//convert back from number to character
		temp._number[i] += '0';
		//check to see if we need to increase _num_digits
		if ( i == _num_digits-1 && carry != 0 )
		{
			increase = true;
		}
	}
	if ( increase )
		_num_digits++;
	//check to see if the answer is too large to fit
	if ( _num_digits >= PRECISION )
	{		
		cout << "ERROR in add - _num_digits: " << _num_digits << " >= PRECISION: " << PRECISION << endl;
		cin.get();
		exit(1);
	}
	for ( unsigned i=0; i<PRECISION; i++ )
	{
		_number[i] = temp._number[i];
	}
}

void ULong::sub ( const ULong& l )
{
	if ( (l._num_digits > _num_digits) || (l._number[_num_digits-1] > _number[_num_digits-1]) )
	{
		_initialize();
		return;
	}
	bool decrease = false;
	ULong temp;
	char borrow = 0;
	for ( unsigned i=0; i<PRECISION; i++)
	{
		//cout<<_number[i] - l._number[i];
		//cout<<l._number[i];
		//cout<<_number[i];
		temp._number[i] = ((_number[i]-'0') - ((l._number[i]-'0') + borrow));
		//cout<< temp._number[i]+'0';
		if(_number[i] < (l._number[i]+borrow))
		//if(temp._number[i] < 0)
		{
			temp._number[i]+=10;
			borrow = 1;
			if(_number[i] < (l._number[i]+borrow)&& i == _num_digits-1)

    			{   
        			_initialize();
        			return;
    			} 
		}
		else
		{
			borrow = 0;
		}
		//temp._number[i] += '0';
		if ( i == _num_digits-1 && temp._number[i] == 0 && _num_digits > 1 )
		{
			decrease = true;
		}
		temp._number[i] += '0';
		//cout<<temp._number[i]<<endl;
	}
	if ( decrease )
	{
		_num_digits--;
	}
	for ( unsigned i=0; i<PRECISION; i++ )
	{
		_number[i] = temp._number[i];
	}
}

void ULong::div ( const ULong& l )
{
	//if l is 0 or 1
	//cout<<"start\n";
	if ( l._num_digits == 1 && l._number[0] < '2')
	{
		//cout<<"first if\n";
		if ( l._number[0] == '0' )
		{
			cout << "ERROR: division by zero"<<endl;
			cin.get();
			exit(1);
		}
		return;
	}
	//if l is larger
	if ( (l._num_digits > _num_digits)||(l._number[_num_digits-1] > _number[_num_digits-1]) )
	{
		//cout<< "\nis larger\n";		
		_initialize();
		return;
	}
	ULong cnt;
	while ( is_greater(l) || equal(l) )
	{
		cnt.add("1");
		//cout<<"is greater\n";
		sub(l);
	}
	*this = cnt;
}

void ULong::mult(const ULong& l)
{
	if ( l._num_digits == 1 && l._number[0] < '2')
	{
		if ( l._number[0] == '0' )
			_initialize();
			return;	
	}
	if ( _num_digits == 1 && _number[0] < '2' )
	{
		if ( _number[0] == '1' )
		{
			_num_digits = l._num_digits;
			for ( unsigned i=0; i<_num_digits; i++ )
				_number[i] = l._number[i];
		}
		return;
	}
	ULong cnt("1");
	ULong one("1");
	ULong RHS = l;
	ULong LHS;
	LHS = *this;
	while ( !cnt.equal( RHS ) )
	{
		add(LHS);
		cnt.add(one);
	}

}
