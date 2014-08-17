// Lab 5b
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// DvcSchedule5b by Michael Monitto(0985765)

#include <fstream>
#include <iostream>
#include <string>
#include <ctime>
using namespace std;

//extra includes
#include <cstring>
#include "Array.h"

//Creates an Array of structs
struct SubjectCode
{
  string name;
  int count;
};

int main()
{
   // identifying output statements
  cout << "Programmer: Michael Monitto\n";
  cout << "Description: This program demonstrates the array class.\n";
  cout << "it parses a large DVC text file sorts and displays class count.\n";
  cout << "It also sorts through and counts the doubles.\n";
  cout << "Displays a runtime at the end." << endl;
  cout << endl;

  // for parsing the inputfile
  Array<SubjectCode> x(1000);  //The array

  //initializes variables
  char* token;
  char buf[1000];
  string a; // stores the term and course
  int i = 0;
  int doubles = 0;
  int size = 0; //counters and sizer
  const char* const tab = "\t";

  //hold for user input
  cout << "press ENTER to continue..." << endl;
  cin.get();
  cout << "processing..." << endl;

  //open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if(!fin.good()) throw "I/O error";
  clock_t startTime = clock();  //starts the clock

  //read the input file
  while(fin.good())
  {
    string line;
    getline(fin,line);
    strcpy(buf,line.c_str());
    if(buf[0]==0)continue;
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    //searches through parsed term and section as one large string
    if(a.find('|' + term + section + '|') != string::npos)
    {
      doubles ++; //counts the doubles
      continue; //skips the duplicates
    }
      a = '|' + term + section + '|' + a;

    //searches through array
    for(i = 0; i<size; i++)
    {
      if(x[i].name == subjectCode)
        break;
    }
    //if no match
    if(size == i)
    {
      x[i].name = subjectCode;
      x[i].count = 1;
      size++;
    }
    //else match
	else
       x[i].count++;
  }
  double elapsedSeconds = (double)(clock()-startTime) / CLOCKS_PER_SEC; //ends clock
  fin.close(); //closes file

  SubjectCode temp; //used to sort

  //standard bubble sort to sort the array of structs
  for(i = 0; i<size - 1;i++)
  {
    for(int j = i + 1; j < size;j++)
    {
      if(x[i].name > x[j].name)
      {
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;
      }
    }
  }
  //displays values
  for(i = 0; i<size;i++)
  {
    cout << x[i].name << " - ";
    cout << x[i].count << endl;
  }
  cout << "There were " << doubles << " duplicate classes" << endl;
  cout << "The program took: " << elapsedSeconds << " seconds to process the file" << endl;
  cout << "Press Enter to continue..." << endl;
  cin.get();
}
