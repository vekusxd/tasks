#include "../include/geocordObject.hpp"
#include <nlohmann/json.hpp>

GeocordObject::GeocordObject() { }

GeocordObject::GeocordObject(nlohmann::json data){
    this->title = QString::fromStdString(data["stations"][0]["title"]);
    this->code = QString::fromStdString(data["stations"][0]["code"]);
    this->stationTypeName = QString::fromStdString(data["stations"][0]["station_type_name"]);
    this->distance = data["stations"][0]["distance"];
}

QString GeocordObject::getTitle() const { return title; }
QString GeocordObject::getCode() const { return code; }
QString GeocordObject::getStationType() const { return stationTypeName; }
double GeocordObject::getDistance() const { return distance; }


QString GeocordObject::getAll() const{
    QString result;
    result += "Название: " + title;
    result += "\nКод: " + code;
    result += "\nТип станции: " + stationTypeName;
    result += "\nДистанция: " + QString::number(distance);
    result += "\n";
    return result;
}

