#include <vector>
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <sstream>
#include "Destination.h"
using namespace std;
class VectorMyJosephus{
    public:
        VectorMyJosephus(int M, int N);
        ~VectorMyJosephus();
        void clear();
        int currentSize();
        bool isEmpty();
        Destination eliminateDestination();
        void printAllDestinations();
        void addDestination(Destination destination);
    private:
        int M;
        int N;
        vector<Destination> destinationVector;
        int currentPos;
};