// Lab 12a,b
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// PriorityQueue.h by Michael Monitto (0985765)

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <cassert>
#include <algorithm>

template <class DataType>
class PriorityQueue
{
public:
  PriorityQueue(int); //constructor
  PriorityQueue(const PriorityQueue<DataType>&); //copy Constructor
  PriorityQueue<DataType>& operator=(const PriorityQueue<DataType>&); //operator overload
  ~PriorityQueue();  //destructor
  void enqueue(const DataType&);
  void changeCapacity(int);
  DataType dequeue();
  DataType& operator[](int);
  int getSize() const; //getter
private:
  DataType *data;
  int capacity;
  int index;
  int parentIndex;
  int size;
};

//constructor
template <class DataType>
PriorityQueue<DataType>::PriorityQueue(int initialCapacity):capacity(initialCapacity),index(0),parentIndex(0),size(0)
{
  data = new DataType[capacity];
}
//copy constructor
template <class DataType>
PriorityQueue<DataType>::PriorityQueue(const PriorityQueue<DataType>&a): capacity(a.capacity),data(0)
{
  if(capacity > 0)
  {
    data = new DataType[capacity];
    for(int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
}
//destructor
template <class DataType>
PriorityQueue<DataType>::~PriorityQueue()
{
  delete []data;
}
//overload the [] operator
template <class DataType>
DataType& PriorityQueue<DataType>::operator[](int i)
{
  return data[i];
}
//overload the = operator
template <class DataType>
PriorityQueue<DataType>& PriorityQueue<DataType>::operator=(const PriorityQueue<DataType>&a)
{
  if (this != &a)
  {
    delete [] data;
    capacity = a.capacity;
    data = 0;
    if (capacity > 0)
    {
      data = new DataType[capacity];
      for (int i = 0; i < capacity; i++)
        data[i] = a.data[i];
    }
  }
  return *this;
}
//ChangeCapacity function
template <class DataType>
void PriorityQueue<DataType>::changeCapacity(int newCapacity)
{
  DataType* newData = new DataType[newCapacity];
  int limit = newCapacity > capacity ? capacity : newCapacity;
  for(int i = 0; i < limit; i++)
    newData[i] = data[i];
  delete []data;
  data = newData;
  capacity = newCapacity;
}
//enqueue function
template<class DataType>
void PriorityQueue<DataType>::enqueue(const DataType& parameter)
{
  index = size;
  if(index >= capacity)
    changeCapacity(capacity*2);  //increase capacity function
  data[index] = parameter;  //insert new value
  while(1)
  {
    parentIndex = (index + 1)/2 - 1;
    if(parentIndex < 0) break;
    if(data[parentIndex] >= data[index]) break;
      swap(data[parentIndex],data[index]);  //swap values to get root
    index = parentIndex;
  }
  ++size;  //increase size
}
//dequeue function
template<class DataType>
DataType PriorityQueue<DataType>::dequeue()
{
  DataType& temp = data[0]; //save value index 0
  index = 0;
  while(1)  //start loop
  {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    if(leftChild >= size) break;  //exit loop
    if(leftChild == size - 1 || data[leftChild] >= data[rightChild])
    {
      data[index] = data[leftChild];  //set value at index to value at left child
      index = leftChild;
    }
    else
    {
      data[index] = data[rightChild];  //set value at index to value at right child
      index = rightChild;
    }
  }
  --size;  //decrease size
  if(size < capacity/4)
    capacity /= 2;  //half the capacity
  data[index] = data[size];  //copy value at size into array at index

  while(data[parentIndex] < data[index])
  {
    parentIndex = (index + 1)/2 - 1;
    if(parentIndex < 0) break;
      swap(data[parentIndex],data[index]);  //swap values at parentIndex and index
    index = parentIndex;
  }
  return temp;
}

//getSize function
template <class DataType>
int PriorityQueue<DataType>::getSize() const
{
  return size;
}
#endif
