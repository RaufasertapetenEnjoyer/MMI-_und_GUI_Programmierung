#include "MaxNVector.h"

int main(){
    MaxNVector<int, 1> maxNVector;

    maxNVector.addElement(9);
    maxNVector.addElement(9);
    maxNVector.addElement(8);
    maxNVector.addElement(10);

    maxNVector.removeAt(0);

    maxNVector[0];
    maxNVector[0] = 19;
}