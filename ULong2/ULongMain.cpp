#include <iostream>
#include "ULong.h"

using namespace std;

int main ()
{
	unsigned long long MAX =100;
	ULong ULMAX(MAX);

	for ( unsigned long long i=MAX; i<= 2*MAX; i++ )
	{
		ULong uli = (i == 0)? ULong("0") : ULong(i);
		if ( i%10 == 0 )
			cout << i<<endl;
		for ( unsigned long long j=0; j<=3*MAX; j++ )
		{
			ULong ulj= (j == 0)? ULong("0") : ULong(j);
			//************SUM************************
			{
				long long sum = j + i;
				ulj += uli;
				ULong ulsum = (sum == 0)? ULong("0") : ULong(sum);
				if ( ulj != ulsum )
				cout << "Error add" << endl;
			}//end add
			//********************SUBTRACT******************
			{
				unsigned long long diff = (j >= i)? j-i : 0;
				ulj = (j == 0)? ULong("0") : ULong(j);
				ulj -= uli;
				
				ULong uldiff = (diff == 0)? ULong("0") : ULong(diff);
				if ( ulj != uldiff )
				{
					
					cout<< ulj << " "<<uli<<endl;
					cout << "Error sub" << endl;
					cout << "j: " << j << " i: " << i << endl
						<< "ulj: " << ulj << " uli: " << uli << endl
						<< "uldiff: " << uldiff << " diff: "
						<< diff << endl<<endl;
					cin.get();
				}
			}//end sub
			//***********************MULT***********************
			{
				unsigned long long prod = (j==0 || i==0)? 0 : j*i;
				ulj = (j == 0)? ULong("0") : ULong(j);
				ulj *= uli;
				ULong ulprod = (prod == 0)? ULong("0") : ULong(prod);
				if ( ulj != ulprod )
				{
					cout << "Error mult" << endl;
					cout << "j: " << j << " i: " << i << endl
						<< "ulj: " << ulj << " uli: " << uli << endl
						<< "ulprod: " << ulprod << " prod: "
						<< prod << endl<<endl;
					cin.get();
				}
			}//end mult

			//***********************DIV***********************
			if ( i != 0 )
			{
				unsigned long long div = (j==0 || i==0)? 0 : j/i;
				ulj = (j == 0)? ULong("0") : ULong(j);
				ulj /= uli;
				ULong uldiv = (div == 0)? ULong("0") : ULong(div);
				if ( ulj != uldiv )
				{
					cout << "Error div" << endl;
					cout << "j: " << j << " i: " << i << endl
						<< "ulj: " << ulj << " uli: " << uli << endl
						<< "uldiv: " << uldiv << " div: "
						<< div << endl<<endl;
					cin.get();
				}
			}//end div

			//*********************MOD**************************
			if ( i != 0 )
			{
				unsigned long long mod = (j==0 || i==0)? 0 : j%i;
				ulj = (j == 0)? ULong("0") : ULong(j);
				ulj %= uli;
				ULong ulmod = (mod == 0)? ULong("0") : ULong(mod);
				if ( ulj != ulmod )
				{
				cout << "Error mod" << endl;
				cout << "j: " << j << " i: " << i << endl
					<< "ulj: " << ulj << " uli: " << uli << endl
					<< "ulmod: " << ulmod << " mod: "
					<< mod << endl<<endl;
				cin.get();
				}
			}// end mod
		}//end j
	}// end i

	cout << "done";
	cin.get();
	return 0;
}

