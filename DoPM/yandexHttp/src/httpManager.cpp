#include "../include/httpManager.hpp"
#include <QDebug>

void hexchar(unsigned char c, unsigned char &hex1, unsigned char &hex2)
{
    hex1 = c / 16;
    hex2 = c % 16;
    hex1 += hex1 <= 9 ? '0' : 'a' - 10;
    hex2 += hex2 <= 9 ? '0' : 'a' - 10;
}

std::string urlencode(std::string s)
{
    const char *str = s.c_str();
    std::vector<char> v(s.size());
    v.clear();
    for (size_t i = 0, l = s.size(); i < l; i++)
    {
        char c = str[i];
        if ((c >= '0' && c <= '9') ||
            (c >= 'a' && c <= 'z') ||
            (c >= 'A' && c <= 'Z') ||
            c == '-' || c == '_' || c == '.' || c == '!' || c == '~' ||
            c == '*' || c == '\'' || c == '(' || c == ')')
        {
            v.push_back(c);
        }
        else if (c == ' ')
        {
            v.push_back('+');
        }
        else
        {
            v.push_back('%');
            unsigned char d1, d2;
            hexchar(c, d1, d2);
            v.push_back(d1);
            v.push_back(d2);
        }
    }

    return std::string(v.cbegin(), v.cend());
}



Cords httpManager::getCords(const QString& city){
    cpr::Response res = cpr::Get(cpr::Url{"https://catalog.api.2gis.com/3.0/items/geocode?q=" + urlencode(city.toStdString()) + "&fields=items.point&key=565c459e-8dbc-4461-b164-8895e6f57013"});

    if(res.status_code != 200){
        qDebug() << "Error!";
        qDebug() << res.status_code;
    }

    nlohmann::json jsonRes = nlohmann::json::parse(res.text);

    Cords result; 
    result.lat = jsonRes["result"]["items"][0]["point"]["lat"];
    result.lon = jsonRes["result"]["items"][0]["point"]["lon"];

    return result;
}

QString httpManager::getNearStations(Cords cords){
    cpr::Response res = cpr::Get(cpr::Url{"https://api.rasp.yandex.net/v3.0/nearest_stations/?apikey=d7187c52-d574-44af-bc14-423872f3a1f8&lat=" + std::to_string(cords.lat) + "&lng=" + std::to_string(cords.lon) + "&distance=10&lang=ru_Ru&format=json"});

     if(res.status_code != 200){
        qDebug() << "Error!";
        qDebug() << res.status_code;
    }

    nlohmann::json jsonRes = nlohmann::json::parse(res.text);


}