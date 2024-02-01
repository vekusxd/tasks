#pragma once

#include <QString>
#include <nlohmann/json.hpp>


class GeocordObject{
public:
    GeocordObject();
    GeocordObject(nlohmann::json data);
    QString getTitle() const;
    QString getCode() const;
    QString getStationType() const;
    double getDistance() const;
    QString getAll() const;
    
private:
    QString title;
    QString code;
    QString stationTypeName;
    double distance;
};