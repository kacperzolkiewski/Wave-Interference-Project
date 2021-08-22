#pragma once
#include "myMatrix.h"

const double pi = 3.14159265359;

myMatrix setRotation(double alpha_x, double alpha_y, double alpha_z);
myMatrix setRotationX(double alpha);
myMatrix setRotationY(double alpha);
myMatrix setRotationZ(double alpha);
myMatrix setTranslation(double width, double height);
myMatrix setScale(double scale);
myMatrix setPerspective();



