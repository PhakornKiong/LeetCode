#include "dynamicArr.h"
#include <iostream>
#include <stdexcept>

using namespace std;

DynamicArray::DynamicArray(int initSize)
{
  size = initSize;
  array = new int[initSize];

  for (int i = 0; i < size; i++)
  {
    // Initialize with zero
    array[i] = 0;
  }
}

DynamicArray::DynamicArray(const DynamicArray &original)
{
  size = original.size;
  array = new int[size];
  for (int i = 0; i < size; i++)
  {
    array[i] = original.array[i];
  }
}

DynamicArray::~DynamicArray()
{
  delete[] array;
}

void DynamicArray::insert(int position, int value)
{
  array[position] = value;
}

int DynamicArray::get(int position)
{
  return array[position];
}

int DynamicArray::getSize()
{
  return size;
}

void DynamicArray::resize(int newSize)
{
  int *temp;
  temp = new int[newSize];
  for (int i = 0; i < newSize; i++)
  {
    temp[i] = array[i];
  }
  delete[] array;
  array = temp;
  size = newSize;
}

int DynamicArray::indexOf(int value)
{
  for (int i = 0; i < size; i++)
  {
    if (array[i] == value)
    {
      return i;
    }
  }
  return -1;
}

int DynamicArray::contains(int value)
{
  return indexOf(value) != -1;
}

int DynamicArray::removeAt(int position)
{

  if (position >= size || position < 0)
  {
    throw std::runtime_error("Out of Position");
  }
  int removedValue = array[position];

  int newSize = size - 1;
  int *temp;
  temp = new int[newSize];
  for (int i = 0, j = 0; i < size; i++, j++)
  {
    if (i == position)
    {
      j--;
      continue;
    }
    temp[j] = array[i];
  }

  delete[] array;
  array = temp;
  size = newSize;
  return removedValue;
}

void DynamicArray::printAll()
{
  for (int i = 0; i < size; i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}

int &DynamicArray::operator[](int index)
{
  if ((index - 1) > size)
  {
    resize(index + 1);
  }
  return array[index]; // returned as a reference
}

bool DynamicArray::operator==(DynamicArray a)
{
  if (a.size != size)
    return false;

  for (int i = 0; i < (a.size); i++)
  {
    if (a[i] != array[i])
      return false;
  }
  return true;
}

bool DynamicArray::operator!=(DynamicArray a)
{
  if (a.size != size)
    return true;

  for (int i = 0; i < (a.size); i++)
  {
    if (a[i] != array[i])
      return true;
  }
  return false;
}