//
// Created by m.busch on 17.11.2023.
//

#include "ArrayEmptyException.h"

const char *ArrayEmptyException::what() const noexcept {
    return "The array is empty!";
}
