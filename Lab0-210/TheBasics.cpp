// Lab 0c
// Programmer: Michael Monitto
// Editor(s) used: Microsoft Visual C++ 2010 Express
// Compiler(s) used: Visual C++ 2010 Express

#include <iostream>
using namespace std;

// additional #includes
#include <string>
#include <cstdlib>
#include <iomanip>

// function prototypes
double celsius(double, double);

int main()
{
  //print my name and this assignment's title
  cout << "Lab 0c\n";
  cout << "Programmer: Michael Monitto" << endl;
  
  //declare variables
  int age;			
  double ftemp,ctemp = 0;
  char buf[100];	//creates a buffer
  string name,location;
  
  //user input for information
  cout << "Enter your age: ";
  cin >> buf; age = atoi(buf);	     //used to limit only int input
  cout << "Enter your name: ";
  cin.ignore();
  getline(cin,name);			
  cout << "Enter the temperature outside right now (degrees F): ";
  cin >> buf; ftemp = atof(buf);	//used to limit only double input
  cout << "What city are you in right now? ";
  cin.ignore();
  getline(cin,location);
  cout << endl;
  
  //function call to covert ferinheight to celsius
  ctemp = celsius(ftemp, ctemp);
  
  //displays the information the user input
  cout << name << " is " << age << " years old now, and will be " << age + 1 << " a year from now." << endl;
  cout << "It's " << ftemp << " degress F in " << location; 
  cout.setf(ios::fixed|ios::showpoint);  //display only one number after decimal 
  cout << setprecision(1) << " -- that's " << ctemp << " degrees C." << endl;
  
  //holds program 
  cout << "Press ENTER to continue.." << endl;
  cin.get();							
}// end main

// function used to calculate the degrees celsius
double celsius(double ftemp, double ctemp)
{
	ctemp = (ftemp - 32.0)*5.0/9.0;
	return ctemp;
}