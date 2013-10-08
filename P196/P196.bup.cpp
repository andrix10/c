/*****************************************************

    Andrei Kuzmiankov
    CISP 400 - MW 5:30 pm
    Programming Project 1
    September 9, 2013

*****************************************************/
#include <iostream>
#include <limits.h>
using namespace std;

unsigned num_digits ( unsigned long l);
int nth_digit(unsigned long l, unsigned int n);
unsigned long rev_digits(unsigned long l);
bool is_palindrome(unsigned long l);
bool P196(unsigned long l);


int main()
{
	unsigned long l,k;
	unsigned int n,g;
	cout<<"enter a number, and an nth digit\n";
	cin >> l>>n;
	k=num_digits(l);
	g=nth_digit(l,n);
	cout<<k<<endl<<g<<endl<<rev_digits(l)<<endl<<P196(l)<<endl;

}

unsigned num_digits ( unsigned long l)
{
	int m = 0;
	if(0>l) m =1;
	while(l){
		l/=10;
		m++;
	}
	return m;
}

int nth_digit(unsigned long l, unsigned int n)
{
	unsigned int m,k=1,g,c,z;
	unsigned long num;
	num=num_digits(l);
	if(n<num+1){	
		for(m=0;m<n;m++){
			k*=10;
        	}
		
		g=l/k;			
		c=g*k;
		k=1;
		for(m=0;m<n-1;m++){
                       	k*=10;
                }
                z=(l-c)/k;
		return z;
	}
	else{ 
		return 500;
	}	
}

unsigned long rev_digits(unsigned long l)
{
	unsigned int m=1,n,k=1,g,i;
	unsigned long ans=0;
	n=num_digits(l);
	while (m<n+1){	
		for(i=m;n>i;i++){
                	k*=10;
                }	
		g=nth_digit(l,m);
		ans=(g*k)+ans;
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
	unsigned long lsub=l;
	bool p=false;
	while(l<ULONG_MAX && p==false ){
		if(is_palindrome(lsub)==true)
		{
			p=true;
		}
		else{
	
			lsub++;
		}
	}
	cout<<lsub<<"(k)";
	return p;	
}


