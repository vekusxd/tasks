#include "time.hpp"

Time::Time(){
    seconds = 0;
    minutes = 0;
    hours = 0;
}

Time::Time(double hours, double minutes, double seconds){
    if(hours >= 0 && minutes >= 0 && seconds >= 0){
        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
        return;
    }
    throw std::runtime_error("Время не может быть отрицательным");
}

double Time::getHours() const{ return hours; }

double Time::getMinutes() const{ return minutes; }

double Time::getSeconds() const{ return seconds; }

double Time::getAllSeconds() const{ 
    return hours * 3600 + minutes * 60 + seconds;
}

void Time::convertToMinutes(){
    minutes += hours * 60 + seconds / 60;
}

void Time::convertToHours(){
    hours += minutes / 60 + seconds / 3600;
}

void Time::convertToSeconds(){
    seconds += hours * 3600 + minutes * 60;
}

std::string Time::getString() const{
    std::string result;
    result += std::to_string(static_cast<int>(hours)) + ":" + std::to_string(static_cast<int>(minutes)) + ":" + std::to_string(static_cast<int>(seconds));
    return result;
}

void Time::addHours(double hours){
    if(hours >= 0){
        this->hours += hours;
    }
}

void Time::addMinutes(double minutes){
    if(minutes >= 0){
        this->minutes += minutes;
    }
}

void Time::addSeconds(double seconds){
    if(seconds >= 0){
        this->seconds += seconds;
    }
}

Time Time::operator+(const Time& other){
    return Time(hours + other.hours, minutes + other.minutes, seconds + other.seconds);
}

Time Time::operator-(const Time& other){
    return Time(hours - other.hours, minutes - other.minutes, seconds - other.seconds);
}

std::ostream& operator<<(std::ostream& out, const Time& other){
    return out << other.getHours() << ":" << other.getMinutes() << ":" << other.getSeconds();
}

bool Time::operator==(const Time& other) const{
    return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
}


void Time::setHours(double hours){
    if(hours >= 0){
        this->hours = hours;
    }
}

void Time::setMinutes(double minutes){
    if(minutes >= 0){
        this->minutes = minutes;
    }
}

void Time::setSeconds(double seconds){
    if(seconds >= 0){
        this->seconds = seconds;
    }
}
