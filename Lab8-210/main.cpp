// Lab 8a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// StackDriver.cpp by Michael Monitto (0985765)

#include <iostream>
using namespace std;

#include "Stack.h"
#include "Stack.h" //test ifndef

double item;

int main()
{
  cout << "Lab 8a" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout << "Testing of the Implemented Stack.h using Stack" << endl;
  cout << endl;

  //push on the stack
  Stack<double> x;

  //testing push
  cout <<"Pushing 2.0"<<endl;
  item = 2.0;
  x.push(item);
  cout <<"Pushing 1.0"<<endl;
  item = 1.0;
  x.push(item);

  //testing pop
  cout << "Poping 1.0" << endl;
  x.pop(item);
  cout << "Poping 1.0" << endl;
  x.pop(item);

  cout << "Checking if stack is empty" << endl;

  //testing getter to see if stack has been made empty
  if(x.isEmpty())
    cout << "The stack is empty" << endl;
  else
    cout << "The stack is full" << endl;

  //pushing items
  item = 3.0;
  cout << "pushing 3 on stack" << endl;
  x.push(item);

  item = 4.0;
  cout << "pushing 4 on stack" << endl;
  x.push(item);

  item = 5.0;
  cout << "pushing 5 on stack" << endl;
  x.push(item);

  item = 6.0;
  cout << "pushing 6 on stack" << endl;
  x.push(item);

  //make a copy of the stack
  cout << endl;

  for(Stack<double> cpy = x; !cpy.isEmpty(); cpy.pop(item))
  {
    //const object copy testing, with assignment upon declaration
    const Stack<double> cpy2 = cpy;
    if (cpy2.isEmpty())
      break;
	//testing setter to set if peek is displayed
    cpy2.peek(item);
    cout << "Items on the stack: " << item << " " << endl;
  }

  cout <<"Clearing the stack" << endl;

  //testing getter
  x.makeEmpty();

  //test if the stack has been made empty
  if(x.isEmpty())
    cout << "The stack is empty" << endl;
  else
    cout << "The stack is full" << endl;

  cout << "Press ENTER to continue.." << endl;
  cin.get();

}
