#include "ListMyJosephus.h"
ListMyJosephus::ListMyJosephus(int M, int N){
    this->M = M;
    this->N = N;
    //cout << "M: " << M << " ; " << "N: " << N << endl;
    currentPos = 0;
    InitializeList();
}
ListMyJosephus::~ListMyJosephus(){
    clear();
}
void ListMyJosephus::InitializeList(){
    int line = generateRandomNumber();
    ofstream outFile("ListResults.log", ios_base::app);
    outFile << "----------**Test ListrMyJosephus**----------" << endl;
    outFile << "M: " << M << " ; " << "N: " << N << " ; " << "Selected Line: " << line << endl;
    outFile << "Original Destinations:" << endl;
    ifstream inputFile("destinations.csv");
    string certain = readCSV(inputFile, line);
    parseLine(certain);
    outFile.close();
}
int ListMyJosephus::generateRandomNumber() {
    srand(static_cast<unsigned int>(time(nullptr)));
    return rand() % 25 + 1;
}
string ListMyJosephus::readCSV(ifstream& file, int line){
    file.seekg(std::ios::beg);
    for(int i=0; i<line-1; i++){
        file.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    string specific;
    getline(file, specific);
    return specific;
}
void ListMyJosephus::parseLine(string certain){
    stringstream ss(certain);
    string token;
    int pos=0;
    while (std::getline(ss, token, ';')) {
        if(pos >= N){
            break;
        }
        //cout << token << endl;
        Destination destination(pos, token);
        destinationList.push_back(destination);
        pos++;
    }
    printAllDestinations();
    
}
void ListMyJosephus::clear(){

}
int ListMyJosephus::currentSize(){
    return destinationList.size();
}
bool ListMyJosephus::isEmpty(){
    if(currentSize() == 0){
        return true;
    }
    else{
        return false;
    } 
}
Destination ListMyJosephus::eliminateDestination(){
    Destination dest(0, "");
    if (isEmpty()) {
        cout << "Error, no destinations to eliminate." << endl;
        return dest;
    }
    currentPos = (currentPos + M) % currentSize();
    list<Destination>::iterator iter = destinationList.begin();
    advance(iter, currentPos);
    dest = *iter;

    iter = destinationList.erase(iter);
    if (iter == destinationList.end()) {
        iter = destinationList.begin();
    } 
    printAllDestinations();
    return dest;
}
void ListMyJosephus::printAllDestinations(){
    ofstream outFile("listResults.log", ios_base::app);
    list<Destination>::iterator it;
    for (it = destinationList.begin(); it != destinationList.end(); ++it){
        outFile << it->getPosition() << ", " << it->getName() << ", ";
    }
    outFile << endl;
    outFile.close();
}
void ListMyJosephus::addDestination(Destination destination){
    destinationList.push_back(destination);
}
