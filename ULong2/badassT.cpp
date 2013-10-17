#include <iostream>
#include "ULong.h"
using namespace std;

int main()
{

	for(unsigned long long i=0; i<=10000;i++)
	{
		for(unsigned long long j=0;i<=10000;i++) 
		{
			ULong ui(i);
			ULong uj(j);
			if((ui==uj) != (i==j))
				cout<<"op error =="<<endl;
	
			if((i==uj) != (i==j))
				cout<<"op error == unsigned long long"<<endl;
		
			if((uj==i) != (j==i))
				cout<<"op error == ull"<<endl;
	
			if((ui!=uj) != (i!=j))
				cout<<"op error !="<<endl;
			
			if((i!=uj) != (i!=j))
				cout<<"op error != ull"<<endl;
	
			if((ui>uj) != (i>j))
				cout<<"op error >"<<endl;
		
			if((i>uj) != (i>j))
				cout<<"op error > ull"<<endl;
		
			if((i<uj) != (i<j))
				cout<<"op error < ull"<<endl;
	
			if((ui<uj) != (i<j))
				cout<<"op error <"<<endl;
			
			if((ui+uj) != (i+j))
				cout<<"op error +"<<" "<<i<<" "<<j<<endl;
	
			if((i+uj) != (i+j))
				cout<<"op error + unsigned long long"<<" "<<i<<" "<<j<<endl;
		
			if((uj+i) != (j+i))
				cout<<"op error + ull"<<i<<" "<<j<<endl;
			
			if((ui*uj) != (i*j))
				cout<<"op error *"<<" "<<i<<" "<<j<<endl;
	
			if((i*uj) != (i*j))
				cout<<"op error * unsigned long long"<<" "<<i<<" "<<j<<endl;
		
			if((uj*i) != (j*i))
				cout<<"op error * ull "<<i<<" "<<j<<endl;
				
			if((ui-j) != (i-j)){
				cout<<"op error - ull "<<i<<" "<<j<<endl;
				cout<<uj;}
			if((ui-uj) != (i-j)){
				cout<<"op error - "<<i<<" "<<j<<endl;
				cout<<uj<<ui;}
		}
	}
}
