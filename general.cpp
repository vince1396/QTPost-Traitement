#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
#include <iomanip>
#include "general.h"
#include "Point.h"

const double pi = 4.0*atan(1.0);
const double rayonTerre = 6356.7523;
const double lambda800  = 3.75; // Mètres
const double lambda900  = 3.33; // Mètres
const double lambda1800 = 1.67; // Mètres
const double lambda2100 = 1.43; // Mètres
const double lambda2300 = 1.30; // Mètres
const double lambda2600 = 1.12; // Mètres

double calculDistance(double long1, double lat1, double long2, double lat2)
{
    double dLong1 = convertDegreesToRadians(long1);
    double dLong2 = convertDegreesToRadians(long2);
    double dLat1 =  convertDegreesToRadians(lat1);
    double dLat2 =  convertDegreesToRadians(lat2);

    double dLat = (dLat2) - (dLat1);
    double dLong = (dLong2) - (dLong1);

    double a = pow(sin((dLat)/2.0),2.0)
               + pow(sin((dLong)/2.0),2.0)
               * cos((dLat1))
               * cos((dLat2));

    double c = 2.0 * asin(sqrt((a)));

    double d = rayonTerre * (c);

    return d;
}

double convertDegreesToRadians(double degrees)
{
    double radians = (degrees) * (M_PI/180);

    return radians;
}

void lambdasCreation(ArrayPoint *arrayPoint, std::vector<ArrayPoint> *vector)
{
    double limit = lambda800;
    std::vector<Point> tempPoint;

    for(int i = 0; i < arrayPoint->getNbElem(); i++)
    {
        if(arrayPoint->getPoint(i).getDistanceMetre() > limit || i >= arrayPoint->getNbElem())
        {
            ArrayPoint grappe(static_cast<int>(tempPoint.size()));
            for(const auto & j : tempPoint)
            {
                grappe.insert(j);
            }
            vector->push_back(grappe);
            tempPoint.clear();
            tempPoint.resize(0);
            tempPoint.push_back(arrayPoint->getPoint(i));
            limit += lambda800;
        }
        else
        {
            tempPoint.push_back(arrayPoint->getPoint(i));
        }
    }
}

void displayLambdas(std::vector<ArrayPoint> *vector)
{
    int j = 1;
    for(auto & i : *vector)
    {
        std::cout << i.getNbElem() << std::endl;
        i.getPoint(0).displayPoint();
        j++;
    }
}

void displayVectorPoint(std::vector<Point> *vector) {

    for(auto &i : *vector)
    {
        i.displayPoint();
    }
}

void makeMediane(std::vector<ArrayPoint> *lambdasContainer, std::vector<Point> *arrayMediane) {

    for(unsigned long i = 1; i < lambdasContainer->size()-2; i++)
    {
        std::vector<ArrayPoint> fourLambdas;
        int size = 0;

        fourLambdas.push_back(lambdasContainer->at(i-1));
        fourLambdas.push_back(lambdasContainer->at(i));
        fourLambdas.push_back(lambdasContainer->at(i+1));
        fourLambdas.push_back(lambdasContainer->at(i+2));

        for(auto & x : fourLambdas)
        {
            size += x.getNbElem();
        }

        int hour   = fourLambdas.at(2).getPoint(0).getHour();
        int minute = fourLambdas.at(2).getPoint(0).getMinute();
        int second = fourLambdas.at(2).getPoint(0).getSecond();
        double lon = fourLambdas.at(2).getPoint(0).getLong();
        double lat = fourLambdas.at(2).getPoint(0).getLat();

        ArrayPoint temp1(size);

        for (auto &j : fourLambdas)
        {
            for(int k = 0; k < j.getNbElem(); k++)
            {
                temp1.insert(j.getPoint(k));
            }
        }

        temp1.quickSort();

        double rssi = temp1.calculMediane().getF1();
        Point pointMedian(hour, minute, second, 0, lon, lat, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, rssi);
        arrayMediane->push_back(pointMedian);
        fourLambdas.clear();
    }
}
