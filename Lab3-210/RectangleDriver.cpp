
// Lab 3c
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// RectangleDriver.cpp by Michael Monitto (0985765)
#include <iostream>
using namespace std;

//extra includes
#include "Fraction.h"
#include "Fraction.h"  //test ifndef
#include "Rectangle.h"
#include "Rectangle.h" //test ifndef

//prototypes
void output(const Fraction &);
int main()
{

  //Header for all assignments
  cout << "Lab 3c" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout <<"Linked with lab2a Fractions.cpp the program calculates the area"<<endl;
  cout << "and perimeter of a rectangle" <<endl;
  cout <<"includes Fractions DataType to calculate" << endl;
  cout << "length and the width if it contained any fractions." << endl;
  cout << "added constructor and const specifications." << endl;
  cout << "This is a test Driver program" << endl;
  cout << endl;

  //test with int datatype
  {
    cout << "***Testing with int datatype***\n" << endl;

    //declare int datatypes
    int a = 6;
    int b = 8;
    const Rectangle<int> rect(a,b);

    //set values in double does not compile because rect is declared const
    //rect.setLength(a);
    //rect.setWidth(b);

    //display to user
    cout << "The length is = " << a << endl;
    cout << "The width is = " << b << endl;
    cout << "Area, expect 48, actual area is = " << rect.area() << endl;
    cout << "Perimeter, expect 28, actual perimeter is = " << rect.parimeter() << endl;

    if(rect.lengthLargerWidth() == true)
    {
      cout <<"The length is larger than the width" << endl;
    }
    else
      cout <<"The length is not larger than the width" << endl;

    //const object copy testing with assignment UPON declaration
    {
      cout << "***Const object copy testing with assignment UPON declaration***\n" << endl;
      //create copy objects
      const Rectangle<int> copy_a = rect;

      //display to user
      cout << "Area, expect 48, actual area is = " << rect.area() << endl;
    }// end object copy test

    //input to continue
    cout << endl;
    cout << "Press ENTER to continue.." << endl;
    cin.get();

    //object copy testing with assignment AFTER declaration
    {
      cout << "***Object copy testing with assignment AFTER declaration***\n" << endl;
      //create copy objects
      Rectangle<int> copy_a; copy_a = rect;
      //display to user
      cout << "Area, expect 48, actual area is = " << rect.area() << endl;
    }//end AFTER test

  }// end int test

  //input to continue
  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();

  //test with double datatype
  {
    cout << "***Testing with double datatype***\n" << endl;
    //declare double datatypes
    double a = 5.05;
    double b = 2.08;
    const Rectangle<double>rect(a,b);

    //set values in double does not compile because rect is declared const
    //rect.setLength(a);
    //rect.setWidth(b);

    //display to user
    cout << "The length is = " << a << endl;
    cout << "The width is = " << b << endl;
    cout << "Area, expect 10.50, actual area is = " << rect.area() << endl;
    cout << "Perimeter, expect 14.26, actual perimeter is = " << rect.parimeter() << endl;

    if(rect.lengthLargerWidth() == true)
    {
      cout <<"The length is larger than the width" << endl;
    }
    else
      cout <<"The length is not larger than the width" << endl;
  }// end double testing

  //input to continue
  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();

  //test with Fraction datatype
  cout << "***Testing with Fraction datatype***\n" << endl;
  Fraction a = {1,2}; //creates initial fraction values: numer/denom
  Fraction b = {3,4}; //creates initial fraction values: numer/denom
  const Rectangle<Fraction>rect(a,b);

  //set values in double does not compile because rect is declared const
  //rect.setLength(a);
  //rect.setWidth(b);

  //display to user
  cout << "Test for length: want 1/2 actual length = ";
  output(a);
  cout << "Test for width: want 3/4 actual width = ";
  output(b);

  //Declared the values as variables
  //Not sure if that is what is needed but it does compile
  //on two different compilers
  Fraction area = rect.area();
  Fraction perim = rect.parimeter();

  //calculates area and perimeter and displays it in fraction notation
  cout << "Area, expect 3/8, actual area is = ";
  output(area);
  cout << "Perimeter, expect 20/8, actual perimeter is = ";
  output(perim);

  if(rect.lengthLargerWidth() == true)
  {
    cout <<"The length is larger than the width" << endl;
  }
  else
    cout <<"The length is not larger than the width" << endl;

  //input to continue
  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();

  //const object copy testing with assignment UPON declaration
  {
    cout << "***Const object copy testing with assignment UPON declaration***\n" << endl;
    //create copy objects
    const Fraction copy_a = a;

    //display to user
    cout << "Test for length: want 1/2 actual length = ";
    output(copy_a);
  }// end object copy test

  //input to continue
  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();

  //object copy testing with assignment AFTER declaration
  {
    cout << "***Object copy testing with assignment AFTER declaration***\n" << endl;
    //create copy objects
    Fraction copy_a; copy_a = a;

    //display to user
    cout << "Test for length: want 1/2 actual length = ";
    output(copy_a);

  }//end AFTER test

  cout << endl;
  cout << "Press ENTER to continue.." << endl;
  cin.get();
}//end main


//function used to output in fraction notation
void output(const Fraction &n)
{
  cout << n.numer << '/' << n.denom << endl;
  return;
}