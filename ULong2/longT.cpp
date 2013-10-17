#include <iostream>
#include "ULong.h"

using namespace std;

int main()
{
	unsigned long long l,r;
	cin >> l >> r;
	ULong num(l);
	ULong num2(r);
	cout << num-r << endl;
	cout << l-r<<endl;
	cout << num + r<<endl;
	
}


