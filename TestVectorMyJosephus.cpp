#include "TestVectorMyJosephus.h"
int generateVectorRandomNumber() {
    srand(static_cast<unsigned int>(time(nullptr)));

    return rand() % 25 + 1;
}
string readVectorCSV(ifstream& file, int line){
    file.seekg(std::ios::beg);
    for(int i=0; i<line-1; i++){
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string specific;
    getline(file, specific);
    return specific;
}
void parseVectorLine(string certain, VectorMyJosephus &dest){
    stringstream ss(certain);
    string token;
    int pos=0;
    while (std::getline(ss, token, ';')) {
        if(pos >= 5){
            break;
        }
        //cout << token << endl;
        Destination destination(pos, token);
        dest.addDestination(destination);
        pos++;
    }
    dest.printAllDestinations();
    
}
void TestVectorMyJosephus(){
    string bigPrint;
    int M = 2, N = 5;
    VectorMyJosephus myVector(M, N);
    int line = generateVectorRandomNumber();
    ifstream inputFile("destinations.csv");
    string certain = readVectorCSV(inputFile, line);
    parseVectorLine(certain, myVector);
    ofstream outFile("results.log");
    outFile << "----------**Test VectorMyJosephus**----------" << endl;
    outFile << "M: " << M << " ; " << "N: " << N << " ; " << "Selected Line: " << line << endl;
    outFile << "Original Destinations:" << endl;
    outFile.close();
    myVector.printAllDestinations();
    Destination dest(0, "");
    int counter = 1;
    while(myVector.currentSize() > 1){   
        outFile.open("vectorResults.log", ios_base::app);     
        outFile << "Round # " << counter << endl;
        outFile.close();
        dest = myVector.eliminateDestination();
        bigPrint += to_string(dest.getPosition()) + ", " + dest.getName() + "\n";
        counter ++;
    }
    outFile.open("vectorResults.log", ios_base::app);
    outFile << "Order of Elimination:" << endl;
    outFile << bigPrint << endl;
    dest = myVector.eliminateDestination();
    outFile << "Destination Chosen: " << dest.getName() << endl;
    outFile.close();
}
