#include "simpleFraction.hpp"
#include <iostream>

SimpleFraction::SimpleFraction(){
    numerator = 0;
    denumerator = 0;
}

SimpleFraction::SimpleFraction(int numerator, int denumerator){
    if(denumerator == 0){
        throw std::runtime_error("0 нельзя!");
    }
    this->numerator = numerator;
    this->denumerator = denumerator;
}

void SimpleFraction::setNumerator(int numerator) {this->numerator = numerator; }
void SimpleFraction::setDenominator(int denumerator) {
    if(denumerator == 0) throw std::runtime_error("Знаменатель не может быть равен 0");
    
    this->denumerator = denumerator; 
}
int SimpleFraction::getNumerator() const {return numerator; }
int SimpleFraction::getDenumerator() const {return denumerator; }

double SimpleFraction::getDecimal() const{
    double tempNumerator = numerator;
    double tempDenumerator = denumerator;
    return tempNumerator / tempDenumerator;
}

void SimpleFraction::display(){
    std::cout << this->numerator << "/" << this->denumerator;
}

bool SimpleFraction::operator==(const SimpleFraction& other){
    return this->numerator * other.denumerator == other.numerator * this->denumerator;
}

bool SimpleFraction::operator>(const SimpleFraction& other){
    return this->numerator * other.denumerator > other.numerator * this->denumerator;
}

bool SimpleFraction::operator<(const SimpleFraction& other){
    return this->numerator * other.denumerator < other.numerator * this->denumerator;
}

bool SimpleFraction::operator<=(const SimpleFraction& other){
    return this->numerator * other.denumerator <= other.numerator * this->denumerator;
}

bool SimpleFraction::operator>=(const SimpleFraction& other){
    return this->numerator * other.denumerator >= other.numerator * this->denumerator;
}

SimpleFraction SimpleFraction::mult(const SimpleFraction& other){
    SimpleFraction result;
   
    result.numerator = this->numerator * other.numerator;
    result.denumerator = this->denumerator * other.denumerator;
    return result;
}

SimpleFraction SimpleFraction::div(const SimpleFraction& other){
    SimpleFraction result;
   
    result.numerator = this->numerator * other.denumerator;
    result.denumerator = this->denumerator * other.numerator;
    return result;
}

SimpleFraction SimpleFraction::add(const SimpleFraction& other){
    SimpleFraction result;

    if(this->denumerator == other.denumerator){
        result.numerator = this->numerator + other.numerator;
        result.denumerator = this->denumerator;
        return result;
    }

    result.numerator = this->numerator * other.denumerator + this->denumerator * other.numerator;
    result.denumerator = this->denumerator * other.denumerator;
    return result;
}

SimpleFraction SimpleFraction::sub(const SimpleFraction& other){
    SimpleFraction result;

    if(this->denumerator == other.denumerator){
        result.numerator = this->numerator - other.numerator;
        result.denumerator = this->denumerator;
        return result;
    }

    result.numerator = this->numerator * other.denumerator - this->denumerator * other.numerator;
    result.denumerator = this->denumerator * other.denumerator;
    return result;
}

SimpleFraction SimpleFraction::add(const SimpleFraction& a, const SimpleFraction& b){
     SimpleFraction result;

    if(a.denumerator == b.denumerator){
        result.numerator = a.numerator + b.numerator;
        result.denumerator = a.denumerator;
        return result;
    }

    result.numerator = a.numerator * b.denumerator + a.denumerator * b.numerator;
    result.denumerator = a.denumerator * b.denumerator;
    return result;
}

SimpleFraction SimpleFraction::sub(const SimpleFraction& a, const SimpleFraction& b){
     SimpleFraction result;

    if(a.denumerator == b.denumerator){
        result.numerator = a.numerator - b.numerator;
        result.denumerator = a.denumerator;
        return result;
    }

    result.numerator = a.numerator * b.denumerator - a.denumerator * b.numerator;
    result.denumerator = a.denumerator * b.denumerator;
    return result;
}

SimpleFraction SimpleFraction::mult(const SimpleFraction& a, const SimpleFraction& b){
    SimpleFraction result;
    result.numerator = a.numerator * b.numerator;
    result.denumerator = a.denumerator * b.denumerator;
    return result;
}

SimpleFraction SimpleFraction::div(const SimpleFraction& a, const SimpleFraction& b){
    SimpleFraction result;
    result.numerator = a.numerator * b.denumerator;
    result.denumerator = a.denumerator * b.numerator;
    return result;
}

SimpleFraction SimpleFraction::operator*(const SimpleFraction& other){
    SimpleFraction result;
    result.numerator = this->numerator * other.numerator;
    result.denumerator = this->denumerator * other.denumerator;
    return result;
}

SimpleFraction SimpleFraction::operator/(const SimpleFraction& other){
    SimpleFraction result;
    result.numerator = this->numerator *  other.denumerator;
    result.denumerator = this->denumerator * other.numerator;
    return result;
}

SimpleFraction SimpleFraction::operator+(const SimpleFraction& other){
    SimpleFraction result;
    if(this->denumerator == other.denumerator){
        result.denumerator = this->denumerator;
        result.numerator = this->numerator + other.numerator;
        return result;
    }
    result.denumerator = this->denumerator * other.denumerator;
    result.numerator = this->numerator * other.denumerator + other.numerator * this->denumerator;
    return result;
}

SimpleFraction SimpleFraction::operator-(const SimpleFraction& other){
    SimpleFraction result;
    if(this->denumerator == other.denumerator){
        result.denumerator = this->denumerator;
        result.numerator = this->numerator - other.numerator;
        return result;
    }
    result.denumerator = this->denumerator * other.denumerator;
    result.numerator = this->numerator * other.denumerator - other.numerator * this->denumerator;
    return result;
}


















