#include "TestListMyJosephus.h"
int generateListRandomNumber() {
    srand(static_cast<unsigned int>(time(nullptr)));

    return rand() % 25 + 1;
}
string readListCSV(ifstream& file, int line){
    file.seekg(std::ios::beg);
    for(int i=0; i<line-1; i++){
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string specific;
    getline(file, specific);
    return specific;
}
void parseListLine(string certain, ListMyJosephus &dest){
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
void TestListMyJosephus(){
    string bigPrint;
    int M = 2, N = 5;
    ListMyJosephus myList(M, N);
    int line = generateListRandomNumber();
    ifstream inputFile("destinations.csv");
    string certain = readListCSV(inputFile, line);
    parseListLine(certain, myList);
    ofstream outFile("listResults.log");
    outFile << "----------**Test ListMyJosephus**----------" << endl;
    outFile << "M: " << M << " ; " << "N: " << N << " ; " << "Selected Line: " << line << endl;
    outFile << "Original Destinations:" << endl;
    outFile.close();
    myList.printAllDestinations();
    Destination dest(0, "");
    int counter = 1;
    while(myList.currentSize() > 1){   
        outFile.open("listResults.log", ios_base::app);     
        outFile << "Round # " << counter << endl;
        outFile.close();
        dest = myList.eliminateDestination();
        bigPrint += to_string(dest.getPosition()) + ", " + dest.getName() + "\n";
        counter ++;
    }
    outFile.open("listResults.log", ios_base::app);
    outFile << "Order of Elimination:" << endl;
    outFile << bigPrint << endl;
    dest = myList.eliminateDestination();
    outFile << "Destination Chosen: " << dest.getName() << endl;
    outFile.close();
}
