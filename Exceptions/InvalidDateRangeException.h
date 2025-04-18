//
// Created by Lorenzo Malavolti on 17/04/2025.
//

#ifndef INVALIDDATERANGE_H
#define INVALIDDATERANGE_H
#include <stdexcept>


class InvalidDateRangeException : public std::out_of_range {
public:
    InvalidDateRangeException() : std::out_of_range("La data di fine deve essere successiva alla data di inizio.") {
    }
};



#endif //INVALIDDATERANGE_H
