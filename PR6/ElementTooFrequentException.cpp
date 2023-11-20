#include "ElementTooFrequentException.h"

const char *ElementTooFrequentException::what() const throw() {
    return "There are too many of the elements in the vector!";
}
