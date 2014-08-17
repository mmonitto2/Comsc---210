// Lab 11
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// HashTable.h by Michael Monitto (0985765)

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <algorithm>
#include <assert.h> //for assertions
#include <list>
using namespace std;


//class HashTable
template <class DataType,int CAPACITY>
class HashTable
{
public:
  HashTable(); //constructor
  int getSize() const; //getter
  bool retrieve(DataType&);
  bool replace(DataType&);
  bool remove(DataType&);
  bool first(DataType&);
  bool getNext(DataType&);
  void setWrappedIndex(int);
  void insert(const DataType&);
  void clear();
private:
  list<DataType> theList[CAPACITY]; //used #include <list>
  typename list<DataType>::const_iterator itCurrent;
  int size,current;
  int wrappedIndex;
};

//constuctor
template <class DataType, int CAPACITY>
HashTable<DataType,CAPACITY>::HashTable():size(0),current(-1),wrappedIndex(0)
{}

template <class DataType, int CAPACITY>
void HashTable<DataType, CAPACITY>::setWrappedIndex(int DI)
{
  if(DI > CAPACITY)
  {
    wrappedIndex = DI % CAPACITY;
    if(wrappedIndex > CAPACITY)
    {
      while (wrappedIndex > CAPACITY)
        wrappedIndex = wrappedIndex % CAPACITY;
    }
  }
  else if (DI < 0)
  {
    while(DI < 0 && DI < CAPACITY)
    {
      DI += CAPACITY;
    }
    wrappedIndex = DI;
  }
  else
    wrappedIndex = DI;
}

//insert function
//passes the Key struct through parameters and sets its wrapped index
//Struct needs a "hashCode() function"
template <class DataType, int CAPACITY>
void HashTable<DataType, CAPACITY>::insert(const DataType& parameter)
{
  int i = parameter.hashCode();
  setWrappedIndex(i); //sets the wrappedIndex
  typename list<DataType>::iterator it;

  it = find(theList[wrappedIndex].begin(), theList[wrappedIndex].end(), parameter);

  if(it != theList[wrappedIndex].end())
    *it = parameter;

  else
  {
    theList[wrappedIndex].push_back(parameter);
    ++size;
  }
}

//retieve function
//passes Key thought parameter and sets the WrappedIndex
//Struct needs a hashCode() function
template <class DataType, int CAPACITY>
bool HashTable<DataType,CAPACITY>::retrieve(DataType& parameter)
{

  int i = parameter.hashCode();
  setWrappedIndex(i); //sets the wrappedIndex
  typename list<DataType>::const_iterator it; //const_iterator
  it = find(theList[wrappedIndex].begin(), theList[wrappedIndex].end(), parameter);

  if(it == theList[wrappedIndex].end())
    return false;
  parameter = *it;
  return true;
}

//replace function
//passes Key thought parameter and sets the WrappedIndex
//Struct needs a hashCode() function
template <class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::replace(DataType& parameter)
{
  int i = parameter.hashCode();
  setWrappedIndex(i); //sets the wrappedIndex
  typename list<DataType>::iterator it;  //iterator

  it = find(theList[wrappedIndex].begin(), theList[wrappedIndex].end(), parameter);

  if(it == theList[wrappedIndex].end())
  {
    return false;
  }
  *it = parameter;
  return true;
}

//remove function
//passes Key thought parameter and sets the WrappedIndex
//Struct needs a hashCode() function
template <class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::remove(DataType& parameter)
{
  int i = parameter.hashCode();
  setWrappedIndex(i); //sets the wrappedIndex
  bool results = false;
  typename list<DataType>::iterator it;

  it = find(theList[wrappedIndex].begin(), theList[wrappedIndex].end(), parameter);
  if(it == theList[wrappedIndex].end())
    return false;
  theList[wrappedIndex].erase(it);
  --size;
  return true;
}

//clear function
template <class DataType, int CAPACITY>
void HashTable<DataType,CAPACITY>::clear()
{
  for(current = 0; current < CAPACITY; current++)
  {
    if(!theList[current].empty())
    {
      theList[current].clear();
    }
  }
  size = 0;
}
//getSize function
template <class DataType, int CAPACITY>
int HashTable<DataType, CAPACITY>::getSize() const
{
  return size;
}
//first function
template <class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::first(DataType& parameter)
{
  assert(current >= -1 && current < CAPACITY);
  for(current = 0; current < CAPACITY; current++)
  {
    if(!theList[current].empty())
    {
      itCurrent = theList[current].begin();
      break;
    }
  }
  if (current == CAPACITY) current = -1;
  if(current == -1) return false;
  parameter = *itCurrent;
  return true;
}
//getNext function
template <class DataType, int CAPACITY>
bool HashTable<DataType, CAPACITY>::getNext(DataType& parameter)
{
  assert(current >= -1 && current < CAPACITY);


  if(current == -1) return false;
  assert(!theList[current].empty());
  if(++itCurrent == theList[current].end())
  {
    for(current = current + 1; current < CAPACITY; current++)
    {
      if(!theList[current].empty())
      {
        itCurrent = theList[current].begin();
        break;
      }
    }
  }
  if (current == CAPACITY) current = -1;
  else parameter = *itCurrent;
  return current >= 0;
}
#endif
