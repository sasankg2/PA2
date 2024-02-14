#include "ListMyJosephus.h"
ListMyJosephus::ListMyJosephus(int M, int N){
    this->M = M;
    this->N = N;
    currentPos = 0;
}
ListMyJosephus::~ListMyJosephus(){
    clear();
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
