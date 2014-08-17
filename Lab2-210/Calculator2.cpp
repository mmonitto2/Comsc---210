
// Lab 2c
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

#include <iostream>
using namespace std;
//extra includes
#include <cctype>
#include <stack>
#include <string>
#include <cstdlib>
//prototypes
bool InputIsGood(string str);

int main()
{
  cout << "Lab 2c" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout <<"This is a RPN calculator used to perform mathematic operations." <<endl;
  cout <<"It includes the stack stl and performs some of its capabilities." << endl;
  cout << endl;

  stack<double>x; //declare stack
  string num;     //string input
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
	if (x.size() < 2 && !isdigit(num[0])) // if the stack size is less than 2
	{
	  atof(num.c_str());                  // read only double values
	}
    else if(num[0] == '+'|| num[0] == '-' || num[0] == '/'|| num[0] == '*')
    {
      double a = x.top(); x.pop();
      double b = x.top(); x.pop();
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
  for (stack<double> copy = x; !copy.empty(); copy.pop())
    cout << copy.top() << " ";
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



