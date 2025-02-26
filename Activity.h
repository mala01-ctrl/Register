//
// Created by Lorenzo Malavolti on 26/02/2025.
//

#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <string>



class Activity {

public:
    Activity(const std::string &description, const std::string& startDateTime, const std::string& endDateTime, int id);

    int getId() const{
        return id;
    }

    std::string getDescription() const {
        return description;
    }

    std::string getStartDateTime() const {
        return startDateTime;
    }

    std::string getEndDateTime() const {
        return endDateTime;
    }

private:
    int id;
    std::string description;
    std::string startDateTime;
    std::string endDateTime;
};



#endif //ACTIVITY_H
