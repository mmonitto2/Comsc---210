// Lab 3b
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//Time.h by Michael Monitto (0985765)
#ifndef Time_h
#define Time_h

//Class Time
class Time
{
private:
  double hours; 
  double minutes; 
  double seconds; 
public:
  Time();//default constructor
  Time(double h, double m, double s); //constructor
  void setHours(double hr); //setter
  void setMinutes(double min); //setter
  void setSeconds(double sec); //setter

  double timeInHours() const; //calculates time in hours
  double timeInMinutes() const; //calculates time in minutes
  double timeInSeconds() const; //calculates time in Seconds
};
//end Class Time

#endif

