#include "MaxNVector.h"

int main(){
    MaxNVector<int, 2> maxNVector;

    maxNVector.addElement(9);
    maxNVector.addElement(7);
    maxNVector.addElement(8);
    maxNVector.addElement(10);

    for (int i = 0; i < maxNVector.getSize(); i++) {
        cout << "Element at position " << i << " is " << maxNVector[i] << endl;
    }

    maxNVector.removeAt(0);

    cout << "After deleting index 0" << endl;

    for (int i = 0; i < maxNVector.getSize(); i++) {
        cout << "Element at position " << i << " is " << maxNVector[i] << endl;
    }

    cout << "Output made with []-operator at maxNVector[0]: " << maxNVector[0] << endl;

    maxNVector[1] = 200;

    cout << "Output made with []-operator at maxNVector[1] and the value is changed to 200:\n" << maxNVector[1] << endl;
}