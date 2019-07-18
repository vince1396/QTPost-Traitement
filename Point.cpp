#include "Point.h"
#include <iostream>
#include <ostream>
#include <iomanip>
#include <math.h>

// =====================================================================================================================
// CONSTRUCTORS
Point::Point() : mHour(0), mMinute(0), mSecond(0), mMs(0), mLong(0.0), mLat(0.0),mF1(0.0), mF2(0.0), mF3(0.0),
                 mF4(0.0), mF5(0.0), mF6(0.0), mDistanceCumulee(0.0), mRssi(0.0) {}

Point::Point(int hour,
             int minute,
             int second,
             int ms,
             double m_long,
             double lat,
             double f1,
             double f2,
             double f3,
             double f4,
             double f5,
             double f6,
             double rssi) :
             mHour(hour),
             mMinute(minute),
             mSecond(second),
             mMs(ms),
             mLong(m_long),
             mLat(lat),
             mF1(f1),
             mF2(f2),
             mF3(f3),
             mF4(f4),
             mF5(f5),
             mF6(f6),
             mDistanceCumulee(0),
             mRssi(rssi){}

// =====================================================================================================================
// DESTRUCTORS

Point::~Point() = default;
// =====================================================================================================================

// =====================================================================================================================
// ========== GETTERS ==========
int    Point::getHour()   const { return mHour; }
int    Point::getMinute() const { return mMinute; }
int    Point::getSecond() const { return mSecond; }
int    Point::getMs()     const { return mMs; }
double Point::getLong()   const { return mLong; }
double Point::getLat()    const { return mLat; }
double Point::getF1()     const { return mF1; }
double Point::getF2()     const { return mF2; }
double Point::getF3()     const { return mF3; }
double Point::getF4()     const { return mF4; }
double Point::getF5()     const { return mF5; }
double Point::getF6()     const { return mF6; }
double Point::getDistanceCumulee() const { return mDistanceCumulee; }
double Point::getRssi() const { return mRssi; }
double Point::getDistanceMetre() { return this->getDistanceCumulee() * 1000; }

// =====================================================================================================================
// =====================================================================================================================
// ========== SETTERS ==========
void Point::setHour(int hour)      { Point::mHour = hour; }
void Point::setMinute(int minute)  { Point::mMinute = minute; }
void Point::setSecond(int second)  { Point::mSecond = second; }
void Point::setMs(int ms)          { Point::mMs = ms; }
void Point::setLong(double m_long) { Point::mLong = m_long; }
void Point::setLat(double lat)     { Point::mLat = lat; }
void Point::setF1(double f1)       { Point::mF1 = f1; }
void Point::setF2(double f2)       { Point::mF2 = f2; }
void Point::setF3(double f3)       { Point::mF3 = f3; }
void Point::setF4(double f4)       { Point::mF4 = f4; }
void Point::setF5(double f5)       { Point::mF5 = f5; }
void Point::setF6(double f6)       { Point::mF6 = f6; }
void Point::setDistanceCumulee(double distanceCumulee) { Point::mDistanceCumulee = distanceCumulee; }
void Point::setRssi(double rssi) { Point::mRssi = rssi; }

// =====================================================================================================================
void Point::displayPoint()
{
    std::cout << "Time : " << this->getHour();
    std::cout << ":" << this->getMinute();
    std::cout << ":" << this->getSecond();
    std::cout << "." << this->getMs() << std::endl;
    std::cout << std::setprecision(7) << "Long : " << this->getLong() << std::endl;
    std::cout << std::setprecision(7) << "Lat : "  << this->getLat()  << std::endl;
    std::cout << std::setprecision(7) << "F1 : "   << this->getF1()   << std::endl;
    std::cout << "F2 : " << this->getF2() << std::endl;
    std::cout << "F3 : " << this->getF3() << std::endl;
    std::cout << "F4 : " << this->getF4() << std::endl;
    std::cout << "F5 : " << this->getF5() << std::endl;
    std::cout << "F6 : " << this->getF6() << std::endl;
    std::cout << std::fixed << std::setprecision(7) << "Distance cumulee : " << this->getDistanceMetre() << "" << std::endl;
    std::cout << "RSSI : " << this->getRssi() << "\n" << std::endl;
}
