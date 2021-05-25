#ifndef MATRIX_H
#define MATRIX_H

#include "myvector.h"

class Matrix
{
public:
    Matrix();

    void print() const;

    double* operator[](unsigned);

    //matrix*matrix
    Matrix operator* (const Matrix&) const;

    MyVector operator* (const MyVector&) const;

private:
    double m_matrix[4][4];
};

#endif // MATRIX_H
