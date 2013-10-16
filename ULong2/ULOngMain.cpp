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
	if(argc ==  4)
	{
		ULong lhs(argv[1]);
		ULong rhs(argv[3]);
		switch (argv[2][0])
		{
		case '+':
			cout<<lhs+rhs;
			cout<<"\n";
			break;
		case '-':
			cout<<lhs-rhs;
			cout<<"\n";
			break; //glitchy, * is wildcard for windows and linux
		case 'x':
			cout<<lhs*rhs;
			cout<<"\n";
			break;
		case '/':
			cout<<lhs/rhs;
			cout<<"\n";
			break;
		case 'g':
			if(lhs>rhs) cout<<"greater\n";
			else cout<<"less\n";
			break;
		case 'l':
			if(lhs<rhs) cout<<"less\n";
		    else cout<<"greater\n";
			break;
		case 'e':
			if(lhs==rhs) cout<<"equals\n";
			else cout<<"doesn't equal\n";
			break;
		case 'd':
			if(lhs!=rhs) cout<<"doesn't equal\n";
			else cout<<"equals\n";
			break;
		case 'm':
			cout << lhs%rhs<<"\n";
			break;
		case 'p':
			//lhs++;
			//rhs++;
			cout<< ++lhs<<" "<<++rhs;
			break;
		case 's':
	//		lhs--;
//			rhs--;
			cout<<--lhs<<" "<<--rhs;
			break;
		default:
			cout << "Unknown opporator!\n";
		}
	}
	else
	{
		cout << "ERROR: wrong format.\n";
		cout << "[number] [operator] [number]\n";
		cout << "allowed operators:\n";
		cout << "[ + ] for plus\n";
		cout << "[ - ] for minus\n";
		cout << "[ x  X ] for multiply\n";
		cout << "[ / ] for divide\n";
	}
	return 0;
}

