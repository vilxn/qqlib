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

    //Vector2 operators
    Vector2 operator + (const Vector2& v0, const Vector2& v1){
        return (Vector2){v0.x + v1.x, v0.y + v1.y};
    }

    Vector2 operator - (const Vector2& v0, const Vector2& v1){
        return (Vector2){v0.x - v1.x, v0.y - v1.y};
    }

    Vector2 operator * (const Vector2& v0, const float f1){
        return (Vector2){v0.x * f1, v0.y * f1};
    }

    Vector2 operator / (const Vector2& v0, const float f1){
        return (Vector2){v0.x / f1, v0.y / f1};
    }

    //Vector3 operators
    Vector3 operator + (const Vector3& v0, const Vector3& v1){
        return (Vector3){v0.x + v1.x, v0.y + v1.y, v0.z + v1.z};
    }

    Vector3 operator - (const Vector3& v0, const Vector3& v1){
        return (Vector3){v0.x - v1.x, v0.y - v1.y, v0.z - v1.z};
    }

    Vector3 operator * (const Vector3& v0, const float f1){
        return (Vector3){v0.x * f1, v0.y * f1, v0.z * f1};
    }

    Vector3 operator / (const Vector3& v0, const float f1){
        return (Vector3){v0.x / f1, v0.y / f1, v0.z / f1};
    }
}
