#include "eagle.h"

Eagle::Eagle ( )
:Bird()
{
  endangered = false;
}
Eagle::Eagle ( const char* name )
:Bird(name)
{
  endangered = false;
}

Eagle::Eagle ( const char* n, const GenderType& gt,
               double fc, double lf, bool ed)
:Bird(n,gt,fc,lf,Carnivore,RawMeat,true)
{
  endangered = ed;
}

Eagle::Eagle ( const Eagle& b)
:Bird(b)
{
  endangered = b.endangered;
}

Eagle::~Eagle ( ) { }

Eagle& Eagle::operator= ( const Eagle& b)
{
  Bird::operator=(b);
  endangered = b.endangered;
  return *this;
}

bool Eagle::Endangered ( ) const
{
  return endangered;
}
void Eagle::Endangered ( bool ed )
{
  endangered = ed;
}

void Eagle::Display()const
{
  Bird::Display();
  cout << "Endangered: "<<((endangered)? "Yes":"No")<<endl;;
}

void Eagle::CageMaintenance()const
{
  cout << "1- Catch the Eagle" << endl
       << "2- Put the Eagle in the back room" << endl
       << "3- Shovel guano out of the cage" << endl
       << "4- Release the Eagle" << endl;
}

