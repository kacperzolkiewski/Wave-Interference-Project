#include "matrix.h"

Matrix::Matrix()
{
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            m_matrix[i][j] = 0.0;
        }
    }

    m_matrix[3][3] = 1.0;
}

void Matrix::print() const
{

}

double *Matrix::operator[](unsigned x)
{
    return m_matrix[x];
}

Matrix Matrix::operator*(const Matrix &) const
{
    Matrix temp;

    return temp;
}

MyVector Matrix::operator* (const MyVector&) const
{
    MyVector temp;

    return temp;
}
