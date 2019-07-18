#include <iostream>
#include "ArrayPoint.h"
#include "general.h"

// =====================================================================================================================
ArrayPoint::ArrayPoint(int max) {

    this->mNbElem = 0;
    this->ArrayPoint::mMax = max;
    this->ArrayPoint::mArray = new Point[max];
}

ArrayPoint::~ArrayPoint() = default;
// =====================================================================================================================
int ArrayPoint::getNbElem() const {
    return this->mNbElem;
}

Point ArrayPoint::getPoint(int i) {

    Point point = mArray[i];
    return point;
}

int ArrayPoint::getMax() {

    return this->mMax;
}
// =====================================================================================================================
void ArrayPoint::insert(const Point &point) {

    this->mArray[this->mNbElem] = point;
    this->mNbElem++;
}

void ArrayPoint::displayArray() {

    for(int i = 0; i < this->mMax; i++)
    {
        std::cout << i << std::endl;
        this->mArray[i].displayPoint();
    }
}

void ArrayPoint::makeDistanceCumulee() {

    for(int i = 0; i < this->mMax; i++)
    {
        double xA = this->mArray[i].getLong();
        double yA = this->mArray[i].getLat();
        double xB = this->mArray[i+1].getLong();
        double yB = this->mArray[i+1].getLat();
        double distance = calculDistance(xA, yA, xB, yB);
        double dc = (distance) + this->mArray[i].getDistanceCumulee();
        this->mArray[i+1].setDistanceCumulee(dc);
    }
}

Point ArrayPoint::calculMediane() {

    int middle = this->getNbElem()/2;
    Point mediane = this->getPoint(middle);

    return mediane;
}
// =====================================================================================================================
void ArrayPoint::quickSort() {

    recQuickSort(0, this->mNbElem-1);
}

void ArrayPoint::recQuickSort(int left, int right) {

    int size1 = right-left+1;
    if(size1 < 10)
    {
        insertionSort(left, right);
    }
    else
    {
        double median = medianOf3(left, right);
        int partition = partitionIt(left, right, median);
        recQuickSort(left, partition-1);
        recQuickSort(partition+1, right);
    }
}

double ArrayPoint::medianOf3(int left, int right) {

    int center = (left+right)/2;

    if(this->mArray[left].getF1() > this->mArray[center].getF1())
        swap(left, center);

    if(this->mArray[left].getF1() > this->mArray[right].getF1())
        swap(left, right);

    if(this->mArray[center].getF1() > this->mArray[right].getF1())
        swap(center, right);

    swap(center, right-1);
    return this->mArray[right-1].getF1();
}

void ArrayPoint::swap(int dex1, int dex2) {

    Point temp = this->mArray[dex1];
    this->mArray[dex1] = this->mArray[dex2];
    this->mArray[dex2] = temp;
}

int ArrayPoint::partitionIt(int left, int right, double pivot) {

    int leftPtr = left;
    int rightPtr = right-1;

    while(true)
    {
        while (this->mArray[++leftPtr].getF1() < pivot)
            ;
        while (this->mArray[--rightPtr].getF1() > pivot)
            ;
        if(leftPtr >= rightPtr)
            break;
        else
            swap(leftPtr, rightPtr);
    }
    swap(leftPtr, rightPtr-1);
    return leftPtr;
}

void ArrayPoint::insertionSort(int left, int right) {

    int in, out;

    for(out = left+1; out <= right; out++)
    {
        Point temp = this->mArray[out];
        in = out;

        while(in > left && this->mArray[in-1].getF1() >= temp.getF1())
        {
            this->mArray[in] = this->mArray[in-1];
            --in;
        }

        this->mArray[in] = temp;
    }
}
// =====================================================================================================================
