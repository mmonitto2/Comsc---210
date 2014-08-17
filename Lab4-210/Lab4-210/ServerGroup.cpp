// Lab 4a 
// Programmer: Michael Monitto
// Editor(s) used: VS++ 2010 Express 
// Compiler(s) used: VC++ 2010 Express

//ServerGroup.cpp by Michael Monitto (0985765)
#include "ServerGroup.h"
//constructor
ServerGroup::ServerGroup(int s)
{
  size = s; //sets size of the array
  spServer = 0; //set to zero
  servers = new int[size]; //create a new dynamic array
  for (int i = 0; i < size; i++){
    servers[i] = 0; // loop to set server values to zero
  }
}
//spServerFree
bool ServerGroup::spServerFree() const
{
  return (spServer == 0); //return true if spServer is zero
}
//serverFree
bool ServerGroup::serverFree() // cant be const cause sets freeServer to i
{
  bool serverfree = false;
  for(int i = 0; i < size; i++)
  {
    if(servers[i] == 0)
    {
      serverfree = true;
      freeServer = i;
    }
  }
  return serverfree;
}
//useServer
void ServerGroup::useServer(int avTransTime)
{
  servers[freeServer] = avTransTime; 
}
//usespServer
void ServerGroup::usespServer(int avTransTime)
{
  spServer = avTransTime;
}
//decServers
void ServerGroup::decServers()
{
  if(spServer != 0)
    spServer = spServer - 1; // subtracts 1 from spServer
 
  for(int i = 0; i < size; i++)
  {
    if(servers[i] !=0)
    {
      servers[i] = servers[i] - 1; //subtracts 1 from servers
    }
  }
}