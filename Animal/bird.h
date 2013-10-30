#include <iostream>
#include "animal.h"
using namespace std;

#ifndef BIRD_H_DEF
#define BIRD_H_DEF

class Bird : public  Animal
{

  bool can_fly;

public:
  Bird ( );
  Bird ( const char* );
  Bird ( const char* n, const GenderType& gt,
         double fc, double lf, const DietType& dt,
         const FeedType& ft, bool);
  Bird ( const Bird& );

  ~Bird ( );

  Bird& operator= ( const Bird& );

  bool CanFly ( ) const;
  void CanFly ( bool );
  void Display()const;

  void CageMaintenance() const 
  { 
  	cout << "BIRD"; 
  }
};

#endif
