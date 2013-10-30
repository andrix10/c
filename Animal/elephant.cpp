#include "elephant.h"

Elephant::Elephant ( )
:Mammal()
{

}
Elephant::Elephant ( const char* name )
:Mammal(name)
{

}

Elephant::Elephant ( const char* n, const GenderType& gt,
               double fc, double lf, double t, double w)
:Mammal(n,gt,fc,lf,Herbivore,Hay,)
{
	weight = (w<0)?0:w;
}

Elephant::Elephant( const Elephant& e)
:Mammal(e)
{
	weight = e.weight
}

Elephant::~Elephant ( ) { }

Elephant& Elephant::operator= ( const Elephant& e)
{
  Mammal::operator=(e);
  weight = e.weight;
  return *this;
}

double Elephant::get_weight()const
{
	return weight;
}
void Elephant::set_weight(double w)
{
	weight = w;
}
bool Elephant::weight_range()const
{
	return (weight>=12000) && (weight<=15000);
}
bool Elephant::temp_range() const
{
	return get_temperture()>=97 && get_temperature <= 98;
}

void Elephant::Display()const
{
  Bird::Display();
  cout << "Weight: "<<weight<<endl;;
}

void Elephant::Feed() const
{
	cout<<"Get a bale of hay"<<endl
		<<"Open the bale and break it up in the feed bin"<<endl
		<<"Repeat until bin is full";
}

void Elephant::CageMaintenance()const
{
  cout << "Put the elephant into the inclosed pen" << endl
       << "Get a really big shovel" << endl
       << "Shovel it up" << endl
       << "" << endl;
}

