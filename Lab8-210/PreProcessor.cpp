// Lab 8b
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// PreProcessor.cpp by Michael Monitto (0985765)

#include <iostream>
using namespace std;
//extra includes
#include <stack>
#include <fstream>
#include <string>
#include <cstring>
//function prototypes
string MatchingDelimiter(char ch);
//struct to hold data
struct line
{
  char delim;
  int lineNum;
};
//declared characters
char leftpar = '(';
char leftsquarebrack = '[';
char leftcurlybrack = '{';
char rightpar = ')';
char rightsquarebrack = ']';
char rightcurlybrack = '}';
char star = '*';
char slash = '/';

int main()
{

  cout << "Lab 8b" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout << "Checks for matching delimeters using the stack stl" << endl;
  cout << endl;

  stack<line> theStack;  //create the stack
  line ch,ch2; //objects
  bool balanced = true;
  int lineCounter = 0; //used to count the lines
  //open file
  ifstream fin;
  string fileName;

  //enter filename
  cout << "Enter filename(H,CPP,JAVA,HTML,or JS): ";
  getline(cin,fileName);
  fin.open(fileName.c_str());
  if(!fin.good()) throw "I/O error"; //if no file

  //read data
  while(fin.good())
  {
    string name; //used to traverse through file
    getline(fin,name);
    ++lineCounter;//count the lines
    for(unsigned int i = 0; i < name.length(); i++)
    {
      ch.delim = name.at(i); //stores chars in struct

      if( i < name.length()-1) //used to check last value
      {
        if(name[i+1] == star && theStack.empty())
        {
          ch.lineNum = lineCounter;  //store line #
          theStack.push(ch);  //pushed char line on stack
          ch2 = theStack.top(); //inialize from top of the stack
        }
      }
      else if (i > 0) //used to check first value in string
      {
        if(name[i-1] == star && ch2.delim == slash)
        {
          theStack.pop();
          continue;
        }
      }
	  //store left delimeter
      if( name[i] == leftcurlybrack || name[i] == leftpar || name[i] == leftsquarebrack)
      {
        ch.lineNum = lineCounter; //store line #
        theStack.push(ch);  //push onto stack
      }
	  //check right delimeter
      if(name[i] == rightcurlybrack || name[i] == rightpar || name[i] == rightsquarebrack)
      {
        if(theStack.empty())  //if no left delimeter display error
        {
          if(name[i] == rightcurlybrack)
          {
            cout << "Right curly bracket found on line " << lineCounter << " in "<< fileName <<  endl;
            cout << "But no " << MatchingDelimiter(name[i]) << " found " << endl;
          }
          if(name[i] == rightsquarebrack)
          {
            cout << "Right square bracket found on line " << lineCounter << " in "<< fileName <<  endl;
            cout << "But no " << MatchingDelimiter(name[i]) << " found " << endl;
          }
          if(name[i] == rightpar)
          {
            cout << "Right parenthesis found on line " << lineCounter << " in "<< fileName <<  endl;
            cout << "But no " << MatchingDelimiter(name[i]) << " found " << endl;
          }
          balanced = false;
          break;
        }
        else
          ch2 = theStack.top();

        if((ch.delim == rightcurlybrack && ch2.delim == leftcurlybrack) || (ch.delim == rightpar && ch2.delim == leftpar) || (ch.delim == rightsquarebrack && ch2.delim == leftsquarebrack))
        {
          theStack.pop();
          continue;
        }
      }
    }//end for
    if(!balanced) //used to check only first error
      break;
  }//end while
  fin.close();  //closes the file

  //if all match
  if(balanced && theStack.empty())
    cout << "No mismatches found by my preprocessor in " << fileName << endl;
  else if(!theStack.empty())
  {
    ch = theStack.top(); //store stack top
    if(ch.delim == leftcurlybrack)
    {
      cout << "Left curly bracket found on line " << ch.lineNum << " in "<< fileName <<  endl;
      cout << "But no " << MatchingDelimiter(ch.delim) << " found " << endl;
    }
    else if(ch.delim == leftsquarebrack)
    {
      cout << "Left square bracket found on line " << ch.lineNum << " in "<< fileName <<  endl;
      cout << "But no " << MatchingDelimiter(ch.delim) << " found " << endl;
    }
    else if(ch.delim == leftpar)
    {
      cout << "Left parenthesis found on line " << ch.lineNum << " in "<< fileName <<  endl;
      cout << "But no " << MatchingDelimiter(ch.delim) << " found " << endl;
    }
    else if(ch.delim == slash)
    {
      cout << "Opening comment found on line " << ch.lineNum << " in "<< fileName <<  endl;
      cout << "But no " << MatchingDelimiter(ch.delim) << " found " << endl;
    }
    else
    {
      cout << "Opening comment found on line " << ch.lineNum << " in "<< fileName <<  endl;
      cout << "But no " << MatchingDelimiter(ch.delim) << " found " << endl;
    }
  }
  theStack.empty();
  cout << "press ENTER to continue.." << endl;
  cin.get();
}

//fuction used to display matching delimeter if oposite one it displayed
string MatchingDelimiter(char ch)
{
  if( ch == leftcurlybrack)
    return "right curly bracket";
  else if (ch == leftsquarebrack)
    return "right square bracket";
  else if (ch == leftpar)
    return "right parenthesis";
  else if( ch == rightcurlybrack)
    return "left curly bracket";
  else if( ch == rightpar)
    return "left parenthesis";
  else if (ch == rightsquarebrack)
    return "left square bracket";
  else if( ch == slash)
    return "closing comment block";
  else
    return "opening comment block";
}
