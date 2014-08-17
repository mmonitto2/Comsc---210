// Lab 15a
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// DvcSchedule5b by Michael Monitto(0985765)

#include <fstream>
#include <algorithm>    // std::remove_if
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct Vertex
{
  string name;

  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  //create another queue to store "vertices to consider"
  queue<int> vertexQueue; // vertices to consider, by index
  //create an empty result queue to return at end of function call
  queue<int> searchOrder; // return this queue of indices
  //initialize each vertex in database:
  for (int i = 0; i < database.size(); i++) database[i].isVisited = false;
  if (iOriginVertex < 0 || iOriginVertex >= database.size()) return searchOrder; // empty queue -- no such city
  //mark starting vertex as "visited"
  database[iOriginVertex].isVisited = true;
  //push start vertex's index onto the result queue
  searchOrder.push(iOriginVertex);
  //push start vertex's index onto "vertices to consider" queue
  vertexQueue.push(iOriginVertex);
  //while "vertices to consider" queue is not empty
  list<int> ::iterator it;
  while (!vertexQueue.empty())
  {
    // TO DO -- write this code block
    //peek/pop a vertex from the "vertices to consider" queue
    int u = vertexQueue.front();
    vertexQueue.pop();
    //for each of that vertex's "neighbors"
    for(it = database[u].adjacentVertices.begin(); it != database[u].adjacentVertices.end(); it++)
    {
      //if neighbor has not yet been visited
      if(!database[*it].isVisited)
      {
        //mark neighbor as visited
        database[*it].isVisited = true;
        //push neighbor onto the result queue
        vertexQueue.push(*it);
        //push neighbor onto the "vertices to consider" queue
        searchOrder.push(*it);
      }
    }
  }
  return searchOrder;
}

queue<int> doDepthFirstSearch(int iOriginVertex, vector<Vertex>& vertices)
{
  // TO DO -- write this function
  //create an empty result queue for returning at the end
  queue<int> searchOrder;
  //create a stack to store "vertices to consider"
  stack<int> verticesQueue;
  //initialize each vertex in database: set to "not visited"
  for (int i = 0; i < vertices.size(); i++) vertices[i].isVisited = false;
  if (iOriginVertex < 0 || iOriginVertex >= vertices.size()) return searchOrder; // empty queue -- no such city
  //push start vertex's index onto the "vertices to consider" stack
  verticesQueue.push(iOriginVertex);
  //while "vertices to consider" stack is not empty
  list<int> ::reverse_iterator it;
  while(!verticesQueue.empty())
  {
    //peek/pop a vertex from the "vertices to consider" stack
    int u = verticesQueue.top();
    verticesQueue.pop();
    //if that vertex has not yet been visited
    if(!vertices[u].isVisited)
    {
      //mark the vertex as visited
      vertices[u].isVisited = true;
      //push vertex onto the result queue
      searchOrder.push(u);
      //for each of that vertex's "neighbors" (in reverse order)
      for(it = vertices[u].adjacentVertices.rbegin(); it != vertices[u].adjacentVertices.rend(); ++it)
      {
        //if neighbor has not yet been visited
        if(!vertices[*it].isVisited)
        {
          //push neighbor onto the "vertices to consider" stack
          verticesQueue.push(*it);
        }
      }
    }
  }
  return searchOrder;
}

int main()
{
  // identifying output statements
  cout << "Programmer: Michael Monitto\n";
  cout << "Description: This program displays trees and graphs.\n";
  cout << "Searches through the graphs with Depth First Search.\n";
  cout << "and Breadth First Search.\n";
  cout << endl;
  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator
    // TO DO -- code to eliminate whitespace
    fromCity.erase(remove_if(fromCity.begin(),fromCity.end(),::isspace),fromCity.end());
    toCity.erase(remove_if(toCity.begin(),toCity.end(),::isspace),toCity.end());

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
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
        break;

    // BFS result
    cout << "BFS";
    queue<int> q = doBreadthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }

    cout << endl;
    cout << endl;

    cout << "DFS";
    q = doDepthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }
    cout << endl;;
  }
}
