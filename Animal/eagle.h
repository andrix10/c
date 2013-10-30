#include <iostream>
#include "bird.h"
using namespace std;


class Eagle : public  Bird
{
  bool endangered;

public:
  Eagle ( );
  Eagle ( const char* );
  Eagle ( const char* n, const GenderType& gt,
         double fc, double lf, bool ed);

  Eagle ( const Eagle& );

  ~Eagle ( );

  Eagle& operator= ( const Eagle& );

  bool Endangered ( ) const;
  void Endangered ( bool );

  void Display()const;
  void CageMaintenance()const;

};

