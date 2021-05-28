#pragma once
#include <array>

class Vector4
{
public:
    Vector4(double x = 0.0, double y = 0.0, double z = 0.0);

    void set(double x, double y, double z);

    double& operator[] (unsigned index);

    const double& operator[] (unsigned index) const;

    Vector4 operator+ (const Vector4& obj) const;

    Vector4 operator- (const Vector4& obj) const;


private:
    std::array<double, 4> data;
};
