#ifndef POST_TRAITEMENT_POINT_H
#define POST_TRAITEMENT_POINT_H

#include <string>
#include <system_error>

class Point {

public:

    Point();
    Point(int hour, int minute, int second, int ms, double mLong, double lat, double f1, double f2, double f3, double f4, double f5, double f6, double rssi);
    ~Point();

    int    getHour() const;
    int    getMinute() const;
    int    getSecond() const;
    int    getMs() const;
    double getLong() const;
    double getLat() const;
    double getF1() const;
    double getF2() const;
    double getF3() const;
    double getF4() const;
    double getF5() const;
    double getF6() const;
    double getRssi() const;
    // =================================================================================================================
    void setHour(int mHour);
    void setMinute(int mMinute);
    void setSecond(int mSecond);
    void setMs(int mMs);
    void setLong(double mLong);
    void setLat(double mLat);
    void setF1(double mF1);
    void setF2(double mF2);
    void setF3(double mF3);
    void setF4(double mF4);
    void setF5(double mF5);
    void setF6(double mF6);
    void setRssi(double mRssi);
    // =================================================================================================================
    void displayPoint();
    double getDistanceCumulee() const;
    void setDistanceCumulee(double mDistanceCumulee);
    double getDistanceMetre();
// =====================================================================================================================
private:

    int mHour;
    int mMinute;
    int mSecond;
    int mMs;

    double mLong;
    double mLat;
    double mF1;
    double mF2;
    double mF3;
    double mF4;
    double mF5;
    double mF6;

    double mDistanceCumulee;
    double mRssi;
};

#endif //POST_TRAITEMENT_POINT_H
