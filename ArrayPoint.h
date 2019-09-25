#ifndef POST_TRAITEMENT_ARRAYPOINT_H
#define POST_TRAITEMENT_ARRAYPOINT_H

#include <vector>
#include "Point.h"

// Point container
class ArrayPoint {

public:

    // =================================================================================================================
    explicit ArrayPoint(int max);
    virtual ~ArrayPoint();
    // =================================================================================================================
    int getNbElem() const;
    Point getPoint(int indice);
    int getMax();
    // =================================================================================================================
    void insert(const Point& point);
    void displayArray();
    void makeAccumulatedDistance();
    Point medianCalculation();
    // =================================================================================================================
    void quickSort();
    void recQuickSort(int left, int right);
    double medianOf3(int left, int right);
    void swap(int dex1, int dex2);
    int partitionIt(int left, int right, double pivot);
    void insertionSort(int left, int right);

private:

    int mMax;
    int mNbElem;
    Point *mArray;
};

#endif //POST_TRAITEMENT_ARRAYPOINT_H
