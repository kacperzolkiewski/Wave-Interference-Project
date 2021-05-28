#pragma once

#include "matrix.h"

Matrix set_rotation_x(double alpha);

Matrix set_rotation_y(double alpha);

Matrix set_rotation_z(double alpha);

Matrix set_rotation(double alpha_x, double alpha_y, double alpha_z);

Matrix set_scale(double scale);

Matrix set_perspective();

Matrix set_translation(double width, double height);


