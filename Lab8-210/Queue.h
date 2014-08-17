// Lab 8c
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// QueueDriver.cpp by Michael Monitto (0985765)

//ifndef node
#ifndef NODE
#define NODE
template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};
#endif
//ifndef Queue
#ifndef QUEUE_H
#define QUEUE_H

template <class DataType>
class Queue
{
private:
  Node<DataType> *front; //front
  Node<DataType> *end; //end
public:
  Queue(); //constructor
  Queue(const Queue<DataType>&); //copy constructor
  ~Queue(); //destructor
  bool isEmpty() const; //getter
  void push(const DataType&);
  bool peek(DataType&) const; //getter
  bool pop(DataType&);
  void makeEmpty();
  Queue<DataType>& operator=(const Queue<DataType>&); //operator overload
};
//constructor
template <class DataType>
Queue<DataType>::Queue():front(0), end(0)
{}
//copy constructor
template <class DataType>
Queue<DataType>::Queue(const Queue<DataType>&a) :front(0), end(0)
{
  Node<DataType>* p;
  for(p = a.front;p;p=p->next)
  { 
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if(end) end->next = node;
      else front = node;
    end = node;
  }
}
//empty
template <class DataType>
bool Queue<DataType>::isEmpty() const 
  {return 0 == front;}
//push
template <class DataType>
void Queue<DataType>::push(const DataType& parameter)
{
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = 0;
  if(end) end->next = node;
    else front = node;
  end = node;
}
//peek
template <class DataType>
bool Queue<DataType>::peek(DataType& parameter) const
{
  if(0 == front) return false; //failed
  parameter = front->data;
    return true; //success
}
//pop
template <class DataType>
bool Queue<DataType>::pop(DataType& parameter)
{
  if(0 == front) return false; //failded
  parameter = front->data;
  Node<DataType>*p = front->next;
  delete front;
  front = p;
  if(front == 0)end = 0;
    return true; //success
}
//empty
template <class DataType>
void Queue<DataType>::makeEmpty()
{
  end = 0;
  Node<DataType>* p;
  while(front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}
//operator = overload
template <class DataType>
Queue<DataType>&Queue<DataType>::operator=(const Queue<DataType>&a)
{
  if(this != &a)
  {
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while(front)
    {
      p = front->next;
      delete front;
      front = p;
    }
    for(p = a.front;p;p=p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if(end) end->node = node;
        else front = node;
      end = node;
    }
  }
  return this;
}
//destructor
template <class DataType>
Queue<DataType>::~Queue()
{
  Node<DataType>* p;
  while(front)
  {
    p = front->next;
    delete front;
    front = p;
  }
}
#endif