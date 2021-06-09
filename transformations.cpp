#include "transformations.h"
#include <cmath>

myMatrix setRotation(double alpha_x, double alpha_y, double alpha_z)
{
    return setRotationX(alpha_x) * setRotationY(alpha_y) * setRotationZ(alpha_z);
}

myMatrix setRotationX(double alpha)
{
    myMatrix data;
    alpha = alpha * pi / 180.0;
    data[0][0] = 1.0;
    data[1][1] = data[2][2] = cos(alpha);
    data[1][2] = -sin(alpha);
    data[2][1] = -data[1][2];

    return data;
}

myMatrix setRotationY(double alpha)
{
    myMatrix data;
    alpha = alpha * pi / 180.0;
    data[1][1] = 1.0;
    data[0][0] = data[2][2] = cos(alpha);
    data[2][0] = -sin(alpha);
    data[0][2] = sin(alpha);

    return data;
}

myMatrix setRotationZ(double alpha)
{
    myMatrix data;
    alpha = alpha * pi / 180.0;
    data[2][2] = 1.0;
    data[0][0] = data[1][1] = cos(alpha);
    data[0][1] = -sin(alpha);
    data[1][0] = sin(alpha);

    return data;
}

myMatrix setTranslation(double width, double height)
{
    myMatrix data;

    for (int i = 0; i < 4; ++i)
        data[i][i] = 1.0;

    data[0][3] = width;
    data[1][3] = height;
    data[2][3] = 0;

    return data;
}

myMatrix setScale(double scale)
{
    myMatrix data;

    data[0][0] = data[1][1] = data[2][2] = scale;

    return data;
}

myMatrix setPerspective()
{
    myMatrix data;

    for (int i = 0; i < 3; ++i)
        data[i][i] = 1.0;

    data[3][2] = 0.00015;

    return data;
}

