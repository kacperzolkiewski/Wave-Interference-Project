#pragma once
#include <array>

class myVector
{
public:
    myVector(double x = 0.0, double y = 0.0, double z = 0.0);

    void set(double x, double y, double z);

    double& operator[] (unsigned index);

    const double& operator[] (unsigned index) const;

    myVector operator+ (const myVector& obj) const;

    myVector operator- (const myVector& obj) const;


private:
    std::array<double, 4> data;
};
