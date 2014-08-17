// Lab 4a 
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express 
// Compiler(s) used: VC++ 2010 Express
// ServerGroupDriver.cpp by Michael Monitto (0985765)
#include <iostream>
using namespace std;
// extra includes
#include <cassert>
#include "ServerGroup.h"

int main()
{
  // identifying output statements
  cout << "Programmer: Michael Monitto\n";
  cout << "Description: This is start to a larger program. It is a movie senario\n";
  cout << "used to set size of an dynamic array test if full or empty,\n";
  cout << "and decrement the values set in the array till zero.\n";
  cout << "Later will be used to evalute servers." << endl;
  cout << endl;
  
  //number is the number of general purpose servers
  ServerGroup server(1);
  cout << "There is a bomb set to go off in the White House!" << endl;
  cout << "The bomb is a special one designed to kill off the President!" << endl; 
  cout << "Lets hope our hero can deactivate it in time before is explodes!" << endl;

  //The interger value is the number of clock ticks unitl the special - purpose server is free.
  //if the value is 0 the special purpose server is already free
  assert(server.spServerFree() == true);
  cout << endl;

  //same as useServer except it is for gereral purpose servers and not special purpose servers
  server.usespServer(4);
  cout << "The bomb is set to go off in" << endl;
  cout << "4 seconds" << endl;
  assert(server.spServerFree() == false);

  //called when a clock tick of time elapses
  server.decServers();
  cout << "3 seconds" << endl;
  server.decServers();
  cout << "2 seconds" << endl;
  server.decServers();
  cout << "1 second" << endl;
  server.decServers();
  cout << endl;
  assert(server.spServerFree() == true);
  cout << "But wait.."<< endl;
  cout << "Nothing happens there was no explosion." << endl;
  cout << "The real bomb is outside!" << endl;
  cout << "Set to explode in the general public." << endl;
  cout << "Killing hundreds of innocent people!" << endl;

  //These integers also represent the number of clock ticks until the correct corresponding servers are free
  //freeServer has the index of one of the servers that are free
  assert(server.serverFree() == true);
  cout << "There is no chance our hero will make it in time to deactivate it!" << endl;
  cout << endl;
  //avTransTime is the average transaction time, in clock ticks, to serve a person in line
  server.useServer(4);
  cout << "The general public bomb is set to blow in" << endl;
  assert(server.serverFree() == false);
  //called when a clock tick of time elapses
  server.decServers();
  cout << "6 seconds" << endl;
  server.decServers();
  cout << "5 seconds" << endl;
  server.decServers();
  cout << "4 seconds" << endl;
  server.decServers();
  cout << "3 seconds" << endl;
  server.decServers();
  cout << "2 seconds" << endl;
  server.decServers();
  cout << "1 second" << endl;
  server.decServers();
  assert(server.serverFree() == true);
  cout << endl;
  cout << "KABOOM!!" << endl;

  //testing const object with only const getter	
  const  ServerGroup server2(12);
  server2.spServerFree();

  cout << "press ENTER to continue..." <<endl;
  cin.get();
}
