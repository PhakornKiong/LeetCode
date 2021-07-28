#include <iostream>
#include "dynamicArr.h"

using namespace std;

// g++ -W main.cpp dynamicArr.h dynamicArr.cpp -o main.exe

int main(int argc, char **argv)
{

  cout << "Dynamic array..." << endl;

  DynamicArray array = DynamicArray(4);
  array.insert(1, 7);
  array.insert(3, 2);

  array[2] = 4;

  array[6] = 11;

  cout << "created array successfully" << endl;

  cout << "Item exists in array case, return index at " << array.indexOf(7) << endl;

  cout << "Item do not exists in array case, return negative number  " << array.indexOf(1231) << endl;

  // Print all item
  array.printAll();

  int removedItem = array.removeAt(2);
  cout << "remove index 2 will return:  " << removedItem << endl;

  // Following Two line will terminate the program
  // removedItem = array.removeAt(-9);
  // removedItem = array.removeAt(100);

  DynamicArray array2 = DynamicArray(array);
  if (array == array2)
  {
    cout << "Both Array is the same" << endl;
  }

  array.insert(1, 9999);
  if (array != array2)
  {
    cout << "Array is not the same" << endl;
  }

  return 0;
}