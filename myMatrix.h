#pragma once
#include "myVector.h"

class myMatrix
{
public:
    myMatrix();

    std::vector<double>& operator[](unsigned index);
    std::vector<double> operator[](unsigned index) const;
    myMatrix operator*(const myMatrix& obiect) const;
    myVector operator*(const myVector& obiect) const;
public:
    std::vector<std::vector<double>> data;
};
