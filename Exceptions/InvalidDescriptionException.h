//
// Created by Lorenzo Malavolti on 17/04/2025.
//

#ifndef INVALIDDESCRIPTIONEXCEPTION_H
#define INVALIDDESCRIPTIONEXCEPTION_H
#include <stdexcept>


class InvalidDescriptionException final : public std::invalid_argument {
public:
    InvalidDescriptionException() : std::invalid_argument("Le date non sono valide.") {
    }
};


#endif //INVALIDDESCRIPTIONEXCEPTION_H
