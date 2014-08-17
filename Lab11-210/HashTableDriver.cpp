// Lab 11a
// Programmer: Michael Monitto
// Editor(s) used: VC++ 2010 Express
// Compiler(s) used: VC++ 2010 Express
// HashTable.h by Michael Monitto (0985765)

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>
#include <cassert>

#include "HashTable.h"
#include "HashTable.h"

#define HASHTABLE_CAPACITY 1009

struct Key
{
  string term;
  string section;
  string course;
  string instructor;
  bool operator==(const Key& k) const {return term == k.term && section == k.section && course == k.course;}
  int hashCode() const;
};

int Key::hashCode() const
{
  int key = 0;
  string s = term + section + course;
  for (int i = 0; i < s.length(); i++)
    key = key + s[i];
  key = key - 951;
  return key;
}

int main()
{
  cout << "Programmer: Michael Monitto" << endl;
  cout << "Description: this is a test driver for HashTable class." << endl;

  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";

  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  HashTable<Key, HASHTABLE_CAPACITY> hashTable;
  Key record;
  int count = 0;
  // read the input file
  while (fin.good())
  {
    if (!(count < 500)) break;
    // read the lines
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    record.term = term;
    record.section = section;
    record.course = course;
    record.instructor = instructor;

    hashTable.insert(record);
    count++;
  }
  fin.close();

  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";

  count = 0;
  while (fin.good())
  {
    if (!(count < 500)) break;
    // read the lines
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;

    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));

    assert(hashTable.retrieve(record) == 1);
    count++;
  }
  fin.close();

  assert(count == 500);
  int doubles = count - hashTable.getSize();
  cout << "Number of Duplicates for the first 500 records(Expect 1): " << doubles << endl;

  Key test;
  test.term = "Spring 2005";
  test.section = "1022";
  test.course = "MATH-110"; //the first entry of the file
  hashTable.remove(test);
  assert(hashTable.retrieve(test) == 0);
  assert(hashTable.replace(test) == 0);
  hashTable.insert(test);
  assert(hashTable.replace(test) == 1);

  int size = 0;
  if (hashTable.first(test)) do
  {
    size++;
  } while (hashTable.getNext(test));

  assert(size == hashTable.getSize());

  {
    const HashTable<Key, HASHTABLE_CAPACITY> copy = hashTable;
    assert(copy.getSize() == hashTable.getSize());
  }

  {
    HashTable<Key, HASHTABLE_CAPACITY> copy; copy = hashTable;
    assert(copy.getSize() == hashTable.getSize());
    assert(copy.retrieve(test) == 1);
    copy.remove(test);
    assert(copy.getSize() == hashTable.getSize() - 1);
    copy.clear();
    assert(copy.remove(test) == 0);
    assert(copy.replace(test) == 0);
  }

  hashTable.clear();
  cout << "Expect the size of the hash table becomes 0, and actual is " << hashTable.getSize() << endl;
}

