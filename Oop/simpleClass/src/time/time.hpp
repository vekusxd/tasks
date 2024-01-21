#pragma once
#include <string>
#include <iostream>

class Time{

private:
    double seconds;
    double minutes;
    double hours;

public:
    Time();
    Time(double hours, double minutes, double seconds);
    double getHours() const;
    double getMinutes() const;
    double getSeconds() const;
    void setMinutes(double minutes);
    void setHours(double minutes);
    void setSeconds(double minutes);
    double getAllSeconds() const;
    void convertToMinutes();
    void convertToSeconds();
    void convertToHours();
    std::string getString() const;
    void addHours(double hours);
    void addMinutes(double minutes);
    void addSeconds(double seconds);
    
    Time operator+(const Time& other);
    Time operator-(const Time& other);
    bool operator==(const Time& other) const;
    friend std::ostream& operator<<(std::ostream& out, const Time& other);
};