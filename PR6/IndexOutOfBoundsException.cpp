#include "IndexOutOfBoundsException.h"

const char *IndexOutOfBoundsException::what() const throw() {
    return "The index is out of bounds for this vector!";
}
