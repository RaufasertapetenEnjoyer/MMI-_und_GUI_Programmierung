#ifndef MMI_GUI_PROGRAMMIERUNG_INDEXOUTOFBOUNDSEXCEPTION_H
#define MMI_GUI_PROGRAMMIERUNG_INDEXOUTOFBOUNDSEXCEPTION_H

#include <iostream>
#include <exception>

using namespace std;

class IndexOutOfBoundsException : public exception {
public:
    virtual const char* what() const noexcept;
};


#endif //MMI_GUI_PROGRAMMIERUNG_INDEXOUTOFBOUNDSEXCEPTION_H
