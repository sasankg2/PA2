#include "TestListMyJosephus.h"

void TestListMyJosephus(){
    string bigPrint;
    int M = 2, N = 5;
    ListMyJosephus myVector(M, N);
    ofstream outFile("ListResults.log", ios_base::app);
    Destination dest(0, "");
    int counter = 0;
    while(myVector.currentSize() > 1){   
        outFile << "Round # " << counter << endl;
        dest = myVector.eliminateDestination();
        bigPrint += to_string(dest.getPosition()) + ", " + dest.getName() + "\n";
        counter ++;
    }
    outFile << "Order of Elimination:" << endl;
    outFile << bigPrint << endl;
    dest = myVector.eliminateDestination();
    outFile << "Destination Chosen: " << dest.getName() << endl;
    outFile.close();
}
