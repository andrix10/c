//  ============================================================
//              Animal Class Interface
//  ============================================================
//
//      Copyright (C) 2013
//
//      Professor David E. Fox
//      Computer and Information Science
//      American River College
//      Sacramento, CA  95841
//
//      Permission is granted to use at your own risk and
//      distribute this software in source and binary forms
//      provided the above copyright notice and this paragraph
//      are preserved on all copies.  This software is provided
//      "as is" with no express or implied warranty.
//
//  ============================================================


#ifndef _ANIMAL_H_
#define _ANIMAL_H_

#include <iostream>
#include <fstream>
using namespace std;

//Dates are stored as a double using the same system as
//MS Excel. The whole part of the number is the number
//of days since the begining of the 20th century, with
//the number one representing Jan. 1, 1900. Decimal
//parts represent the time of the day.
//For example: the number: 41600.4
//represents the date and time: Nov 22, 2013 09:36
//Time periods are represented as a double with the whole
//part represnting a number of days and the decimal
//the number of hours and minutes. Times are given in
//24-hour-clock format, i.e., no am/pm
//There is round-off - get over it.


enum DietType {DietTypeUnknown, Carnivore, Herbivore, Omnivore};
enum FeedType {FeedTypeUnknown, Hay, LiveMice, RawMeat,
               RawFish, GrubsNGrass};
enum GenderType {GenderUnknown, Female, Male};

class Animal
{
   char*			_name;
   GenderType		_gender;
   double		    _feeding_cycle; //FC
   double			_last_feeding;  //LF
   DietType			_diet;
   FeedType			_feed;

public:
   //Post: Animal _gender == GenderUnknown
   //		  _diet == DietTypeUnknown
   //             _feed == FeedTypeUnknown
   Animal ( );
   Animal ( const char*, const GenderType&, double FC,
            double LF, const DietType&, const FeedType&);
   Animal ( const char* name );
   Animal ( const Animal& );

   virtual ~Animal ( );

   Animal& operator= ( const Animal& );

   const char* Name ( void ) const;
   void Name ( const char* );

   GenderType Gender( void ) const;
   void Gender ( const GenderType& g );

   double FeedingCycle( void ) const;
   void FeedingCycle ( double FC );

   double LastFeeding( void ) const;
   void LastFeeding ( double LF );

   DietType TypeOfDiet( void ) const;
   void TypeOfDiet ( const DietType& dt );

   FeedType TypeOfFeed( void ) const;
   void TypeOfFeed ( const FeedType& ft );

   void NextFeeding()const;

   //Post: Gives instructions to feed the animal
   virtual void Feed ( void )const;

   //Post: Gives instructions to maintain the animal's cage
   virtual void CageMaintenance ( void )const = 0;

   virtual void Display()const;

};
#endif
