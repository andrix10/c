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

ULong::ULong ( const char* c )
{
	_initialize();
	if ( c == NULL || c[0] == '\0' ) return;
	while ( c[_num_digits++] != '\0' );
		_num_digits--;
	if ( _num_digits >= PRECISION )
	{
		cout << "ERROR";
		cin.get();
		exit(1);
	}
	unsigned index = 0;
	while ( index < _num_digits )
	{
		_number[index] = c[_num_digits-(index+1)];
		index++;
	}
}

ULong::ULong(unsigned long long n )
{
	_initialize();
	unsigned ind = 0;
	_num_digits = 0;
	while ( n > 0 )
	{
		_number[ind++] = n%10 + '0';
		n /= 10;
		_num_digits ++;
	}
}

ULong::ULong(const ULong& r)
{
	_num_digits=r._num_digits;
	for(unsigned i=0;i<PRECISION;i++)
		_number[i]=r._number[i];
	
}	

void ULong::_initialize()
{
	//_num_digits=1;
    for(unsigned i = 0; i < PRECISION; i++)
	{   
		_number[i] = '0';
	}   
	_num_digits=1;
}

ostream& operator<< ( ostream& os, const ULong& ul)
{
	for ( int i = ul._num_digits-1; i>=0; i-- )
	{
		//if ( i != ul._num_digits-1 && i%3 == 2 )
		//os << ",";
		os << ul._number[i];
	}
	return os;
}

istream& operator>> ( istream& is, ULong& ul)
{
	char temp[PRECISION];
	is >> temp;
	//_no_comma(temp); //remove commas from temp
	ul = ULong(temp);
	return is;
}

ULong& ULong::operator+=(const ULong& l)
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
	return *this;
}

ULong& ULong::operator-=(const ULong& l)
{
	if ( (l._num_digits > _num_digits) || (l._num_digits==_num_digits && (l._number[_num_digits-1] > _number[_num_digits-1]) ))
    {
        _initialize();
        return *this;
    }
    bool decrease = false;
    ULong temp;
    char borrow = 0;
    for ( unsigned i=0; i<PRECISION; i++)
    {
        temp._number[i] = ((_number[i]-'0') - ((l._number[i]-'0') + borrow));
        if(_number[i] < (l._number[i]+borrow))
        {
            temp._number[i]+=10;
            borrow = 1;
            if(_number[i] < (l._number[i]+borrow)&& i == _num_digits-1)
			{   
            	_initialize();
                return *this;
			}
        }
        else
        {
            borrow = 0;
        }

		temp._number[i] += '0';
		if ( i == _num_digits-1 && temp._number[i] == '0' && _num_digits > 0 )
        {
            decrease = true;
        }
		else decrease = false;
    }
    if ( decrease )
    {
        _num_digits--;
    }
	if(_num_digits>1)
	{
		while(temp._number[_num_digits-1]=='0')
		{
			_num_digits--;
		}
	}
    for ( unsigned i=0; i<PRECISION; i++ )
    {
        _number[i] = temp._number[i];
    }
	return *this;
}

ULong ULong::operator- (const ULong& l) const
{
    return ULong(*this)-=l;
}

ULong ULong::operator- (unsigned long long l) const
{
    return *this - ULong(l);
}

ULong operator- (unsigned long long l, const ULong& r)
{
    return ULong(l) - r;
}

ULong& ULong::operator*=(const ULong& r)
{
    if ( r._num_digits == 1 && r._number[0] < '2')
    {
        if ( r._number[0] == '0' )
            _initialize();
            return *this; 
    }
    if ( _num_digits == 1 && _number[0] < '2' )
    {
        if ( _number[0] == '1' )
        {
            _num_digits = r._num_digits;
            for ( unsigned i=0; i<_num_digits; i++ )
                _number[i] = r._number[i];
        }
        return *this;
    }
    ULong cnt("1");
    ULong one("1");
    ULong RHS(r);
    ULong LHS;
    LHS = *this;
    while ( cnt != RHS )
    {
        operator+=(LHS);
        cnt+=one;
    }
    return *this;

}

ULong ULong::operator* (const ULong& l) const
{
    return ULong(*this)*=l;
}

ULong ULong::operator* (unsigned long long l) const
{
    return (*this) * ULong(l);
}

ULong operator* (unsigned long long l, const ULong& r)
{
    return ULong(l) * r;
}

ULong& ULong::operator/=(const ULong& l)
{
    if ( l._num_digits == 1 && l._number[0] < '2')
    {
        if ( l._number[0] == '0' )
        {
            cout << "ERROR: division by zero"<<endl;
            cin.get();
            exit(1);
        }
        return *this;
    }
    if ( (l._num_digits > _num_digits)||(l._number[_num_digits-1] > _number[_num_digits-1]) )
    {
        _initialize();
        return *this;
    }
    ULong cnt;
	ULong one("1");
    while ( *this>l || *this==l )
    {
        cnt+=one;
		*this-=l;
    }
    *this = cnt;
	return *this;
}
ULong ULong::operator/ (const ULong& l) const
{
	return ULong(*this)/=l;
}

