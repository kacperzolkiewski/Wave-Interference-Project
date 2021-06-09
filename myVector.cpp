#include "myVector.h"

myVector::myVector(double x, double y, double z)
{
    data[0] = x;
    data[1] = y;
    data[2] = z;
    data[3] = 1.0;
}

void myVector::set(double x, double y, double z)
{
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

double& myVector::operator[](unsigned index)
{
    return data[index];
}

const double& myVector::operator[](unsigned index) const
{
    return data[index];
}

myVector myVector::operator+(const myVector& obiect) const
{
    myVector result;
    for (int i = 0; i < 4; ++i)
        result[i] += data[i] + obiect.data[i];
    return result;
}

myVector myVector::operator-(const myVector& obiect) const
{
    myVector result;
    for (int i = 0; i < 4; ++i)
        result[i] += data[i] - obiect.data[i];
    return result;
}
