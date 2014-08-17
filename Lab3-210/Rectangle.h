

// Lab 3c
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
  Rectangle() //Default constructor
  {}
  Rectangle(const DataType& len, const DataType& wid); //constructor
  
  void setWidth(const DataType w) //sets the Width of the rectangle
    {width = w;}
  void setLength(const DataType l) //sets the length of the rectangle
    {length = l;}

//***If include Fraction.cpp contains the overloaded operators for DataType***
  bool lengthLargerWidth() const; // used to test if the length is larger than the width

  DataType parimeter() const //calculates the perimeter 
  { 
    return (2*length + 2*width);
  }
  DataType area() const //calculates the area
  {
    return (width * length);
  }
};
template <class DataType> //template class "DataType"
Rectangle<DataType>::Rectangle(const DataType& len, const DataType& wid)
{
  width = wid;
  length = len;
}

template <class DataType>
bool Rectangle<DataType>::lengthLargerWidth() const
{
  if (length>width)
    return true;
  else 
    return false;
}
#endif


