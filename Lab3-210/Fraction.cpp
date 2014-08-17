
// Lab 3c
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

#include "Fraction.h"
//overloaded operator + that adds two fractions together
Fraction operator+(const Fraction & a,const Fraction & b)
{
  Fraction result;
  result.numer = a.numer*b.denom + a.denom*b.numer;
  result.denom = a.denom * b.denom;
  return result;
}
//overloaded operator * that mulitplies two fractions together
Fraction operator*(const Fraction & a, const Fraction & b)
{
  Fraction result;
  result.numer = a.numer * b.numer;
  result.denom = a.denom * b.denom;
  return result;
}
//overloaded operator * that adds a fraction on the right and and int on the left
Fraction operator*(const Fraction & a, int n)
{
  Fraction result;
  result.numer = a.numer * n;
  result.denom = a.denom;
  return result;
}
//overloaded operator * that adds a int on the right and a fraction on the left
Fraction operator*(int n, const Fraction & a)
{
  Fraction result;
  result.numer = a.numer * n;
  result.denom = a.denom;
  return result;
}
//overloaded operator the tells if fraction on the left is greater than fraction on the right
bool operator>(const Fraction & a,const Fraction &b)
{
  if((double)a.numer/a.denom > (double)b.numer/b.denom)return true; //divides the numerator by the denominator and converts it to double
  if((double)a.numer/a.denom <= (double)b.numer/b.denom)return false; //divides the numerator by the denominator and converts it to double
  return false; //otherwise returns false
}
