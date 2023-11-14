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

    const T& removeAt(size_t index);

    const T& operator[](int pos) const;

    T& operator[](int pos);
};


#endif //MMI_GUI_PROGRAMMIERUNG_MAXNVECTOR_H
