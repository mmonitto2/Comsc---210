// Lab 4a 
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express 
// Compiler(s) used: VC++ 2010 Express

//ServerGroup.h by Michael Monitto (0985765)
#include <iostream>
using namespace std;

#ifndef SERVERGROUP_H
#define SERVERGROUP_H
class ServerGroup
{
private:
  int* servers; //pointer
  int  spServer; //private
  int  freeServer; //private
  int  size; //private
public:
  ServerGroup(int s);//constructor
  bool spServerFree()const; //getter
  bool serverFree(); //getter
  void useServer(int avTransTime); //setter 
  void usespServer(int avTransTime); //setter
  void decServers(); //setter
};
#endif