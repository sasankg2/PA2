#ifndef DESTINATION_H
#define DESTINATION_H
#include <iostream>
using namespace std;
class Destination{
    public:
        Destination(int postition, string name);
        int getPosition();
        string getName();
        ~Destination();
        void printPosition();
        void printDestinationName();
    private:
        int position;
        string name;
};
#endif // DESTINATION_H