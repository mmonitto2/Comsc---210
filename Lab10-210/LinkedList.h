// Lab 10a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// LinkedList.h by Michael Monitto (0985765)
#include <cassert>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType> *next;
};

template <class DataType>
class LinkedList
{
public:
  LinkedList();  //constructor
  LinkedList(const LinkedList<DataType>&a);
  ~LinkedList();
  LinkedList<DataType>& operator=(const LinkedList<DataType>& a);
  DataType& operator[](int index);
  void insert(const DataType& parameter);
  bool first(DataType & parameter);
  bool getNext(DataType& parameter);
  bool find(const DataType& parameter);
  bool retrieve(DataType& parameter);
  bool replace(const DataType& parameter);
  bool remove(DataType& parameter);
  bool isEmpty() const;
  int  length()const;
  int  getIndex() const;
  void makeEmpty();
private:
  Node<DataType> *start;
  Node<DataType> *current;
  int size;
  int currentIndex;
  int index;
  DataType dummy;
};
#endif

template <class DataType>
LinkedList<DataType>::LinkedList():start(0),current(0),size(0),currentIndex(0),index(0){} //constructor

template <class DataType> //copy constructor
LinkedList<DataType>::LinkedList(const LinkedList<DataType>&a)
: start(0),current(0),size(0),currentIndex(0),index(0)
{
  Node<DataType>* p;
  Node<DataType>* end = 0;
  for(p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
	node->data = p->data;
	node->next = 0;
	if(end) end->next = node;
	end = node;
	if(p == a.current) current = node;
  }
}

template <class DataType> //Destructor
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  while(start)
  {
    p = start->next;
	delete start;
	start = p;
  }
}

template <class DataType>
DataType& LinkedList<DataType>::operator[](int index)
{
  if(index == 0)
  {
    currentIndex = -1;
    assert(currentIndex == -1);
    current = start;
	currentIndex++;
	return start->data;
  }
  if(index == currentIndex + 1)
  {
    assert(currentIndex >= 0);
    current = current->next;
    currentIndex++;
    return current->data;
  }
  for(current = start; current; current = current->next)
  {
    if(currentIndex == index)break;
    currentIndex++;
  }
  if(current)
    return current->data;
  else
    return dummy;
 }

template <class DataType> //operator = overloaded
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a)
{
  if(this != &a)
  {
    current = 0;
	Node<DataType> *p;
	Node<DataType>* end = 0;
	while(start)
	{
      p = start->next;
	  delete start;
	  start = p;
    }
	for (p = a.start; p; p = p->next)
	{
      Node<DataType>* node = new Node<DataType>;
	  node->data = p->data;
	  node->next = 0;
	  if(end) end->next = node;
	  else start = node;
	  end = node;
	  if(p == a.current) current = node;
    }
  }
  return *this;
}
//insert function
template <class DataType>
void LinkedList<DataType>::insert(const DataType& parameter)
{
  current = 0;
  size++;
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = start;
  start = node;
}
//getNext Function
template <class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter)
{
  if (!current) return false;
  current = current->next;
  if(!current) return false;
  parameter = current->data;
  return true;
}

//first function
template <class DataType>
bool LinkedList<DataType>::first(DataType& parameter)
{
  if(!start) return false;
  parameter = start->data;
  current = start;
  return true;
}

//find function
template <class DataType>
bool LinkedList<DataType>::find(const DataType& parameter) // O(n)
{
  DataType temp;
  index = 0;
  if(first(temp))do
  {
    index++;
    if (parameter == temp) return true; //found it

  }while (getNext(temp));
  return false; // no match
}

//retrieve function
template <class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter) //O(n)
{
  if(!find(parameter)) return false;
  parameter = current->data;  //set in find
  return true;
}

//replace function
template <class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter) //O(1)
{
  if(!current) return false;
  current->data = parameter;
  return true;
}
//remove function
template <class DataType>
bool LinkedList<DataType>::remove(DataType& parameter)
{
  //find node to remove
  Node<DataType>* p;
  Node<DataType>* prev;
  size--;
  for(prev = 0, p = start;p;prev=p,p=p->next)
    if(p->data == parameter)
      break;
  //deallocate node here
  if(!p) return false; //no match
  if(prev) {prev->next = p->next;}
    else start = p->next;
  if(p==current)current = current->next;
  parameter = p->data;
  delete p;
  return true;
}
//isEmpty function
template <class DataType>
bool LinkedList<DataType>::isEmpty() const //O(1)
{
  return start == 0;
}
//makeEmpty function
template <class DataType>
void LinkedList<DataType>::makeEmpty() //O(n)
{
  while(start)
  {
    current = start->next;
	delete start;
	start = current;
  }
}
template <class DataType>
int LinkedList<DataType>::length() const
{
  return size;
}

template <class DataType>
int LinkedList<DataType>::getIndex() const
{
  return index;
}
