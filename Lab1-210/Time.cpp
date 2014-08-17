
// Lab 1b
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

#include "Time.h"

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
double Time::timeInHours()
{
  double time;
  time = hours + minutes / 60 + seconds / (3600);
  return time;
}
//calculates the time in minutes
double Time::timeInMinutes()
{
  double time;
  time = hours * 60 + minutes + seconds / 60;
  return time;
}
//calculates the time in seconds
double Time::timeInSeconds()
{
  double time;
  time = hours * 60 * 60 + minutes * 60 + seconds;
  return time;
}