#include <math/qmath.h>
namespace qmath{
    Vector3 Normalize(const Vector3& v){
        float length = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

        return v / length;
    }

    Vector3 Cross(const Vector3& v0, const Vector3& v1){
        return (Vector3){
            v0.y * v1.z - v0.z * v1.y,
            v0.z * v1.x - v0.x * v1.z,
            v0.x * v1.y - v0.y * v1.x 
        };
    }
}
