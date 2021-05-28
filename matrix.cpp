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
    for (int i = 0; i < 4; ++i){

        for (int j = 0; j < 4; ++j){
         std::cout << m_matrix[i][j] << " ";
        }

        std::cout << std::endl;
    }
}

double *Matrix::operator[](unsigned x)
{
    return m_matrix[x];
}

Matrix Matrix::operator*(const Matrix &mx) const
{
    Matrix temp;

    for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
           temp[i][j] = 0.0;
           for (int k = 0; k < 4; ++k)
              temp[i][j] += m_matrix[i][k] * mx.m_matrix[k][j];
           }
    }

    return temp;
}

MyVector Matrix::operator* (const MyVector &mv) const
{
    MyVector temp;

    for (unsigned i = 0; i < 4; ++i){
      temp[i] = 0.0;
      for (unsigned j = 0; j < 4; ++j)
          temp[i] += m_matrix[i][j]*mv[j];
    }


    return temp;
}
