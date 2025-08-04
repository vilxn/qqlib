#include <math/qmath.h>

namespace qmath {

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

    Vector2& Vector2::operator += (const Vector2& v){
        x += v.x;
        y += v.y;

        return *this;
    }

    Vector2& Vector2::operator -= (const Vector2& v){
        x -= v.x;
        y -= v.y;

        return *this;
    }

    Vector2& Vector2::operator *= (const float& f){
        x *= f;
        y *= f;

        return *this;
    }

    Vector2& Vector2::operator /= (const float& f){
        x /= f;
        y /= f;

        return *this;
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

    Vector3& Vector3::operator += (const Vector3& v) {
        return *this = *this + v;
    }

    Vector3& Vector3::operator -= (const Vector3& v) {
        return *this = *this - v;
    }

    Vector3& Vector3::operator *= (const float& f) {
        return *this = *this * f;
    }

    Vector3& Vector3::operator /= (const float& f) {
        return *this = *this / f;
    }

    std::ostream& operator << (std::ostream& os, const qmath::Vector3& v) {
        return os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    }


    //Vector4 operators
    float& Vector4::operator[](const int index){
        if(index >= 4 || index < 0){
            std::cout << "out of bound\n";
            exit(0);
        }

        switch(index){
            case 0: return x; break;
            case 1: return y; break;
            case 2: return z; break;
            case 3: return w; break;
                default:
                std::cout << "out of bound\n"; break;
        }

        return x;
    }


    //Matrix operators
    float* Matrix::operator[](int index){
        if(index >= 4){
            std::cout << "out of bound";
            exit(0);
        }

        index *= 4;
        return (array + index);
    }

    std::ostream& operator << (std::ostream& os, const qmath::Matrix& mat){
        return os << mat.ToString();
    }


}
