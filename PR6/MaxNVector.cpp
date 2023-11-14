#include "MaxNVector.h"

template<typename T, int n>
MaxNVector<T, n>::MaxNVector() {
    m_vector = new vector<T>;
}

template<typename T, int n>
MaxNVector<T, n>::~MaxNVector() {
    delete m_vector;
}

template<typename T, int n>
void MaxNVector<T, n>::addElement(const T& elementToAdd) {
    int sum = 0;
    for (const T& element : m_vector) {
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
const T &MaxNVector<T, n>::removeAt(size_t index) {
    if(index > m_vector->size()){
        throw IndexOutOfBoundsException();
    }else{
        const T& elementToRemove = (*m_vector)[index];

        m_vector->erase(m_vector->begin() + index);

        return elementToRemove;
    }
}

template<typename T, int n>
const T &MaxNVector<T, n>::operator[](int pos) const{
    if(pos > m_vector->size() || pos < 0){
        throw IndexOutOfBoundsException();
    }else{
        return m_vector[pos];
    }
}

template<typename T, int n>
T &MaxNVector<T, n>::operator[](int pos) {
    if(pos > m_vector->size() || pos < 0){
        throw IndexOutOfBoundsException();
    }else{
        return m_vector[pos];
    }
}