//
// Created by m.busch on 17.11.2023.
//

#ifndef MMI_GUI_PROGRAMMIERUNG_ARRAYEMPTYEXCEPTION_H
#define MMI_GUI_PROGRAMMIERUNG_ARRAYEMPTYEXCEPTION_H
#include <exception>

using namespace std;

class ArrayEmptyException : public exception{
    virtual const char* what() const throw();
};


#endif //MMI_GUI_PROGRAMMIERUNG_ARRAYEMPTYEXCEPTION_H
