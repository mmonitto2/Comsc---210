// Lab 5a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//MyArray.cpp by Michael Monitto
#include <iostream>
using namespace std;
//extra includes
#include "Array.h"
#include <cstdlib>
//function prototypes
Array<int> getElements();
float calcAverage(Array<int> avnums);

int main()
{
  //array initial size is 2
  Array<int> arr(2);
  char buf[100];
  int num;

  cout << "Programmer: Michael Monitto" << endl;
  cout << "Description: Application used to show the created Array Class" <<endl;
  cout << "Generally user fills the array, calculates the average, then performs linear" << endl;
  cout << "search." << endl;

  //user inputs values in the array
  arr = getElements();

  int n = arr.getCapacity(); //gets size of the array
  cout << "Displaying the values in the array" <<endl;
  for(int i = 0; i < n; i++)
    cout << arr[i] << " ";

  double average = calcAverage(arr);
  //displays the average
  cout << "\nThe average is: " << average << endl;

  while(true)
  {
    cout << "\nEnter value to find in array index or -1 to exit ";
    cin >>buf; num = atoi(buf);
    if(num < 0) break;
    n = arr.lsearch(num);
    cout << num << " " << "is at index " << n << endl;
  }
  cout << "The program has ended.." << endl;
}
//get the Elements in the array
Array<int> getElements()
{
  Array<int> numbers(2);
  int i = 0;
  char buf[100];
  cout << "Enter a positive integer: ";
  cin >> buf; numbers[i] = atoi(buf);

  while(numbers[i] != -1){
    i++;
    int n = numbers.getCapacity();
    if(i == n)
      numbers.changeCapacity(i*2);
    cout << "Enter a positive integer(enter -1 to stop): ";
    cin >> buf; numbers[i] = atoi(buf);
  }
  numbers.changeCapacity(i);
  return numbers;
}
//calculates the Average
float calcAverage(Array<int> avnums)
{
  int sum = 0;
  int n = avnums.getCapacity();
  for(int i = 0; i < n; i++)
    sum += avnums[i];
  return sum/float(n);
  }
