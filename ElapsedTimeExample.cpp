/*
 * This program demonstrates how to calculate the actual
 * processing time of a part of your program, say the 
 * execution time of function f(). The program uses the 
 * function clock(), the clock_t type, and the constant
 * CLOCKS_PER_SEC defined in the C++ standard library "ctime".
 *
 *	Note: You can also use C's gettimeofday() function for timing, instead of this.
 */
 
// be sure to include <ctime>
#include<ctime>
#include<iostream>
#include <cmath>
using namespace std;
#include "ListMyJosephus.h"
#include "VectorMyJosephus.h"

using namespace std;

void runListJosephusSimulation(int N) {
    // Define the values for N and M
    int M = 3;  // Interval of elimination

    // Instantiate a ListMyJosephus object
    ListMyJosephus listJosephus(M, N);

    // Record the start time
    clock_t start = clock();

    // Run the Josephus simulation until only one destination is left
    while (listJosephus.currentSize() > 1) {
        listJosephus.eliminateDestination();
    }

    // Record the end time
    clock_t end = clock();

    // Calculate the CPU elapsed time in microseconds
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0 * 1000.0;

    // Print the CPU elapsed time in microseconds
    ofstream outputFile("results.log", ios_base::app);
    outputFile << "CPU elapsed time for ListMyJosephus " << " for N:" << N << " in microseconds: " << elapsedTime << endl;
    outputFile.close();
}
void runVectorJosephusSimulation(int N) {
    // Define the values for N and M
    int M = 3;  // Interval of elimination

    // Instantiate a ListMyJosephus object
    VectorMyJosephus vectorJosephus(M, N);

    // Record the start time
    clock_t start = clock();

    // Run the Josephus simulation until only one destination is left
    while (vectorJosephus.currentSize() > 1) {
        vectorJosephus.eliminateDestination();
    }

    // Record the end time
    clock_t end = clock();

    // Calculate the CPU elapsed time in microseconds
    double elapsedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000.0 * 1000.0;

    // Print the CPU elapsed time in microseconds
    ofstream outputFile("results.log", ios_base::app);
    outputFile << "CPU elapsed time for VectorMyJosephus " << " for N:" << N << " in microseconds: " << elapsedTime << endl;
    outputFile.close();
}

int main(int argc, char *argv[]) {
    // Run the Josephus simulation
    for (int i = 2; i <= 10; ++i) {
          int N = pow(2, i);
          if (N <= 1024) {
               runVectorJosephusSimulation(N);
               runListJosephusSimulation(N);
          }      
          else {
               break;
          } 
    }
    return 0;
}