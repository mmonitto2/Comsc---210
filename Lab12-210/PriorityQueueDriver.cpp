// Lab 12a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// PriorityQueueDriver.cpp by Michael Monitto (0985765)

#include <iostream>
using namespace std;
#include <ctime> // for clock() and clock_t
#include "PriorityQueue.h"
#include "PriorityQueue.h" //test ifndef

int main()
{
  cout << "Lab 12a" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout << "Driver testing of the PriorityQueue.h fuctions and operators" << endl;
  cout << endl;

  srand(time(0)); //prime random
  int r = rand();  //set random
  int iaArray[20];
  PriorityQueue<int> q(2); //new Queue
  for(int i = 0; i < 20; i++)
  {
    r = (rand()%100); //fill Queue with rand values
    q.enqueue(r);
  }
  int treeSize = q.getSize(); //store size
  assert(q.getSize() > 0); //assert there are values

  //displays the tree
  cout << "Displays the tree and with random values" << endl;

  for(int i = 0; i < treeSize;i++)
    cout << "|" << q[i] << "|";

  cout << endl;
  cout << "\nAfter removing half the values" << endl;

  //dequeue half the values on the tree
  for(int i = 0; i < treeSize/2;i++)
    q.dequeue(); //remove root value

  assert(q.getSize() == treeSize/2);
  //get the size
  treeSize = q.getSize();

  //displays the tree after dequeue
  for(int i = 0; i < treeSize;i++)
    cout << "|" << q[i] << "|";
  cout << endl;
  cout << "\nDisplaying the copy tree" << endl;

  //create the copy for testing
  {
    PriorityQueue<int> copy(2); copy = q;
    for(int i = 0; i < treeSize;i++)
      cout << "|" << copy[i] << "|";
  }
  cout << endl;
  cout << "Press Enter to continue.." << endl;
  cin.get();
}



