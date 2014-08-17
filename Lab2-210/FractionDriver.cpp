// Lab 2a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
#include <iostream>
using namespace std;

//extra #includes
#include "Fraction.h"
#include "Fraction.h" //test ifndef

void output(Fraction &); //prototype

int main()
{
  //declare objects
  Fraction a = {1,2};
  Fraction b = {3,4}; //used as specified in lecture
  Fraction c;

  //declare ints used 
  int num1 = 5 ,num2 = 10;
  
  //Header for all assignments
  cout << "Lab 2a" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout <<"Testing of fractions and overloading operators. Each test says specifically" <<endl;
  cout <<"what they do and the results I am looking for." << endl;
  cout << endl;

  //displays all the test and what is expected vs. the results
  cout << "Test for Fraction A: want 1/2 actual Fraction A = "; 
  output(a);
  cout << "Test for Fraction B: want 3/4 actual Fraction B = ";
  output(b);

  //output(); //display in fraction form
  cout << "\nNumbers used for ints: num1 = " << num1 << ",num2 = " << num2 << endl; 

  cout << "\nTest + operater A + B want 1/2 + 3/4 = 10/8, actual = ";
  c = a+b;    //operation +
  output(c);

  cout << "\nTest * operater A * B want 1/2 * 3/4 = 3/8, actual = ";
  c = a*b;    //operation *
  output(c);

  cout << "\nTest * operater A * num1 want 1/2 * 5 = 5/2, actual = ";
  c = a*num1; //operation *
  output(c);

  cout << "\nTest * operater B * num2 want 3/4 * 10 = 30/4, actual = ";
  c = b*num2; //operation *
  output(c);

  cout << "\nTest * operater num1 * A want 5 * 1/2 = 5/2, actual = ";
  c = num1*a; //operation *
  output(c);

  cout << "\nTest * operater num2 * B want 10 * 3/4 = 30/4, actual = ";
  c = num2*b; //operation *
  output(c);

  cout << "\nTest > operater A > B want 1/2 > 3/4 = False!!, actual = ";

  //compairs if a > b
  if(a>b)     //operation >
  {
    cout << "True!!" << endl;
  }
  else
  {
    cout << "False!!" << endl;
  }
  cout << endl;

  //input to continue
  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();

  //object copy testing with assignment UPON declaration
  {
    cout << "***Object copy testing with assignment UPON declaration***" << endl;
    cout << endl;

    //declare copy objects
    Fraction copy_a = a;
    Fraction copy_b = b; //used as specified in lecture

    //displays all the test and what is expected vs. the results
    cout << "Test for Fraction A: want 1/2 actual Fraction A = "; 
    output(copy_a);
    cout << "Test for Fraction B: want 3/4 actual Fraction B = ";
    output(copy_b);
  }
  //input to continue
  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();

  //object copy testing with assignment UPON declaration
  {
    cout << "***Object copy testing with assignment AFTER declaration***" << endl;
    cout << endl;

    //declare copy objects
    Fraction copy_a; copy_a = a;
    Fraction copy_b; copy_b = b;

    //displays all the test and what is expected vs. the results
    cout << "Test for Fraction A: want 1/2 actual Fraction A = "; 
    output(copy_a);
    cout << "Test for Fraction B: want 3/4 actual Fraction B = ";
    output(copy_b);
  }

  //holds program
  cout << endl;
  cout << "Press ENTER of continue.." << endl;
  cin.get();

}//end main

//function used to output in fraction notation
void output(Fraction &n)
{
  cout << n.numer << '/' << n.denom << endl;
  return;
}
