#include <iostream>
#include "mammal.h"
using namespace std;


class Eagle : public  Mammal
{
	double weight;

public:
	Elephant ( );
 	Elephant  ( const char* );
 	Elephant  ( const char* n, const GenderType& gt,
         double fc, double lf, double t, double w);
	Elephant  ( const Elephant& );
	~Elephant  ( );

 	Elephant & operator= ( const Elephant& );

  	double get_weight()const;
  	void set_weight(double);
	bool weight_range()const;
	bool temp_range() const;
  	
	void Display()const;
	void Feed()const;
	void CageMaintance()const;
  	//void CageMaintenance()const;

};

