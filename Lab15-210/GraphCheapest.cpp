// Lab 15c
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// DvcSchedule5b by Michael Monitto(0985765)

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
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

struct Container // vertex container, for multiple ways to get to a vertex
{
  int vertex; // index in database array
  int prev; // index in database array
  double cost;
  bool operator<(const Container& v) const
  {
    return cost > v.cost;
  }
};

pair<stack<int>, double> getCheapestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it; // to iterate over adjacentVertices
  // TO DO -- write this function
  //reset the cost and previous indices for all vertices, isVisited to false
  for(int i = 0; i < database.size(); i++)
  {
    database[i].isVisited = false;
    database[i].cost = 0;
    database[i].prev = -1;
  }
  //create priority queue of Container objects
  priority_queue<Container> vertexQueue;
  //create a Container object for the start vertex, with 0 cost and negative prev index
  Container iOriginVertex;
  iOriginVertex.vertex = iStart;
  iOriginVertex.cost = 0;
  iOriginVertex.prev = -1;
  //push the start vertex's container onto the priority queue
  vertexQueue.push(iOriginVertex);
  //while the priority queue is not empty
  while(!vertexQueue.empty())
  {
    //peek/pop a container object from the priority queue
    Container u = vertexQueue.top();
    vertexQueue.pop();
    //if contained object's been visited, "continue"
    if(database[u.vertex].isVisited) continue;
    //mark contained object as visited
    database[u.vertex].isVisited = true;
    //set its cost to that of its container
    database[u.vertex].cost = u.cost;
    //set its prev to that of its container
    database[u.vertex].prev = u.prev;
    //if contained vertex is the end vertex, exit while-loop
    if(u.vertex == iEnd) break;
    //for each of that vertex's unvisited neighbors
    for(it = database[u.vertex].adjacentVertices.begin(); it != database[u.vertex].adjacentVertices.end(); it++)
    {
      //create a container object for neighbor
      Container neighbor;
      neighbor.vertex = it->first;
      //set its cost to that of the vertex, plus edge cost
      neighbor.cost = u.cost + it->second;
      //set its previous to the vertex
      neighbor.prev = u.vertex;
      //push container onto priority queue
      vertexQueue.push(neighbor);
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
  cout << "Description: This program displays trees and graphs using Dijkstra's algorithm,\n";
  cout << "by finding the cheapest route.\n";
  cout << endl;
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";
  // process the input file
  // load database
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
     // get start/end points
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
    pair<stack<int>, double> result = getCheapestRoute(iFrom, iTo, database);
    while (!result.first.empty()){cout << '-' << database[result.first.top()].name; result.first.pop();}
    cout << "\nTotal Miles: " << result.second;
    cout << endl;
  }
}

