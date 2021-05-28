#include "vector4.h"

Vector4::Vector4(double x, double y, double z)
{
    data[0] = x;
    data[1] = y;
    data[2] = z;
    data[3] = 1.0;
}

void Vector4::set(double x, double y, double z)
{
    data[0] = x;
    data[1] = y;
    data[2] = z;
}

double& Vector4::operator[] (unsigned index)
{
    return data[index];
}

const double& Vector4::operator[] (unsigned index) const
{
    return data[index];
}

Vector4 Vector4::operator+ (const Vector4& obj) const
{
    Vector4 result;
    for (int i = 0; i < 4; ++i)
        result[i] += data[i] + obj.data[i];
    return result;
}

Vector4 Vector4::operator- (const Vector4& obj) const
{
    Vector4 result;
    for (int i = 0; i < 4; ++i)
        result[i] += data[i] - obj.data[i];
    return result;
}
