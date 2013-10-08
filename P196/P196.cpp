/*****************************************************

    Andrei Kuzmiankov
    CISP 400 - MW 5:30 pm
    Programming Project 1
    September 9, 2013

*****************************************************/
#include <iostream>
#include <limits.h>
using namespace std;

unsigned num_digits ( unsigned long );
int nth_digit(unsigned long, unsigned );
unsigned long rev_digits(unsigned long );
bool is_palindrome(unsigned long );
bool P196(unsigned long );


int main()
{
    const unsigned long MAX_TEST = 200;
    for(unsigned long L = 0; L <= MAX_TEST; L++)
    {
        if(P196(L))
            cout << L << ": Is P196" << endl;
        else
            cout << L << ": Not P196" << endl;
    }
    return 0;
}

unsigned num_digits ( unsigned long l)
{
	int m = 0;
	if(0>=l) m =1;
	while(l){
		l/=10;
		m++;
	}
	return m;
	
}

int nth_digit(unsigned long l, unsigned n)
{
	
	if(n == 0)
	{	
		return l%10;
    	}
    	if(l<10)
    	{
        	return -1;
    	}
    	return nth_digit(l/10, n-1);
}

unsigned long rev_digits(unsigned long l)
{
	unsigned int m=0,n,k=1,g,i;
	unsigned long ans=0;
	n=num_digits(l);
	while (m<n){	
		for(i=m+1;n>i;i++){
                	k*=10;
                }	
		g=nth_digit(l,m);
		if(g>0 && m!=n) ans=(g*k)+ans;
		else if(m==n) ans=ans+g;
		else return 1;
		k=1;
		m++;
        }
	return ans;
}

bool is_palindrome(unsigned long l)
{
       return l == rev_digits(l);
}

bool P196(unsigned long l)
{
	unsigned long lsub=l,ans=0;
	bool p=false;
	while(!p){
		ans = rev_digits(lsub);
		lsub = lsub + ans;
		if(ULONG_MAX - lsub < ans)
                {
                        return false;
                }
		if(is_palindrome(lsub))
		{
			return true;
		}
	}	
	return p;
}
