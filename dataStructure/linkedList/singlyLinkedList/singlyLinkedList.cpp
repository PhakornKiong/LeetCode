#include <iostream>

using namespace std;

inline void error(const string &s)
{
  throw runtime_error(s);
};

template <typename T>
struct Node
{
  T data;
  Node *next;
};

template <typename T>
class LinkedList
{
public:
  int length_;
  Node<T> *head_;
  Node<T> *tail_;

  LinkedList();
  ~LinkedList();

  bool isEmpty()
  {
    return this->head_ == nullptr;
  }

  void push(T data);
  void append(T data);
  void deleteNodeAt(int idx);
  void insertAt(T data, int idx);
  void deleteAt(int idx);
  Node<T> *get(int idx);
  T getData(int idx);
  void printSequence();
};

template <typename T>
LinkedList<T>::LinkedList()
{
  this->length_ = 0;
  this->head_ = nullptr;
  this->tail_ = nullptr;
};

// Destructor
template <typename T>
LinkedList<T>::~LinkedList()
{
  Node<T> *next = this->head_;
  Node<T> *curr = nullptr;
  while (next != nullptr)
  {
    curr = next;
    next = next->next;
    delete curr;
  }
  std::cout << "List deleted." << std::endl;
};

// Push to the Tail
template <typename T>
void LinkedList<T>::push(T data)
{
  Node<T> *node = nullptr;
  if (isEmpty())
  {
    node = new Node<T>;
    this->head_ = node;
  }
  else
  {
    node = this->tail_;
    node->next = new Node<T>;
    node = node->next;
  }
  node->data = data;
  node->next = nullptr;
  this->tail_ = node;
  this->length_++;
};

// Push to the Head
template <typename T>
void LinkedList<T>::append(T data)
{
  Node<T> *node = new Node<T>;
  node->data = data;
  node->next = this->head_;
  if (isEmpty())
  {
    this->tail_ = node;
  }

  this->head_ = node;
  this->length_++;
};

template <typename T>
void LinkedList<T>::insertAt(T data, int idx)
{
  Node<T> *prevNode = nullptr;
  Node<T> *newNode = new Node<T>;
  newNode->data = data;
  if (idx == 0)
  {
    prevNode = this->head_;
    this->head_ = newNode;
  }
  else if (idx == this->length_ - 1)
  {
    prevNode = this->tail_;
    this->tail_ = newNode;
  }
  else
  {
    prevNode = this->get(idx - 1);
  }
  newNode->next = prevNode->next;
  prevNode->next = newNode;
  this->length_++;
}

template <typename T>
void LinkedList<T>::deleteAt(int idx)
{
  Node<T> *node = nullptr;
  Node<T> *tempNode = nullptr;
  if (idx == 0)
  {
    node = this->head_->next;
    tempNode = this->head_;
    this->head_ = node;
  }
  else if (idx == this->length_ - 1)
  {
    node = this->get(idx - 1);
    tempNode = this->tail_;
    this->tail_ = node;
    node->next = nullptr;
  }
  else
  {
    node = this->get(idx - 1);
    tempNode = node->next;
    node->next = tempNode->next;
  }
  delete tempNode;
  this->length_--;
}

template <typename T>
Node<T> *LinkedList<T>::get(int idx)
{
  int i = 0;
  Node<T> *node = nullptr;
  if (idx >= this->length_ || idx < 0)
  {
    error("invalid index");
  }
  node = this->head_;
  while (i < idx)
  {
    node = node->next;
    i++;
  }
  // Return address of node
  return node;
};

template <typename T>
T LinkedList<T>::getData(int idx)
{
  Node<T> *node = this->get(idx);
  return node->data;
}
template <typename T>
void LinkedList<T>::printSequence()
{
  if (isEmpty())
  {
    std::cout << "List is empty." << std::endl;
  }
  else
  {
    Node<T> *node = this->head_;
    std::cout << "Singly linked list sequence:" << std::endl;
    while (node != nullptr)
    {
      std::cout << node->data << ' ';
      node = node->next;
    }
    std::cout << std::endl;
  }
}

int main()
{
  LinkedList<int> *list1 = new LinkedList<int>;
  for (int i = 0; i < 10; i++)
  {
    list1->append(i);
  }

  // list1->printSequence();
  // std::cout << list1->getData(8) << std::endl;

  // list1->insertAt(100, 0);
  // list1->printSequence();
  // std::cout << list1->length_ << std::endl;
  // std::cout << list1->head_->data << std::endl;
  // std::cout << list1->tail_->data << std::endl;

  // list1->insertAt(100, 9);
  // list1->printSequence();
  // std::cout << list1->length_ << std::endl;
  // std::cout << list1->head_->data << std::endl;
  // std::cout << list1->tail_->data << std::endl;

  // list1->printSequence();
  // list1->deleteAt(3);
  // list1->printSequence();
  // std::cout << "Length : " << list1->length_ << std::endl;
  // std::cout << "Head : " << list1->head_->data << std::endl;
  // std::cout << "Tail : " << list1->tail_->data << std::endl;
};