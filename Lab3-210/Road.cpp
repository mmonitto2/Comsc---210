// Lab 3a
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//Road.cpp, by Michael Monitto (0985765)
#include "Road.h"
//setter to set the Length in miles
Road::Road(int l, int w)
{
  length = l;
  width = w;
}
void Road::setLength(int miles)
{
  length = miles;
}
// setter to set the width in feet
void Road::setWidth(int feet)
{
  width = feet;
}
// getter returns the length
int Road::getLength() const
{
  return length;
}
// getter returns the width
int Road::getWidth() const
{
  return width;
}
// funtion to calculate the asphalt
int Road::asphalt(int thickness) const
{
  int cubicFeet; 
  const int feet_per_mile = 5280; // feet in a mile
  const double feet_in_inches = 0.08333; // feet in an inch 
	
  // converts everything to feet then multiplies together to get cubic feet
  cubicFeet = (thickness * feet_in_inches)  * (length * feet_per_mile) * width;

  return cubicFeet;
}