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
        
        void Print();
    };

    struct Vector3{
        float x;
        float y;
        float z;
    };

    struct Vector2{
        float x;
        float y;

        Vector2& operator += (const qmath::Vector2& v);

        Vector2& operator -= (const qmath::Vector2& v);

        Vector2& operator *= (const float f);

        Vector2& operator /= (const float f);
    };

    class Matrix{
    private:
        float array[16]{};

    public:
        Matrix();

        Matrix(float value);
        
        void Print();
        
        float* operator[](int index);

        std::string ToString() const;
        
        Vector4 Multiply(Vector4& vec);

        Matrix Multiply(const Matrix& mat);

        void Translate(float x, float y, float z);

        void Scale(float x, float y, float z);

        void Rotate(int angle, float x, float y, float z);

        void RotateX(int angle);

        void RotateY(int angle);

        void RotateZ(int angle);

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
}

std::ostream& operator << (std::ostream &os, const qmath::Matrix& mat);






