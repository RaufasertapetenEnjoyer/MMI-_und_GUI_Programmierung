#ifndef MMI_GUI_PROGRAMMIERUNG_ELEMENTTOOFREQUENTEXCEPTION_H
#define MMI_GUI_PROGRAMMIERUNG_ELEMENTTOOFREQUENTEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class ElementTooFrequentException : public exception {
    virtual const char* what() const throw();
};


#endif //MMI_GUI_PROGRAMMIERUNG_ELEMENTTOOFREQUENTEXCEPTION_H
