//
// Created by Lorenzo Malavolti on 17/04/2025.
//

#ifndef INVALIDDATEEXCEPTION_H
#define INVALIDDATEEXCEPTION_H
#include <stdexcept>


class InvalidDateException : public std::invalid_argument {
public:
    InvalidDateException() : std::invalid_argument("Le date non sono valide.") {
    }
};


#endif //INVALIDDATEEXCEPTION_H
