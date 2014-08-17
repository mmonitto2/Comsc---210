// Lab 1a
// Programmer: Michael Monitto
// Editor(s) used: Visual C++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//RoadDriver.cpp, by Michael Monitto (0985765)
#include <iostream>
using namespace std;

//Extra includes
#include <cassert>
#include "Road.h"
#include "Road.h" //testing ifndef

int main()
{
  cout << "Programmer: Michael Monitto\n";
  cout << "Description: This program uses getters and setters to obtain" << endl; 
  cout << "the length in miles and width in feet";
  cout << " then determines the amount of asphalt" << endl;
  cout << "to be laid in cubic feet." << endl;
  cout << "Its is demostrated in a driver test program." << endl;
  cout << endl;

  Road road;  
  // hard coded testing values
  road.setLength(1); //1 mile
  road.setWidth(10); //10 feet 

  // used for asserts and getters
  int Length_Mile = road.getLength();
  int Width_Feet = road.getWidth();
  int result_asphalt = road.asphalt(2);

  //assert used for testing the values are true
  assert(Length_Mile == 1);
  assert(Width_Feet == 10);
  assert(result_asphalt == 8799); //make sure value is true

  cout << "Expect 1 mile, " << "actual = " << Length_Mile << " mile"<< endl;
  cout << "Expect 10 feet, " << "actual = " << Width_Feet  << " feet" << endl;
  cout << "For asphalt: 2 * 0.08333 * 1 * 5280 * 10 = 8799 cubic inches" << endl;
  assert(result_asphalt == 8799); //make sure value is true
  cout << "actual= " << result_asphalt << " cubic inches of asphalt" << endl;

  //object copy testing, with assignment UPON declaration
  {
    cout << "\nObject copy testing, with assignment UPON declaration" << endl;
    Road copy = road;

    //declare new copy members
    Length_Mile = copy.getLength();
    Width_Feet  = copy.getWidth();
    result_asphalt = copy.asphalt(2);

    //assert used for testing the values are true
    assert(Length_Mile == 1);
    assert(Width_Feet == 10);
    assert(result_asphalt == 8799); //make sure value is true

    cout << "Expect 1 mile, " << "actual = " << Length_Mile << " mile"<< endl;
    cout << "Expect 10 feet, " << "actual = " << Width_Feet  << " feet" << endl;
    cout << "For asphalt: 2 * 0.08333 * 1 * 5280 * 10 = 8799 cubic inches" << endl;
    cout << "actual= " << result_asphalt << " cubic inches of asphalt" << endl;
  }

  //object copy testing, with assignment AFTER declaration
  {
    cout << "\nObject copy testing, with assignment AFTER declaration" << endl;
    Road copy; copy = road;

    //declare copy members
    Length_Mile = copy.getLength();
    Width_Feet  = copy.getWidth();
    result_asphalt = copy.asphalt(2);

    //assert used for testing the values are true
    assert(Length_Mile == 1);
    assert(Width_Feet == 10);
    assert(result_asphalt == 8799); //make sure value is true

    cout << "Expect 1 mile, " << "actual = " << Length_Mile << " mile"<< endl;
    cout << "Expect 10 feet, " << "actual = " << Width_Feet  << " feet" << endl;
    cout << "For asphalt: 2 * 0.08333 * 1 * 5280 * 10 = 8799 cubic inches" << endl;
    cout << "actual= " << result_asphalt << " cubic inches of asphalt" << endl;
  }
  cout << endl;
  cout <<"Press ENTER to continue..." << endl;
  cin.get();
}