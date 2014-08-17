// Lab 1a
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//Road.h by Michael Monitto (0985765)
#ifndef Road_h
#define Road_h

//class Road
class Road
{
private:
  int width;   // private
  int length;  //private
public:
  Road(int l,int w); //constructor
  void setWidth(int feet); //setter
  void setLength(int miles); //setter

  int getWidth() const; //getter
  int getLength() const; //getter
  int asphalt(int thickness) const; // asphalt function
};
// end class Road
#endif

