#include "IndexOutOfBoundsException.h"

const char *IndexOutOfBoundsException::what() const noexcept {
    return "The index is out of bounds for this vector!";
}
