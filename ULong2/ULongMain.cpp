#include <iostream>
#include "ULong.h"
using namespace std;

int main()
{

	for(unsigned long long i=0; i<100;i++)
	{
		for(unsigned long long j=0;i<100;i++) 
		{
		ULong ui(i);
		ULong uj(j);
		if((ui==uj) != (i==j))
			cout<<"op error =="<<endl;
	
		if((i==uj) != (i==j))
			cout<<"op error == unsigned long long"<<endl;
		
		if((ui==uj) != (ui==j))
			cout<<"op error == ull"<<endl;
	
		if((ui!=uj) != (i!=j))
			cout<<"op error !="<<endl;
		
		if((i==uj) != (i==j))
			cout<<"op error == ull"<<endl;
	
		if((ui>uj) != (i>j))
			cout<<"op error >"<<endl;
		
		if((i>uj) != (i>j))
			cout<<"op error > ull"<<endl;
		
		if((i<uj) != (i<j))
			cout<<"op error < ull"<<endl;
	
		if((ui<uj) != (i<j))
			cout<<"op error <"<<endl;
		}
	}
}