ULong ULong::operator/ (unsigned long long l) const
{
	return (*this) / ULong(l);
}

ULong operator/ (unsigned long long l, const ULong& r)
{
	return ULong(l)/r;
}

ULong& ULong::operator%=( const ULong& l)
{
    if ( l._num_digits == 1 && l._number[0] < '2')
    {   
        if ( l._number[0] == '0' )
        {   
            cout << "ERROR: division by zero"<<endl;
            cin.get();
            exit(1);
        }   
        return *this;
    }   
    if ( (l._num_digits > _num_digits)||(l._number[_num_digits-1] > _number[_num_digits-1]) )
    {   
        _initialize();
        return *this;
    }   
    ULong cnt;
    ULong one("1");
	ULong copy=l;
	ULong copy2=*this;
    while ( *this>l || *this==l )
    {   
        cnt+=one;
        *this-=l;	
    }   
	*this=copy2-(copy*cnt);
	//cout<<cnt<<" ";
	//cout<<*this<<"\n";
    return *this;
}

ULong ULong::operator% (const ULong& l) const
{
    return ULong(*this)%=l;
}

ULong ULong::operator% (unsigned long long l) const
{
    return (*this) % ULong(l);
}

ULong operator% (unsigned long long l, const ULong& r)
{
    return ULong(l)%r;
}


ULong ULong::operator++ (int) //post
{
	//use copy constr
	return *this;
}

ULong ULong::operator-- (int) //post
{
	return *this;
}

ULong& ULong::operator++ () //pre
{
	return *this;
}

ULong& ULong::operator-- () //pre
{
	return *this;
}

bool ULong::operator< (const ULong& l) const
{
	return !(*this>l);
}

bool ULong::operator< (unsigned long long l) const
{
	return (*this) < ULong(l);
}

bool operator< (unsigned long long l, const ULong& r)
{
	return ULong(l) < r;
}

bool ULong::operator> (const ULong& l) const
{
	bool greater=true;
    unsigned k = _num_digits;
    if (_num_digits < l._num_digits) k=l._num_digits;
    for(unsigned i = 0; i < k; i++)
    {
        //cout<< _num_digits;
        //cout<<endl<<_number[i]<<endl<<l._number[i];
        if(_number[i] < l._number[i]) greater=false;   
        else if(_number[i]!=l._number[i]) greater=true;
    }   
	return greater;
}

bool ULong::operator> (unsigned long long l) const
{
	return (*this) > ULong(l);
}

bool operator> (unsigned long long l, const ULong& r)
{
	return ULong(l)>r;
}
	
ULong& ULong::operator=(const ULong& r)
{
	_num_digits = r._num_digits;
	for(unsigned i=0;i<PRECISION;i++)
		_number[i] = r._number[i];
	return *this;
}

bool ULong::operator==(const ULong& r) const
{
	if(_num_digits != r._num_digits) return false;
	for(unsigned i=0;i<_num_digits;i++)
	{
		if(_number[i] != r._number[i]) return false;
	}
	return true;
}

bool ULong::operator==(unsigned long long l) const
{
	return (*this)==ULong(l);
}

bool operator==(unsigned long long l,const ULong& r)
{
	return ULong(l)==r;
}

bool ULong::operator!=(const ULong& r) const
{
	return !(*this== r);
}

bool ULong::operator!=(unsigned long long l) const
{
	return (*this) != ULong(l);
}

bool operator!=(unsigned long long l,const ULong& r)
{
	return ULong(l) != r;
}

ULong ULong::operator+ (const ULong& r) const
{
	return ULong(*this)+=r;
}

ULong ULong::operator+ (unsigned long long l) const
{
	return (*this) + ULong(l);
}

ULong operator+ (unsigned long long l, const ULong& r)
{
	return ULong(l) + r;
}

bool ULong::operator<= (const ULong& l) const
{
	return !(*this>=l);
}

bool ULong::operator<= (unsigned long long l) const
{
	return *this<=ULong(l);
}

bool operator<= (unsigned long long l, const ULong& r)
{
	return ULong(l)<=r;
}

bool ULong::operator>= (const ULong& l) const
{
	bool greater=true;
    unsigned k = _num_digits;
    if (_num_digits < l._num_digits) k=l._num_digits;
    for(unsigned i = 0; i < k; i++)
    {   
        //cout<< _num_digits;
        //cout<<endl<<_number[i]<<endl<<l._number[i];
        if(_number[i] < l._number[i]) greater=false;   
        else greater=true;
    }   
    return greater;

}

bool ULong::operator>= (unsigned long long l) const
{
	return *this >= ULong(l);
}

bool operator>= (unsigned long long l, const ULong& r)
{
	return ULong(l)>=r;
}
