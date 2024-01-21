#pragma once

class SimpleFraction{
private:
    int numerator;
    int denumerator;

public:
    SimpleFraction();
    SimpleFraction(int numerator, int denumerator);
    void setNumerator(int numerator);
    void setDenominator(int denumerator);
    int getNumerator() const;
    int getDenumerator() const;
    double getDecimal() const;
    void display();
    SimpleFraction add(const SimpleFraction& other);
    SimpleFraction sub(const SimpleFraction& other);
    SimpleFraction mult(const SimpleFraction& other);
    SimpleFraction div(const SimpleFraction& other);
    static SimpleFraction add(const SimpleFraction& a, const SimpleFraction& b);
    static SimpleFraction sub(const SimpleFraction& a, const SimpleFraction& b);
    static SimpleFraction mult(const SimpleFraction& a, const SimpleFraction& b);
    static SimpleFraction div(const SimpleFraction& a, const SimpleFraction& b);
    SimpleFraction operator+(const SimpleFraction& other);
    SimpleFraction operator-(const SimpleFraction& other);
    SimpleFraction operator*(const SimpleFraction& other);
    SimpleFraction operator/(const SimpleFraction& other);
    bool operator==(const SimpleFraction& other);
    bool operator>(const SimpleFraction& other);
    bool operator<(const SimpleFraction& other);
    bool operator>=(const SimpleFraction& other);
    bool operator<=(const SimpleFraction& other);
};