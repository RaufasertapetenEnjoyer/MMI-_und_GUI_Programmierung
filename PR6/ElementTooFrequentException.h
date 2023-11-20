#ifndef MMI_GUI_PROGRAMMIERUNG_ELEMENTTOOFREQUENTEXCEPTION_H
#define MMI_GUI_PROGRAMMIERUNG_ELEMENTTOOFREQUENTEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class ElementTooFrequentException : public exception {
public:
    virtual const char* what() const noexcept;
};


#endif //MMI_GUI_PROGRAMMIERUNG_ELEMENTTOOFREQUENTEXCEPTION_H
