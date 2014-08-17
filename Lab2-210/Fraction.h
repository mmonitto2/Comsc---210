// Lab 2a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//Fraction.h by Michael Monitto (0985765)
#ifndef Fraction_h
#define Fraction_h

//struct Fraction begins
struct Fraction
{
  //all public
  int numer;
  int denom;
}; 
//end struct

  //Stand alone prototypes
  Fraction operator+(const Fraction &, const Fraction &); //overload + function
  Fraction operator*(const Fraction &, const Fraction &); //overload * function
  Fraction operator*(const Fraction &, const int);  //overload * function right int
  Fraction operator*(const int, const Fraction &);  //overload * function left int
  bool operator>(const Fraction &,const Fraction &);  //overload > function

#endif