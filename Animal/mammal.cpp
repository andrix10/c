#include <iostream>
#include "animal.h"
#include "mammal.h"

Mammal::Mammal ( )
:Animal()
{
	 
}

Mammal::Mammal ( const char* name )
:Animal(name)
{
  
}

Mammal::Mammal ( const char* n, const GenderType& gt,
             double fc, double lf, const DietType& dt,
             const FeedType& ft, double tp)
:Animal(n,gt,fc,lf,dt,ft)
{
  temp = tp;
  //range = r;
}

Mammal::Mammal ( const Mammal& m)
:Animal(m)
{
    temp = m.temp;
    //range = b.range;
}

Mammal::~Mammal ( ) { }

Mammal& Mammal::operator= (const Mammal& m)
{
    Animal::operator=(m);
	temp = m.temp;
	//range = b.range;
    return *this;
}

void Mammal::set_temp(double tp)
{
	temp = tp;
}

double Mammal::get_temp() const
{
	return temp;
}

/*bool Bird::CanFly ( ) const
{
  return can_fly;
}
void Bird::CanFly ( bool cf )
{
  can_fly = cf;
}

*/
void Mammal::Display() const
{
  Animal::Display();
  cout<<"Temperature: "<<temp<<endl;
}
