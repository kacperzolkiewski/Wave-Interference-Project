#pragma once
#include <array>
#include "myVector.h"

class myMatrix
{
public:
    myMatrix();

    std::array<double, 4>& operator[] (unsigned index);

    std::array<double, 4> operator[] (unsigned index) const;

    myMatrix operator* (const myMatrix& obj) const;

    myVector operator* (const myVector& obj) const;


public:
    std::array<std::array<double, 4>, 4> data;
};
