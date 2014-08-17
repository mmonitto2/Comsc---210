
// Lab 14
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// Array.h by Michael Monitto (0985765)

#include <string>

template <class DataType>
class Array
{
public:
  Array(int initialCapacity);
  Array(const Array<DataType>&);
  ~Array();
  Array<DataType> & operator=(const Array<DataType>&);
  DataType & operator[](int index);
  void changeCapacity(int newCapacity);
  int getCapacity() const;
  string err() const;
  int lsearch(const DataType& element)const;
  int bsearch(const DataType& element);
  void sort(int size);
private:
  DataType *data;
  DataType dummy;
  int initial;
  int capacity;
  int errorCode;
  void quicksort(int, int);
  int bsearch2(DataType*,const DataType&,int,int);

};
//constructor
template <class DataType>
Array<DataType>::Array(int initialCapacity):capacity(initialCapacity),errorCode(0),data(0),initial(0)
{
  if(capacity <= 0)
  {
    errorCode |= 1;
  }
  else
    data = new DataType[capacity];
}
//copy constructor
template <class DataType>
Array<DataType>::Array(const Array<DataType>&a):capacity(a.capacity),errorCode(a.errorCode),data(0),initial(0)
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
Array<DataType>::~Array()
{
  delete []data;
}
//overload the [] operator
template <class DataType>
DataType& Array<DataType>::operator[] (int index)
{
  if(index < 0 || index >= capacity)
  {
    errorCode |= 2;
    return dummy;
  }
  errorCode &= (7-2);
  return data[index];
}
//overload the = operator
template <class DataType>
Array<DataType>& Array<DataType>::operator=(const Array<DataType>&a)
{
  if (this != &a)
  {
    delete [] data;
    capacity = a.capacity;
    errorCode = a.errorCode;
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
//change the capacity of the array if full
template <class DataType>
void Array<DataType>::changeCapacity(int newCapacity)
{
  errorCode &= (7-4);
  if (newCapacity <=0)
    errorCode |=4;
  else
  {
    DataType* newData = new DataType[newCapacity];
    int limit = newCapacity > capacity ? capacity : newCapacity;
    for (int i = 0; i < limit; i++)
      newData[i] = data[i];
    delete []data;
    data = newData;
    capacity = newCapacity;
   }
}
//display error codes if called
template <class DataType>
string Array<DataType>::err() const
{
  string result;
  if(errorCode & 1)
    result += string(result.length() ? " | " : "") + "invalid capacity parameter in constructor";
  if(errorCode & 2)
    result += string(result.length() ? " | " : "") + "invalid index used in []";
  if (errorCode & 4)
    result += string(result.length() ? " | " : "") + "invalid new capacity parameter in changeCapacity";
  return result;
}
//returns capacity
template <class DataType>
int Array<DataType>::getCapacity() const
{
  return capacity;
}
//performs linear search on a element
template <class DataType>
int Array<DataType>::lsearch(const DataType& element) const
{
  int result = -1;
  for(int i = 0; i < capacity; i++){
    if(element == data[i]){
      result = i+1;
      break;
    }
  }
  return result;
}
//quicksort function
template <class DataType>
void Array<DataType>::quicksort(int s, int e)
{
  if(s >= e) return; //done!
  int pivot = (s + e) / 2;
  int l = s;
  int r = e;
  while(true)
  {
    while (l < pivot)
      {if(data[pivot] < data[l]) break; else ++l;}
    while (pivot < r)
      {if(data[r] < data[pivot]) break; else --r;}
    if (l == r) //balanced
    {
      quicksort(s, pivot - 1);
      quicksort(pivot + 1, e);
      break;
    }
    else if (l == pivot)
    {
      DataType temp = data[pivot];
      data[pivot] = data[r];
      data[r] = temp;
      pivot = r;
      ++l;
    }
    else if(pivot == r)
    {
      DataType temp = data[pivot];
      data[pivot] = data[l];
      data[l] = temp;
      pivot = l;
      --r;
    }
    else
    {
      DataType temp = data[l];
      data[l] = data[r];
      data[r] = temp;
      ++l;
      --r;
    }
  }
}
//sort function
template<class DataType>
void Array<DataType>::sort(int size)
{
  quicksort(initial,size - 1);
}
//bsearch function
template<class DataType>
int Array<DataType>::bsearch(const DataType& element)
{
  int result = -1;
  result = bsearch2(data,element,initial,capacity);
  return result;
}
//bsearch2 function
template<class DataType>
int Array<DataType>::bsearch2(DataType* a,const DataType& value, int s, int e)
{
  int m = (s + e) / 2;
  if (value == a[m])
  {
    return m + 1;
  }
  else if (s == e)
    return -1;
  else if (value < a[m])
  {
    if (s == m) return -1;
    else return bsearch2(a,value,s,m-1);
  }
  else
  {
    if(m == e) return -1;
    else return bsearch2(a,value,m+1,e);
  }
}

