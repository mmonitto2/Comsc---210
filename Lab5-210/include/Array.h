
template <class DataType>
class Array
{
public:
  Array(int initialCapacity);
  Array(const Array<DataType>&);
  ~Array();
  Array & operator=(const Array<DataType>&);
  DataType & operator[](int index);
  void changeCapacity(int newCapacity);
  int getCapacity() const;
  string err() const;
  int lsearch(const DataType& element)const;
private:
  DataType *data;
  DataType dummy;
  int capacity;
  int errorCode;
};

template <class DataType>
Array<DataType>::Array(int initialCapacity)
{
  capacity = initialCapacity;
  errorCode = 0;
  if(capacity <= 0)
  {
    errorCode |= 1;
	data = 0;
  }
  else
    data = new DataType[capacity];
}

template <class DataType>
Array<DataType>::Array(const Array<DataType>&a)
{
  capacity = a.capacity;
  errorCode = a.errorCode;
  data = 0;

  if(capacity > 0)
  {
    data = new DataType[capacity];
	for(int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
}

template <class DataType>
Array<DataType>::~Array()
{
  delete []data;
}

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
template <class DataType>
int Array<DataType>::getCapacity() const
{
  return capacity;
}

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

