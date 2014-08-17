// Lab 2b
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// Rectangle.h by Michael Monitto (0985765)

#ifndef Rectangle_h
#define Rectangle_h
template <class DataType> //template class "DataType"
class Rectangle
{
private:
  DataType length; //private
  DataType width;  //private
public:
  void setWidth(DataType w) //sets the Width of the rectangle
    {width = w;}
  void setLength(DataType l) //sets the length of the rectangle
    {length = l;}

//***If include Fraction.cpp contains the overloaded operators for DataType***
  bool lengthLargerWidth() // used to test if the length is larger than the width
  {
    if (length>width)
      return true;
    else
      return false;
  }
  //also declared these as const
  DataType parimeter() //calculates the perimeter
  {
    return 2*(length + width);
  }
  DataType area() //calculates the area
  {
    return width * length;
  }
};
#endif
