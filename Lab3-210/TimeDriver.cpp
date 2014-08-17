// Lab 3b
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//RoadDriver.cpp, by Michael Monitto (0985765)
#include <iostream>
using namespace std;

//Extra includes
#include <cassert>
#include "Time.h"
#include "Time.h" //testing ifndef

int main()
{
  cout << "Programmer: Michael Monitto\n";
  cout << "Description: This program uses getters and setters to obtain" << endl; 
  cout << "hours minutes and seconds";
  cout << " then determines the full seconds" << endl;
  cout << "minutes and hours." << endl;
  cout << "displays test of the constructor and the const implementations"<<endl;
  cout << "Its is demostrated in a driver test program." << endl;
  cout << endl;

  Time time1;
  //declared variables to function values
  cout << "Testing the default constructor for hours: " << time1.timeInHours() << endl;
  cout << "Testing the default constructor for minutes: " << time1.timeInMinutes() << endl;
  cout << "Testing the default constructor for seconds: " << time1.timeInSeconds() << endl;
  
  cout << endl;
 
  Time time(1,40,30);  //declare object

  //hard coded testing values
  time.setHours(1); //does not compile if type const
  time.setMinutes(40); //does not compile if type const
  time.setSeconds(30); //does not compile if type const

  //declared variables to function values
  double time_Hours = time.timeInHours();
  double time_Minutes = time.timeInMinutes();
  double time_Seconds = time.timeInSeconds();

  //assert used for testing the values are true

  //Needed to compare double numbers due to rounding error
  //Not sure if the is substantial, would like some input
  assert(time_Hours <= 1.675 || time_Hours >= 1.675);
  assert(time_Minutes == 100.5);
  assert(time_Seconds == 6030);

  cout << "Hours = expect 1.675, " << "actual = " << time_Hours << " hours"<< endl;
  cout << "Minutes = expect 100.5, " << "actual = " << time_Minutes  << " minutes" << endl;
  cout << "Seconds =  expect 6030, " << "actual = " << ((int)time_Seconds)  << " seconds" << endl;

  //object copy testing, with assignment UPON declaration
  {
    cout << "\nObject copy testing, with assignment UPON declaration" << endl;
    const Time copy = time;  //declare copy of object

    //declare new copy members
    time_Hours = copy.timeInHours();
    time_Minutes = copy.timeInMinutes();
    time_Seconds = copy.timeInSeconds();
    
    //assert used for testing the values are true
    //Needed to compare double numbers due to rounding error
    //Not sure if the is substantial, if there is another way please let me know
    assert(time_Hours <= 1.675 || time_Hours >= 1.675);
    assert(time_Minutes == 100.5);
    assert(time_Seconds == 6030); //make sure value is true

    //assert used for testing the values are true
    cout << "Hours = expect 1.675, " << "actual = " << time_Hours << " hours"<< endl;
    cout << "Minutes = expect 100.5, " << "actual = " << time_Minutes  << " minutes" << endl;
    cout << "Seconds =  expect 6030, " << "actual = " << ((int)time_Seconds)  << " seconds" << endl;
  }
  
  //object copy testing, with assignment AFTER declaration
  {
    cout << "\nObject copy testing, with assignment AFTER declaration" << endl;
    Time copy;copy = time; //declare copy of copy object

    //declare copy members
    time_Hours = copy.timeInHours();
    time_Minutes = copy.timeInMinutes();
    time_Seconds = copy.timeInSeconds();

    //assert used for testing the values are true
    //Needed to compare double numbers due to rounding error
    //Not sure if the is substantial, if there is another way please let me know
    assert(time_Hours <= 1.675 || time_Hours >= 1.675);
    assert(time_Minutes == 100.5);
    assert(time_Seconds == 6030); //make sure value is true

    //assert used for testing the values are true
    cout << "Hours = expect 1.675, " << "actual = " << time_Hours << " hours"<< endl;
    cout << "Minutes = expect 100.5, " << "actual = " << time_Minutes  << " minutes" << endl;
    cout << "Seconds =  expect 6030, " << "actual = " << ((int)time_Seconds)  << " seconds" << endl;
  }
  cout << endl;
  cout <<"Press ENTER to continue..." << endl;
  cin.get();
}