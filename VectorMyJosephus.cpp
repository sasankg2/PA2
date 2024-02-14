#include "VectorMyJosephus.h"
VectorMyJosephus::VectorMyJosephus(int M, int N){
    this->M = M;
    this->N = N;
    currentPos = 0;
    InitializeVector();
}
VectorMyJosephus::~VectorMyJosephus(){
    clear();
}
void VectorMyJosephus::InitializeVector(){
    int line = generateRandomNumber();
    ofstream outFile("vectorResults.log", ios_base::app);
    outFile << "----------**Test VectorMyJosephus**----------" << endl;
    outFile << "M: " << M << " ; " << "N: " << N << " ; " << "Selected Line: " << line << endl;
    outFile << "Original Destinations:" << endl;
    ifstream inputFile("destinations.csv");
    string certain = readCSV(inputFile, line);
    parseLine(certain);
    outFile.close();
}
int VectorMyJosephus::generateRandomNumber() {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % 25 + 1;
}
string VectorMyJosephus::readCSV(ifstream& file, int line){
    file.seekg(std::ios::beg);
    for(int i=0; i<line-1; i++){
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string specific;
    getline(file, specific);
    return specific;
}
void VectorMyJosephus::parseLine(string certain){
    stringstream ss(certain);
    string token;
    int pos=0;
    while (std::getline(ss, token, ';')) {
        if(pos >= N){
            break;
        }
        //cout << token << endl;
        Destination destination(pos, token);
        destinationVector.push_back(destination);
        pos++;
    }
    printAllDestinations();
    
}
void VectorMyJosephus::clear(){

}
int VectorMyJosephus::currentSize(){
    return destinationVector.size();
}
bool VectorMyJosephus::isEmpty(){
    if(currentSize() == 0){
        return true;
    }
    else{
        return false;
    } 
}
Destination VectorMyJosephus::eliminateDestination(){
    Destination dest(0, "");
    if (isEmpty()) {
        cout << "Error, no destinations to eliminate." << endl;
        return dest;
    }
    currentPos = (currentPos + M) % currentSize();
    dest = destinationVector.at(currentPos);

    vector<Destination>::iterator iter = destinationVector.erase(destinationVector.begin() + currentPos);
    if (iter == destinationVector.end()) {
        iter = destinationVector.begin();
    } 
    printAllDestinations();
    return dest;
}
void VectorMyJosephus::printAllDestinations(){
    ofstream outFile("vectorResults.log", ios_base::app);
    vector<Destination>::iterator it;
    for (it = destinationVector.begin(); it != destinationVector.end(); ++it){
        outFile << it->getPosition() << ", " << it->getName() << ", ";
    }
    outFile << endl;
    outFile.close();
}
void VectorMyJosephus::addDestination(Destination destination){
    destinationVector.push_back(destination);
}