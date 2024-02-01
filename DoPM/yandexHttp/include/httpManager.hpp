#pragma once

#include <cpr/cpr.h>
#include <nlohmann/json.hpp>
#include <QString>
#include <string>


struct Cords{
    std::string lat;
    std::string lon;
};

class httpManager{
public:
    httpManager() = default;

    static Cords getCords(const QString& city);
    static QString getNearStations(Cords cords);
    static QString getSchedule(const QString& from, const QString& to);

};