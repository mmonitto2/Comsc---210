// Lab 8a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

#include <iostream>
using namespace std;
//extra includes
#include <cctype>
#include <string>
#include <cstdlib>
#include "Stack.h"
//prototypes
bool InputIsGood(string str);

int main()
{
  cout << "Lab 8a" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout <<"This is a RPN calculator used to perform mathematic operations." <<endl;
  cout <<"It includes the stack stl and performs some of its capabilities." << endl;
  cout <<"New addition uses an implemented stack.h" << endl;
  cout << endl;

  Stack<double>x; //declare stack
  string num;     //string input
  double item;    //passed by value
  cout <<"Input a value followed by ENTER to exit the program press Q" << endl;
  cout << endl;
  cout << "Enter: ";
  do{
      getline(cin,num);

      //if the first input is a digit
      if(isdigit(num[0]))
      {
        x.push(atof(num.c_str()));   // push only double values on the stack
      }
      else if(num[0] == '+'|| num[0] == '-' || num[0] == '/'|| num[0] == '*')
      {
        double a = x.peek(a); x.pop(a);
        double b = x.peek(b); x.pop(b);
	    //switch statment the perform math operations
        switch(num[0])
        {
          case '+': x.push(a + b);
            break;
          case '-': x.push(b - a);
           break;
          case '/': x.push(b / a);
           break;
          case '*': x.push(a * b);
           break;
        }
      }
    cout << "Enter: ";
    //create a copy of the stack to display what is already on the stack
    for (Stack<double> copy = x; !copy.isEmpty(); copy.pop(item))
    {
      copy.peek(item); //gathers the top of the stack stores it in item
      cout << item << " "; //displays top
    }
  }while(InputIsGood(num)==true); //break if input is q
  cout << endl;
  cout << "The program has ended.." << endl;
}
//function to used to terminate the program
bool InputIsGood(string str){
  bool good = true;
  if ((str == "q") || (str == "Q"))good=false;
    return good;
}
