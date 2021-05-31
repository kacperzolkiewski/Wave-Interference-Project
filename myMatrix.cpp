#include "myMatrix.h"

myMatrix::myMatrix()
{
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            data[i][j] = 0.0;
    data[3][3] = 1.0;
}

std::array<double, 4>& myMatrix::operator[] (unsigned index)
{
    return data[index];
}

std::array<double, 4> myMatrix::operator[] (unsigned index) const
{
    return data[index];
}

myMatrix myMatrix::operator* (const myMatrix& obj) const
{
    myMatrix result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < 4; ++k)
                result[i][j] += data[i][k] * obj.data[k][j];
        }
    }
    return result;
}

myVector myMatrix::operator* (const myVector& obj) const
{
    myVector result;
    for (int i = 0; i < 4; ++i) {
        result[i] = 0.0;
        for (int j = 0; j < 4; ++j)
            result[i] += data[i][j] * obj[j];
    }
    return result;
}