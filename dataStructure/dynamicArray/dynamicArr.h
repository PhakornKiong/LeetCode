
class DynamicArray
{
public:
  DynamicArray(int initSize);
  DynamicArray(const DynamicArray &original);
  ~DynamicArray();

  void insert(int position, int value);
  int get(int position);

  int indexOf(int value);
  int contains(int value);
  int removeAt(int position);

  int getSize();
  void resize(int newSize);
  void printAll();

  int &operator[](int index);
  bool operator==(DynamicArray);
  bool operator!=(DynamicArray);

private:
  int size;
  int *array;
};