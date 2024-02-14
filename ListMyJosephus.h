#include <list>
#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <fstream>
#include <sstream>
#include "Destination.h"
using namespace std;
class ListMyJosephus{
    public:
        ListMyJosephus(int M, int N);
        ~ListMyJosephus();
        void clear();
        int currentSize();
        bool isEmpty();
        Destination eliminateDestination();
        void printAllDestinations();
        void addDestination(Destination destination);
    private:
        int M;
        int N;
        list<Destination> destinationList;
        int currentPos;
        int generateRandomNumber();
        string readCSV(ifstream& file, int line);
        void parseLine(string certain);
        void InitializeList();
};