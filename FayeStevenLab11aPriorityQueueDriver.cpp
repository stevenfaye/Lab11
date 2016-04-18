// FayeStevenLab11aPriorityQueueDriver.cpp
// by Steven Faye
// on 4/17/16
// Editor(s) used: Apple Xcode 7.3
// Compiler(s) used: Apple LLVM 7.1
// Lab 11a, Priority Queue Driver

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "FayeStevenLab11PriorityQueue.h"
#include "FayeStevenLab11PriorityQueue.h" // included twice for ifndef test
using namespace std;

// prototypes
void printSig();
template <class T>
void displayQueueInfo(const PriorityQueue<T>&);
//template <class T>
//void displayPQ(const PriorityQueue<T>&); // for debugging

// global constants
const string HR = "---------------\n";
const string bigHR = "\n=========================================\n\n";

int main() {
  printSig();
  cout.setf (ios_base::boolalpha);
  srand((unsigned)time(NULL));
  
  cout << bigHR;
  cout << "Constructor Test\n"
  << "Creating two PriorityQueues:\n"
  << "pQueue has default capacity of 2\n"
  << "pQueue2 is passed a capacity of 20\n"
  << "Also tests size(), capacity(), empty(), and top()\n\n";
  cout << "pQueue\n";
  PriorityQueue<int> pQueue;
  displayQueueInfo(pQueue);
  cout << "\npQueue2\n";
  PriorityQueue<int> pQueue2(20);
  displayQueueInfo(pQueue2);
  cout << bigHR;
  
  cout << "enqueue() Test\n"
  << "Adding 10 random ints to pQueue\n"
  << "Top Value should be largest random int\n\n";
  cout << "pQueue\n";
  for (int i = 0; i < 10; i++) {
    int randNum = rand() % 50 + 1;
    cout << "enqueue: " << randNum << "\n";
    pQueue.enqueue(randNum);
  }
  displayQueueInfo(pQueue);
  cout << bigHR;
  
  cout << "Copy Constructor Test\n"
  << "Copying pQueue to new const PriorityQueue pQueue3\n\n";
  cout << "pQueue3\n";
  const PriorityQueue<int> pQueue3(pQueue);
  displayQueueInfo(pQueue3);
  cout << bigHR;
  
  cout << "Assignment Operator Test\n"
  << "Copying pQueue to pQueue2 via assignment operator\n\n";
  cout << "pQueue2\n";
  pQueue2 = pQueue;
  displayQueueInfo(pQueue2);
  cout << bigHR;
  
  cout << "dequeue() Test\n"
  << "Removing all 10 values from pQueue\n"
  << "As they are removed, they should be outputted high to low\n\n";
  for (int i = 0; i < 10; i++) {
    cout << "dequeue #" << i + 1 << ": " << pQueue.dequeue() << endl;
  }
  cout << "\npQueue\n";
  displayQueueInfo(pQueue);
  cout << bigHR;

  cout << "clear() Test\n"
  << "Clearing all values from pQueue2\n\n";
  cout << "pQueue2 before clear\n";
  displayQueueInfo(pQueue2);
  cout << endl;
  cout << "pQueue2 after clear\n";
  pQueue2.clear();
  displayQueueInfo(pQueue2);
  cout << bigHR;
  
  cout.unsetf (ios_base::boolalpha);
  cout << endl;
}

// *********** function printSig() ***********
// prints my name and assignment information
void printSig() {
  cout << "\tFayeStevenLab11aPriorityQueueDriver.cpp\n"
  << "\tProgrammer: Steven Faye\n"
  << "\tEditor(s) used: Apple Xcode 7.3\n"
  << "\tCompiler(s) used: Apple LLVM 7.1\n"
  << "\tFile: " << __FILE__ << "\n"
  << "\tCompiled: " << __DATE__ << " at " << __TIME__ << "\n"
  << "\tLab 11a, Priority Queue Driver\n" << endl;
}

// *********** function displayQueueInfo() ***********
// prints the size, capacity, empty bool, and top value of a PriorityQueue
template <class T>
void displayQueueInfo(const PriorityQueue<T>& aPQ) {
  cout << HR
  << "Size: " << aPQ.size() << "\n"
  << "Capacity: " << aPQ.capacity() << "\n"
  << "Empty?: " << aPQ.empty() << "\n"
  << "Top Value: " << aPQ.top() << "\n"
  << HR;
}

// *********** function displayPQ() ***********
// DOES NOT WORK unless PriorityQueue.h heap[] is changed to public
//template <class T>
//void displayPQ(const PriorityQueue<T>& aPQ) {
//  for (int i = 0; i < aPQ.capacity(); i++) {
//    if (i < 10)
//      cout << " ";
//    cout << i << " ";
//  }
//  cout << endl;
//  for (int i = 0; i < aPQ.capacity(); i++) {
//    if (aPQ.heap[i] < 10)
//      cout << " ";
//    cout << aPQ.heap[i] << " ";
//  }
//  cout << endl << endl;
//}

