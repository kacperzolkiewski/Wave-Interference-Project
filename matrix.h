#pragma once
#include <array>
#include "vector4.h"

class Matrix
{
public:
    Matrix();

    std::array<double, 4>& operator[] (unsigned index);

    std::array<double, 4> operator[] (unsigned index) const;

    Matrix operator* (const Matrix& obj) const;

    Vector4 operator* (const Vector4& obj) const;


public:
    std::array<std::array<double, 4>, 4> data;
};
