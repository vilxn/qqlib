#pragma once
#include <iostream>
#include <ostream>
#include <string>

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

        const float* GetPointer() const;
    };
}

std::ostream& operator << (std::ostream &os, const qmath::Matrix& mat);

qmath::Vector2 operator + (const qmath::Vector2& v0, const qmath::Vector2& v1);

qmath::Vector2 operator - (const qmath::Vector2& v0, const qmath::Vector2& v1);

qmath::Vector2 operator * (const qmath::Vector2& v0, const float f1);

qmath::Vector2 operator / (const qmath::Vector2& v0, const float f1);




