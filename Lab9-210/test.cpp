#include <algorithm>
#include <iostream> // for cout and endl
#include <string> // for string
#include <stdlib.h>
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{
srand(time(NULL));



int n = 5000;


for(int i = 0; i < n; i++)
{
  double* a = new double[n];

  a[n] = rand();
  cout << a[n] << endl;

}
}
