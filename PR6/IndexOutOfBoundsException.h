#ifndef MMI_GUI_PROGRAMMIERUNG_INDEXOUTOFBOUNDSEXCEPTION_H
#define MMI_GUI_PROGRAMMIERUNG_INDEXOUTOFBOUNDSEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception {
    virtual const char* what() const throw();
};


#endif //MMI_GUI_PROGRAMMIERUNG_INDEXOUTOFBOUNDSEXCEPTION_H
