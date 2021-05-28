#include "myvector.h"

MyVector::MyVector()
{
    for (unsigned i = 0; i < 3; ++i){
         m_vector[i] = 0.0;
    }
    m_vector[3] = 1.0;
}

void MyVector::print()const
{
    std::cout<<std::endl;
    for (unsigned i = 0; i< 3; ++i)
        std::cout << m_vector[i] << std::endl;
}

void MyVector::set(double x, double y, double z)
{
    m_vector[0] = x;
    m_vector[1] = y;
    m_vector[2] = z;
}

double &MyVector::operator[](unsigned x)
{
    return m_vector[x];
}

const double& MyVector::operator[] (unsigned x) const
{
    return m_vector[x];
}

MyVector MyVector::operator+(const MyVector &mv) const
{
    MyVector temp;

    for(unsigned i = 0; i < 4; i++)
        temp[i] += m_vector[i] + mv.m_vector[i];

    return temp;}

MyVector MyVector::operator-(const MyVector &mv) const
{
    MyVector temp;

    for(unsigned i = 0; i < 4; i++)
        temp[i] += m_vector[i] - mv.m_vector[i];

    return temp;
}
