#include "VectorMyJosephus.h"
VectorMyJosephus::VectorMyJosephus(int M, int N){
    this->M = M;
    this->N = N;
    currentPos = 0;
}
VectorMyJosephus::~VectorMyJosephus(){
    clear();
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
    vector<Destination>::iterator iter = destinationVector.begin();
    advance(iter, currentPos);
    dest = *iter;

    iter = destinationVector.erase(iter);
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