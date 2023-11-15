#ifndef MMI_GUI_PROGRAMMIERUNG_MAXNVECTOR_H
#define MMI_GUI_PROGRAMMIERUNG_MAXNVECTOR_H

#include <vector>
#include <iostream>
#include "ElementTooFrequentException.h"
#include "IndexOutOfBoundsException.h"

using namespace std;

template<typename T, int n> class MaxNVector {
private:
    vector<T>* m_vector;

public:
    MaxNVector();
    ~MaxNVector();

    void addElement(const T& elementToAdd);

    void removeAt(size_t index);

    const T& operator[](int pos) const;

    T& operator[](int pos);

    size_t getSize() const;
};

//TODO: Problem ist, sobald man die Methoden in die .cpp schreibt lässt sich das Programm nicht mehr ausführen und bekommt linking
// Probleme
// aktuelle cmake: PR6/main.cpp PR6/MaxNVector.cpp PR6/ElementTooFrequentException.cpp PR6/IndexOutOfBoundsException.cpp
// wenn funkionen in .h geschrieben, dann funktioniert das Programm

template<typename T, int n>
size_t MaxNVector<T, n>::getSize() const {
    return m_vector->size();
}

template<typename T, int n>
MaxNVector<T, n>::MaxNVector() : m_vector(new vector<T>){}

template<typename T, int n>
MaxNVector<T, n>::~MaxNVector() {
    delete m_vector;
}

template<typename T, int n>
void MaxNVector<T, n>::addElement(const T& elementToAdd) {
    int sum = 0;
    for (int i = 0; i < m_vector->size(); i++) {
        const T& element = (*m_vector)[i];
        if(element == elementToAdd){
            sum++;
        }
    }

    if(sum < n){
        m_vector->push_back(elementToAdd);
    }else{
        throw ElementTooFrequentException();
    }
}

template<typename T, int n>
void MaxNVector<T, n>::removeAt(size_t index) {
    if(index > m_vector->size()){
        throw IndexOutOfBoundsException();
    }else{
        m_vector->erase(m_vector->begin() + index);
    }
}

template<typename T, int n>
const T &MaxNVector<T, n>::operator[](int pos) const{
    if(pos > m_vector->size() || pos < 0){
        throw IndexOutOfBoundsException();
    }else{
        return (*m_vector)[pos];
    }
}

template<typename T, int n>
T &MaxNVector<T, n>::operator[](int pos) {
    if(pos > m_vector->size() || pos < 0){
        throw IndexOutOfBoundsException();
    }else{
        return (*m_vector)[pos];
    }
}



#endif //MMI_GUI_PROGRAMMIERUNG_MAXNVECTOR_H
