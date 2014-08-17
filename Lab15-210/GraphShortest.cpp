// Lab 15b
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// DvcSchedule5b by Michael Monitto(0985765)
#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;

  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  // TO DO -- write this function

  //reset the cost and previous indices for all vertices, and mark all as not visited
  for(int i = 0; i < database.size(); i++)
  {
    database[i].isVisited = false;
    database[i].prev = -1;
    database[i].cost = 0;
  }
  //create a queue to store "vertices to consider"
  queue<int> vertexQueue;
  if (iStart < 0 || iStart >= database.size()) return result; // empty queue -- no such city
  //mark start vertex as "visited" and push it onto the "vertices to consider" queue
  database[iStart].isVisited = true;
  vertexQueue.push(iStart);
  //while the "vertices to consider" queue is not empty
  while(!vertexQueue.empty())
  {
    //peek/pop a vertex from the "vertices to consider" queue
    int u = vertexQueue.front();
    vertexQueue.pop();
    //for each of that vertex's neighbors
    for(it = database[u].adjacentVertices.begin(); it != database[u].adjacentVertices.end(); ++it)
    {
      //if neighbor has not yet been visited
      if(!database[it->first].isVisited)
      {
        //mark neighbor as visited
        database[it->first].isVisited = true;
        //set neighbor's cost to 1+cost of vertex under consideration
        database[it->first].cost = database[u].cost + 1;
        //set neighbor's previous vertex to the vertex under consideration
        database[it->first].prev = u;
        //push neighbor into the "vertices to consider" queue
        vertexQueue.push(it->first);
      }
      //if neighbor vertex contains the index of the end city
      if(it->first == iEnd)
      {
        //empty the queue and exit for-loop
        while(!vertexQueue.empty())
          vertexQueue.pop();
        break;
      }
    }
  }
  //the route's cost equals the end vertex's cost
  result.second = database[iEnd].cost;
  //build a stack of entries, starting from the end vertex, back towards the start
  for(int vertex = iEnd; vertex >= 0; vertex = database[vertex].prev)
    result.first.push(vertex);
  return result;
}

int main()
{

  // identifying output statements
  cout << "Programmer: Michael Monitto\n";
  cout << "Description: This program displays trees and graphs.\n";
  cout << "Finds the shortest route.\n";
  cout << endl;


  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity, cost;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator
    // TO DO -- code to eliminate whitespace
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    // store bi-directional edges
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;

    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;

    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;

    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;

    cout << "Route";
    pair<stack<int>, double> result = getShortestRoute(iFrom, iTo, database);
    while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
    cout << "\nTotal edges: " << result.second;
    cout << endl;
  }
}
