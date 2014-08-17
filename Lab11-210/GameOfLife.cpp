
// Lab 11b
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// GameOfLife.cpp by Michael Monitto (0985765)

#include <iostream>
using namespace std;

#include <cstdlib>

struct cell
{
  int value; // equal to 1, so 0,0 is not a blank
  int row; // any +/0/- value
  int col; // any +/0/- value

  bool operator==(const cell& c) const {return row == c.row && col == c.col;}
  bool operator<(const cell& c) const {return (1000000 * row + col) < (1000000 * c.row + c.col);}
  int hashCode() const {return 31 * row + col;}
};

#include "HashTable.h"
HashTable<cell, 1009> grid; //needs fixing
HashTable<cell, 1009> newGrid; //needs fixing

const int MINROW = -25;
const int MAXROW = 25;
const int MINCOL = -35;
const int MAXCOL = 35;

int neighborCount(int row, int col)
{
  cell temp;
  int count = 0;
  for (temp.row = row - 1; temp.row <= row + 1; temp.row++)
    for (temp.col = col - 1; temp.col <= col + 1; temp.col++)
      if (temp.row != row || temp.col != col)
        if (grid.retrieve(temp))
          ++count;
  return count;
}

void initialize()
{
  cout << "List the coordinates for living cells.\n";
  cout << "Terminate the list with a special pair -1 -1\n";

  cell temp;
  char buf[100];
  while (true)
  {
    cin >> buf; temp.row = atoi(buf);
    cin >> buf; temp.col = atoi(buf);
    if (temp.row == -1 && temp.col == -1) break;
    grid.insert(temp);
  }
  cin.ignore();
}

void print()
{
  cell temp = {1};
  cout << "\nThe current Life configuration is:\n";
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
  {
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      if (grid.retrieve(temp))
        cout << '*';
      else
        cout << ' ';
    cout << endl;
  }
  cout << endl;
}

void update()
{
  cell temp = {1};
  newGrid.clear();
  for (temp.row = MINROW; temp.row <= MAXROW; temp.row++)
    for (temp.col = MINCOL; temp.col <= MAXCOL; temp.col++)
      switch (neighborCount(temp.row, temp.col))
      {
        case 2:
          if (grid.retrieve(temp)) newGrid.insert(temp);
          break;
        case 3:
          newGrid.insert(temp);
          break;
      }

  grid = newGrid;
};

int main()
{
  cout << "Lab 11b" <<endl;
  cout <<"Programmer: Michael Monitto" <<endl;
  cout << "Conways's game of Life using created hashTable.h" << endl;
  cout << endl;


  cout << "Welcome to Conway's game of Life\n";
  cout << "This game uses a grid in which\n";
  cout << "each cell can either be occupied by an organism or not.\n";
  cout << "The occupied cells change from generation to generation\n";
  cout << "according to the number of neighboring cells which are alive.\n";

  initialize();
  print();

  for (int i = 1; grid.getSize(); i++)
  {
    cout << "Generation " << i << ". Press ENTER to continue, X-ENTER to quit...\n";
    if (cin.get() > 31) break;
    update();
    print();
  }
  return 0;
}