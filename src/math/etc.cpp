#include "math/qmath.h"

namespace qmath {
    float radians(float degrees) {
        return degrees * M_PI / 180.0f;
    }
}