#include "TestVectorMyJosephus.h"
void TestVectorMyJosephus(){
    string bigPrint;
    int M = 2, N = 5;
    VectorMyJosephus myVector(M, N);
    ofstream outFile("vectorResults.log", ios_base::app);
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
