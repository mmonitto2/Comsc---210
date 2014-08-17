// Lab 3b
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

#include "Time.h"
Time::Time()// default constructor
{
  hours = 0;
  minutes = 0;
  seconds = 0;
}
Time::Time(double h, double m, double s)//constructor for setting time
{
  hours = h;
  minutes = m;
  seconds = s;
}
//sets the Hours
void Time::setHours(double hr)
{
  hours = hr;
}
//sets the Minutes
void Time::setMinutes(double min)
{
  minutes = min;
}
//sets the Seconds
void Time::setSeconds(double sec)
{
  seconds = sec;
}
//calculates the time in hours
double Time::timeInHours() const
{
  double time;
  time = hours + minutes / 60 + seconds / (3600);
  return time;
}
//calculates the time in minutes
double Time::timeInMinutes() const
{
  double time;
  time = hours * 60 + minutes + seconds / 60;
  return time;
}
//calculates the time in seconds
double Time::timeInSeconds() const
{
  double time;
  time = hours * 60 * 60 + minutes * 60 + seconds;
  return time;
}