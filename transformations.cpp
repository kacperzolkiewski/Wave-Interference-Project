#include "transformations.h"
#include <cmath>

const double pi = 3.14159265359;

myMatrix set_rotation_x(double alpha)
{
    myMatrix data;
    alpha = alpha * pi / 180.0;
    data[0][0] = 1.0;
    data[1][1] = data[2][2] = cos(alpha);
    data[1][2] = -sin(alpha);
    data[2][1] = sin(alpha);

    return data;
}

myMatrix set_rotation_y(double alpha)
{
    myMatrix data;
    alpha = alpha * pi / 180.0;
    data[1][1] = 1.0;
    data[0][0] = data[2][2] = cos(alpha);
    data[2][0] = -sin(alpha);
    data[0][2] = sin(alpha);

    return data;
}

myMatrix set_rotation_z(double alpha)
{
    myMatrix data;
    alpha = alpha * pi / 180.0;
    data[2][2] = 1.0;
    data[0][0] = data[1][1] = cos(alpha);
    data[0][1] = -sin(alpha);
    data[1][0] = sin(alpha);

    return data;
}

myMatrix set_rotation(double alpha_x, double alpha_y, double alpha_z)
{
    return set_rotation_x(alpha_x) * set_rotation_y(alpha_y) * set_rotation_z(alpha_z);
}


myMatrix set_scale(double scale)
{
    myMatrix data;

    data[0][0] = scale;
    data[1][1] = scale;
    data[2][2] = scale;

    return data;
}

myMatrix set_perspective()
{
    myMatrix data;

    for (int i = 0; i < 3; ++i)
        data[i][i] = 1.0;

    data[3][2] = 0.00015;

    return data;
}


myMatrix set_translation(double width, double height)
{
    myMatrix data;

    for (int i = 0; i < 4; ++i)
        data[i][i] = 1.0;

    data[0][3] = width;
    data[1][3] = height;
    data[2][3] = 0;

    return data;

}
