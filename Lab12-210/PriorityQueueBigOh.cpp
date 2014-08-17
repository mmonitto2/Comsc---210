// Lab 12b
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// PriorityQueueBigOh.cpp by Michael Monitto (0985765)

#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include "PriorityQueue.h"

int main()
{

  cout << "Lab 12b" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout << "Testing the PriorityQueue.h BigOh" << endl;
  cout << endl;

  /*****************************
  TESTING OF THE ENQUEUE FUCTION
  ******************************/

  // problem setup goes here
  PriorityQueue<int> q(2);
  // programmer customizations go here
  int n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 500; // for timing fast operations, use REPS up to 100th of the starting n
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    for(int i = n; i > 1; --i)
      q.enqueue(i);
    // assert that n is the size of the data structure
    assert(q.getSize() == n - 1);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for(int reps = 0; reps < REPS; reps++)
    {
      for(int i = n+1; i < n+reps; i++)
        q.enqueue(i);
    }
    clock_t endTime = clock();
    // validation block -- assure that process worked
    int size = q.getSize();
    for(int i = size; i > 0;--i)
    {
      q.dequeue();
      assert(q[0] >= q[1] || q[0] >= q[2]);
    }
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }

  cout << "press Enter to continue.." << endl;
  cin.get();

  /*****************************
  TESTING OF THE DEQUEUE FUCTION
  ******************************/

  n = 5000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int REPS2 = 5000000; // for timing fast operations, use REPS up to 100th of the starting n
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    for(int i = n; i > 1; --i)
      q.enqueue(i);
    int size = q.getSize();
    // assert that n is the size of the data structure
    assert(size == n - 1);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for(int reps = 0; reps < REPS2; reps++)
    {
      for(int i = 0; i < size; i++,size--)
        q.dequeue();
    }
    clock_t endTime = clock();
    // validation block -- assure that process worked
    assert(q[0] >= q[1] || q[0] >= q[2]);
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
    }
}















