// FayeStevenLab11bPriorityQueueBigOh.cpp
// by Steven Faye
// on 4/17/16
// Editor(s) used: Apple Xcode 7.3
// Compiler(s) used: Apple LLVM 7.1
// Lab 11a, Priority Queue Big Oh Test

#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include "FayeStevenLab11PriorityQueue.h"
using namespace std;

// prototypes
void printSig();

int main() {
  printSig();

  PriorityQueue<int> pQueue(40000);
  cout << "Priority Queue Enqueue Test: \n";
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  int n = 5000;
  clock_t startTime = 0;
  double executionTime = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2) {
    
    // start the timer
    startTime = clock();
    executionTime = 0;
    
    // code to be tested...
    for (int i = 0; i < n; i++) {
      pQueue.enqueue(i + 1);
    }
    
    // end timer
    executionTime = (double)(clock() - startTime)/*/CLOCKS_PER_SEC*/;
    
    // verify operations
    for (int i = 0; i < pQueue.capacity(); i++) {
      int temp = pQueue.top();
      pQueue.dequeue();
      assert(pQueue.top() <= temp);
    }
    
    // calculate big oh
    double actualTime, expectedTime = 0;
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      actualTime = executionTime;
    else if (bigOh == "O(1)")
      expectedTime = actualTime;
    else if (bigOh == "O(log n)")
      expectedTime = log(double(n)) / log(n / factor) * actualTime;
    else if (bigOh == "O(n)")
      expectedTime = factor * actualTime;
    else if (bigOh == "O(n log n)")
      expectedTime = factor * log(double(n)) / log(n / factor) * actualTime;
    else if (bigOh == "O(n squared)")
      expectedTime = factor * factor * actualTime;
    cout << n << " N took " << executionTime << " ticks";
    if (cycle == 0)
      cout << " (Expected: " << bigOh << ")\n";
    else
      cout << " (Expected: " << expectedTime << ")\n";
    
    // reset
    pQueue.clear();
  }
  
  cout << "\nPriority Queue Dequeue Test: \n";
  bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  n = 5000;
  startTime = 0;
  executionTime = 0;
  for (int cycle = 0; cycle < 4; cycle++, n *= 2) {
    
    // populate the pQueue
    for (int i = 0; i < n; i++) {
      pQueue.enqueue(i + 1);
    }
    
    // start the timer
    startTime = clock();
    executionTime = 0;
    
    // code to be tested...
    for (int i = 0; i < n; i++) {
      pQueue.dequeue();
    }

    // end timer
    executionTime = (double)(clock() - startTime)/*/CLOCKS_PER_SEC*/;
    double actualTime, expectedTime = 0;
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      actualTime = executionTime;
    else if (bigOh == "O(1)")
      expectedTime = actualTime;
    else if (bigOh == "O(log n)")
      expectedTime = log(double(n)) / log(n / factor) * actualTime;
    else if (bigOh == "O(n)")
      expectedTime = factor * actualTime;
    else if (bigOh == "O(n log n)")
      expectedTime = factor * log(double(n)) / log(n / factor) * actualTime;
    else if (bigOh == "O(n squared)")
      expectedTime = factor * factor * actualTime;
    cout << n << " N took " << executionTime << " ticks";
    if (cycle == 0)
      cout << " (Expected: " << bigOh << ")\n";
    else
      cout << " (Expected: " << expectedTime << ")\n";
    
    // reset
    pQueue.clear();
  }

  cout << endl;
}

// *********** function printSig() ***********
// prints my name and assignment information
void printSig() {
  cout << "\tFayeStevenLab11bPriorityQueueBigOh.cpp\n"
  << "\tProgrammer: Steven Faye\n"
  << "\tEditor(s) used: Apple Xcode 7.3\n"
  << "\tCompiler(s) used: Apple LLVM 7.1\n"
  << "\tFile: " << __FILE__ << "\n"
  << "\tCompiled: " << __DATE__ << " at " << __TIME__ << "\n"
  << "\tLab 11a, Priority Queue Big Oh Test\n" << endl;
}
