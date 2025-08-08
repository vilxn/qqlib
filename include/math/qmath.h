#pragma once
#include <iostream>
#include <ostream>
#include <string>
#include <cmath>

namespace qmath{
    struct Vector4{
        float x;
        float y;
        float z;
        float w = 1.0f;
        
        float& operator[](int index);
        
        void Print() const;
    };

    struct Vector3{
        float x;
        float y;
        float z;

        Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f) : x(x), y(y), z(z){}

        Vector3& operator += (const Vector3& v);

        Vector3& operator -= (const Vector3& v);

        Vector3& operator *= (const float& f);

        Vector3& operator /= (const float& f);
    };

    struct Vector2{
        float x;
        float y;

        Vector2(float x = 0.0f, float y = 0.0f) : x(x), y(y){}

        Vector2& operator += (const qmath::Vector2& v);

        Vector2& operator -= (const qmath::Vector2& v);

        Vector2& operator *= (const float& f);

        Vector2& operator /= (const float& f);
    };

    class Matrix{
    private:
        float array[16]{};

    public:
        Matrix();

        Matrix(float value);
        
        void Print() const;
        
        float* operator[](int index);

        std::string ToString() const;
        
        Vector4 Multiply(Vector4& vec) const;

        Matrix Multiply(const Matrix& mat) const;

        void Translate(float x, float y, float z);

        void Scale(float x, float y, float z);

        void Rotate(const int &angle, const float &x, const float &y, const float &z);

        void RotateX(const int &angle);

        void RotateY(const int &angle);

        void RotateZ(const int &angle);

        void Perspective(float fov, float aspectRatio, float zNear, float zFar);

        const float* GetPointer() const;
    };

    Vector3 Normalize(const Vector3& v);

    Vector3 Cross(const Vector3& v0, const Vector3& v1);

    //Vector2 operators
    Vector2 operator + (const Vector2& v0, const Vector2& v1);

    Vector2 operator - (const Vector2& v0, const Vector2& v1);

    Vector2 operator * (const Vector2& v0, const float f1);

    Vector2 operator / (const Vector2& v0, const float f1);

    //Vector3 operators
    Vector3 operator + (const Vector3& v0, const Vector3& v1);

    Vector3 operator - (const Vector3& v0, const Vector3& v1);

    Vector3 operator * (const Vector3& v0, const float f1);

    Vector3 operator / (const Vector3& v0, const float f1);

    std::ostream& operator << (std::ostream& os, const qmath::Vector3& v);

    //Matrix operator
    std::ostream& operator << (std::ostream &os, const qmath::Matrix& mat);

    float radians(float degrees);
}








