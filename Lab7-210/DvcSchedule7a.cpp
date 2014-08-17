
// Lab 7a
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

//Creates an Array of structs
struct SubjectCode
{
  string name;
  int count;
};
//linked list node
struct Node
{
  SubjectCode data;
  Node* next;
};


int main(){

  // identifying output statements
  cout << "Programmer: Michael Monitto\n";
  cout << "Program: 7a\n";
  cout << "Description: This program demonstrates a linked list.\n";
  cout << "It parses a large DVC text file sorts and displays class count.\n";
  cout << "It also sorts through and counts the doubles.\n";
  cout << "Displays a runtime at the end." << endl;
  cout << endl;

  Node* p; //main pointer for list
  Node* q; //pointer used for sort
  Node* start = 0; //pointer used for the start of the list

  //initializes variables
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int i = 0, size = 0,doubles = 0,counter = 0;
  string a;

  //hold for user input
  cout << "press ENTER to continue..." << endl;
  cin.get();
  cout << "processing ";

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

    //display for user to see processing
    if(counter % 1000 == 0)
    cout << ".";
    counter++;

    //stores each section
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    if(a.find('|' + term + section + '|') != string::npos)
    {
      doubles++; //counts doubles
      continue; //skips doubles
    }
    a = '|' + term + section + '|' + a;

	//searches through array
    for(p = start; p ; p = p->next)
    {
      if(p->data.name == subjectCode)
        break;
    }
    //if found
    if(p != 0)
    {
      p->data.count++;
    }
    //else no match
    else
    {
      Node *p = new Node; //create a new node
      p->data.name = subjectCode;
      p->data.count = 1;
      p->next = start; //front of the list
      start = p;
    }
  }

  double elapsedSeconds = (double)(clock()-startTime)/CLOCKS_PER_SEC; //ends clock
  fin.close(); //closes file

  //standard bubble sort to sort the array of structs
  for(p=start; p; p = p->next)
  {
    for(q = p->next;q;q=q->next)
    {
      if(q->data.name < p->data.name)
      {
        SubjectCode temp = p->data;
        p->data = q->data;
        q->data = temp;
      }
    }
  }

  cout << endl;
  //displays values
  for(p = start; p ; p= p->next)
  {
    cout << p->data.name << " - ";
    cout << p->data.count << endl;
  }
  //deallocate memory
  while(start)
  {
    p = start->next;
    delete start;
    start = p;
  }

  cout << "The program took: " << elapsedSeconds << " seconds to process the file" << endl;
  cout << "The program has: " << doubles << " doubles" << endl;
  cout << "Press Enter to continue..." << endl;
  cin.get();
}
