#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;
#include "LinkedList.h"
#include <algorithm>
#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{
  // problem setup goes here
  srand(time(0));//new seed value to rand
  double r = rand(); //prime sequence
  // programmer customizations go here
  int i;
  int n = 50000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 100000000; // for timing fast operations, use REPS up to 100th of the starting n

  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> a;
    r = (rand()/10.0);
	for(i = 0; i < n; i++)
      a.insert(r);
    // assert that n is the size of the data structure
	assert(a.length() == n);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
	for(int reps = 0; reps < REPS; reps++)
      a[0];
    clock_t endTime = clock();

    // validation block -- assure that process worked
    assert(i == n);
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
    cout << "\npress ENTER to continue.." << endl;
    cin.get();

  n = 50000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)

  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> a;
    r = (rand()/10.0);
	for(i = 0; i < n; i++)
      a.insert(r);
    // assert that n is the size of the data structure
	assert(a.length() == n);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
	for(int reps = 0; reps < REPS; reps++)
      a[100];
    clock_t endTime = clock();

    // validation block -- assure that process worked
    assert(i == n);
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
    cout << "\npress ENTER to continue.." << endl;
    cin.get();

  n = 500; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  bigOh = "O(n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS2 = 100000; // for timing fast operations, use REPS up to 100th of the starting n
  elapsedTimeTicksNorm = 0;
  expectedTimeTicks = 0;

  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> a;
    r = (rand()/10.0);
	for(i = 0; i < n; i++)
      a.insert(r);
    // assert that n is the size of the data structure
	assert(a.length() == n);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for(int reps = 0; reps < REPS2; reps++)
      for (i = 0; i < a.length(); a[i], i++);
    clock_t endTime = clock();

    // validation block -- assure that process worked
    assert(i == n);
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
    cout << "\npress ENTER to continue.." << endl;
    cin.get();

  n = 50000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS3 = 100000000; // for timing fast operations, use REPS up to 100th of the starting n
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    // more problem setup goes here -- the stuff not timed
    LinkedList<double> a;
    r = (rand()/10.0);
	for(i = 0; i < n; i++)
      a.insert(r);
    int length = a.length();
    // assert that n is the size of the data structure
	assert(a.length() == n);
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for(int reps = 0; reps < REPS3; reps++)
      a[length];
    clock_t endTime = clock();

    // validation block -- assure that process worked
    assert(i == n);
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
    cout << "\npress ENTER to continue.." << endl;
    cin.get();
}
