#include "Point.h"
#include "ArrayPoint.h"
#include <vector>

#ifndef POST_TRAITEMENT_FUNCTIONS_H
#define POST_TRAITEMENT_FUNCTIONS_H

#endif //POST_TRAITEMENT_FUNCTIONS_H

double distanceCalculation(double long1, double lat1, double long2, double lat2);
double convertDegreesToRadians(double degrees);
void lambdasCreation(ArrayPoint *arrayPoint, std::vector<ArrayPoint> *vector, double lambda);
void displayLambdas(std::vector<ArrayPoint> *vector);
void makeMedian(std::vector<ArrayPoint> * lambdasContainer, std::vector<Point> *arrayMediane);
void displayVectorPoint(std::vector<Point> *vector);
