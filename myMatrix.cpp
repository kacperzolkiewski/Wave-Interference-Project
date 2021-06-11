#include "myMatrix.h"

myMatrix::myMatrix()
{
    data = std::vector<std::vector<double>>(4);
    for (int i = 0; i < 4; ++i) {
        data[i] = std::vector<double>(4);
        for (int j = 0; j < 4; ++j)
            data[i][j] = 0.0;
    }
    data[3][3] = 1.0;
}

std::vector<double>& myMatrix::operator[](unsigned index)
{
    return data[index];
}

std::vector<double> myMatrix::operator[](unsigned index) const
{
    return data[index];
}

myMatrix myMatrix::operator*(const myMatrix& obiect) const
{
    myMatrix result;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            result[i][j] = 0.0;
            for (int k = 0; k < 4; ++k)
                result[i][j] += data[i][k] * obiect.data[k][j];
        }
    }
    return result;
}

myVector myMatrix::operator*(const myVector& obiect) const
{
    myVector result;
    for (int i = 0; i < 4; ++i) {
        result[i] = 0.0;
        for (int j = 0; j < 4; ++j)
            result[i] += data[i][j] * obiect[j];
    }
    return result;
}
