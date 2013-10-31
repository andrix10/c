#include "bird.h"
using namespace std;

Bird::Bird ( )
:Animal()
{
  can_fly = true;
}
Bird::Bird ( const char* name )
:Animal(name)
{
  can_fly = true;
}
Bird::Bird ( const char* n, const GenderType& gt,
             double fc, double lf, const DietType& dt,
             const FeedType& ft, bool cf)
:Animal(n,gt,fc,lf,dt,ft)
{
  can_fly = cf;
}
Bird::Bird ( const Bird& b)
:Animal(b)
{
  can_fly = b.can_fly;
}

Bird::~Bird ( ) { }

Bird& Bird::operator= ( const Bird& b)
{
  Animal::operator=(b);
  can_fly = b.can_fly;
  return *this;
}

bool Bird::CanFly ( ) const
{
  return can_fly;
}
void Bird::CanFly ( bool cf )
{
  can_fly = cf;
}

void Bird::Display()const
{
  Animal::Display();
  cout << "Can Fly: "<<((can_fly)?"Yes":"No") << endl;
}
