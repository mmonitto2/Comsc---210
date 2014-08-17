// Lab 8a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express

//Stack.h by Michael Monitto (0985765)
//ifndef NODE 
#ifndef NODE
#define NODE
template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};
#endif
//ifndef Stack
#ifndef STACK_H
#define STACK_H

template <class DataType>
class Stack
{
private:
  Node<DataType>* start; //start
public:
  Stack(); //constructor
  Stack(const Stack<DataType>&); //copy constructor
  ~Stack();//destructor
  bool isEmpty() const; //getter
  void push (const DataType&);
  bool peek(DataType&) const; //getter
  bool pop(DataType&);
  void makeEmpty();
  Stack<DataType>& operator=(const Stack<DataType>&);//operator overload
  
};
  //constructor
  template <class DataType>
  Stack<DataType>::Stack():start(0){}
  //copy constructor
  template <class DataType>
  Stack<DataType>::Stack(const Stack<DataType>& a): start(0)
  {
    Node<DataType>*p;
    Node<DataType>*end = 0;

    for(p = a.start;p;p=p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if(end) end->next = node;
       else start = node;
      end = node;
    }
  }
  //make empty
  template <class DataType>
  bool Stack<DataType>::isEmpty() const
    {return 0 == start;}
  //push
  template <class DataType>
  void Stack<DataType>::push(const DataType& parameter)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = parameter;
    node->next = start;
    start = node;
  }
  //top
  template <class DataType>
  bool Stack<DataType>::peek(DataType& parameter)const
  {
    if(0==start)return false;
    parameter = start->data;
    return true; //success
  }
  //pop
  template <class DataType>
  bool Stack<DataType>::pop(DataType& parameter) 
  {
    if (0==start)return false;
    parameter = start->data;
    Node<DataType> *p = start->next;
    delete start;
    start = p;
    return true; //success
  }
  //clear
  template <class DataType>
  void Stack<DataType>::makeEmpty()
  {
    Node<DataType>* p;
    while(start)
    {
      p = start->next;
      delete start;
      start = p;
    }
  }
  //operator overload
  template <class DataType>
  Stack<DataType>& Stack<DataType>::operator=(const Stack<DataType>& a)
  {
    if(this != &a)
    {
      Node<DataType>* p;
      Node<DataType>* end = 0;
      while(start)
      {
        p = start->next;
        delete start;
        start = p;
      }
      for(p = a.start; p ; p = p->next)
      {
        Node<DataType>* node = new Node<DataType>;
        node->data = p->data;
        node->next = 0;
        if(end) end->next = node;
          else start = node;
        end = node;
      }
	  
    }
    return this;
  }
  //destructor
  template <class DataType>
  Stack<DataType>::~Stack()
  {
    Node<DataType>* p;
    while(start)
    {
      p = start->next;
      delete start;
      start = p;
    }
  }
#endif

