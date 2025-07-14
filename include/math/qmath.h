#pragma once
#include <iostream>

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
    };

    class Matrix{
    private:
        float array[16]{};

    public:
        Matrix();

        Matrix(float value);
        
        void Print();
        
        float* operator[](int index);
        
        Vector4 Multiply(Vector4& vec);

        Matrix Multiply(const Matrix& mat);

        void Translate(float x, float y, float z);

        void Scale(float x, float y, float z);

        const float* GetPointer() const;
    };
}


