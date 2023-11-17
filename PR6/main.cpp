#include "MaxNVector.h"
#include "ArrayEmptyException.h"

template<typename T> T getRarestElement(T array[], size_t size){
    if(size == 0){
        throw ArrayEmptyException();
    }else{
        T rarestElement = array[0];
        int counterRarestElement = 0;
        int currentCounter = 0;
        for (int i = 0; i < size; i++) {
            if(array[i] == rarestElement && i != 0){
                continue;
            }
            for (int j = 0; j < size; j++) {
                if(i != 0){
                    if(array[i] == array[j]){
                        currentCounter++;
                    }
                }else{
                    if(array[i] == array[j]){
                        counterRarestElement++;
                    }
                }
            }
            if(currentCounter < counterRarestElement && i != 0){
                rarestElement = array[i];
            }
            currentCounter = 0;
        }
        return rarestElement;
    }
}

int main(){
    MaxNVector<int, 1> maxNVector;

    maxNVector.addElement(9);
    maxNVector.addElement(7);
    maxNVector.addElement(8);
    maxNVector.addElement(10);
    //maxNVector.addElement(9);

    for (int i = 0; i < maxNVector.getSize(); i++) {
        cout << "Element at position " << i << " is " << maxNVector[i] << endl;
    }

    maxNVector.removeAt(0);
    //maxNVector[5];

    cout << "After deleting index 0" << endl;

    for (int i = 0; i < maxNVector.getSize(); i++) {
        cout << "Element at position " << i << " is " << maxNVector[i] << endl;
    }

    cout << "Output made with []-operator at maxNVector[0]: " << maxNVector[0] << endl;

    maxNVector[1] = 200;

    cout << "Output made with []-operator at maxNVector[1] and the value is changed to 200:\n" << maxNVector[1] << endl;

    //int array[] = {};
    //size_t size = 0;
    int array[] = {11, 23,11, 23,4,5, 11};
    size_t size = 7;

    cout << getRarestElement<int>(array, size) << endl;
}