// FayeStevenLab11PriorityQueue.h
// by Steven Faye
// on 4/17/16
// Editor(s) used: Apple Xcode 7.3
// Compiler(s) used: Apple LLVM 7.1
// Lab 11, Priority Queue

#ifndef FayeStevenLab11PriorityQueue_h
#define FayeStevenLab11PriorityQueue_h
#include <cassert>

template <class T>
class PriorityQueue {
public:
  PriorityQueue(int initCap = 2) // constructor
  :heap(new T[initCap]),_size(0),_capacity(initCap){
    for (int i = 0; i < _capacity; i++) {
      heap[i] = T();
    }
  };
  PriorityQueue(const PriorityQueue&); // copy constructor
  void operator=(const PriorityQueue&); // assignement operator
  virtual ~PriorityQueue(){delete [] heap;}; // destructor
  void enqueue(const T&); // enqueue adds an element to PriorityQueue
  T top() const {return heap[0];}; // returns the value of the root "node"
  T dequeue(); // remove a value from PriorityQueue
  bool empty() const {return _size == 0;}; // returns true if PriorityQueue is empty
  void clear(); // clear all elements in the PriorityQueue
  int size() const {return _size;}; // returns the number of "nodes" in PriorityQueue
  int capacity() const {return _capacity;}; // returns the current array capacity
private:
  T* heap; // dynamically allocated array of templated values
  unsigned int _size; // tracks the current number of elements
  unsigned int _capacity; // tracks the current capacity
  void doubleArray(); // helper function to double capacity of array
};

// copy constructor
template <class T>
PriorityQueue<T>::PriorityQueue(const PriorityQueue<T>& anotherPQ) {
  if (this != &anotherPQ) {
    heap = new T[anotherPQ.capacity()];
    for (int i = 0; i < anotherPQ.capacity(); i++) {
      heap[i] = anotherPQ.heap[i];
    }
    _size = anotherPQ.size();
    _capacity = anotherPQ.capacity();
  }
}

// assignement operator
template <class T>
void PriorityQueue<T>::operator=(const PriorityQueue<T>& anotherPQ) {
  if (this != &anotherPQ) {
    delete [] heap;
    heap = new T[anotherPQ.capacity()];
    for (int i = 0; i < anotherPQ.capacity(); i++) {
      heap[i] = anotherPQ.heap[i];
    }
    _size = anotherPQ.size();
    _capacity = anotherPQ.capacity();
  }
}

// enqueue
template <class T>
void PriorityQueue<T>::enqueue(const T& newData) {
  unsigned int index = _size;
  if (index >= _capacity) {
    doubleArray();
  }
  heap[index] = newData;
  while (true) {
    int parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0)
      break;
    if (heap[parentIndex] >= heap[index])
      break;
    T temp = T();
    temp = heap[parentIndex];
    heap[parentIndex] = heap[index];
    heap[index] = temp;
    index = parentIndex;
  }
  _size++;
}

// dequeue
template <class T>
T PriorityQueue<T>::dequeue() {
  if (_size == 0)
    return T();
  T topVal = heap[0];
  int index = 0;
  while (true) {
    unsigned int leftChild = 2 * index + 1;
    unsigned int rightChild = 2 * index + 2;
    if (leftChild >= _size) {
      break;
    }
    if (leftChild == (_capacity - 1) || heap[leftChild] >= heap[rightChild]) {
      heap[index] = heap[leftChild];
      index = leftChild;
    } else {
      heap[index] = heap[rightChild];
      index = rightChild;
    }
  }
  _size--;
  while (true) {
    int parentIndex = (index + 1) / 2 - 1;
    if (parentIndex < 0)
      break;
    if (heap[parentIndex] >= heap[index]) {
      heap[index] = T();
      break;
    }
    T temp = T();
    temp = heap[parentIndex];
    heap[parentIndex] = heap[index];
    heap[index] = temp;
    index = parentIndex;
  }
  return topVal;
}

// doubleCapacity
template <class T>
void PriorityQueue<T>::doubleArray() {
  assert(false);
  T* tempArray = new T[_capacity * 2];
  for (int i = 0; i < _capacity; i++) {
    tempArray[i] = heap[i];
  }
  for (int i = _capacity; i < _capacity * 2; i++) {
    tempArray[i] = T();
  }
  delete [] heap;
  _capacity *= 2;
  heap = tempArray;
}

// clear
template <class T>
void PriorityQueue<T>::clear() {
  for (int i = 0; i < _capacity; i++) {
    heap[i] = T();
  }
  _size = 0;
}

#endif /* FayeStevenLab11PriorityQueue_h */
