#include <iostream>
#include "animal.h"
using namespace std;

#ifndef MAMMAL_H_DEF
#define MAMMAL_H_DEF

class Mammal : public  Animal
{
	double temp;

public:
    Mammal ( );
    Mammal ( const char* );
    Mammal ( const char* n, const GenderType& gt,
             double fc, double lf, const DietType& dt,
             const FeedType& ft, double);
    Mammal ( const Mammal& );
    
    ~Mammal ( );

    Mammal& operator= ( const Mammal& );

    double get_temp() const;
    void set_temp(double tp);
    virtual bool get_range() const = 0;

    void Display() const;
	/*
    void CageMaintenance() 
    { 
  	    cout 
	*/
};

#endif

