#include "math/qmath.h"
#include <iostream>
#include <cmath>

namespace qmath{
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

    Vector2& Vector2::operator *= (const float f){
        x *= f;
        y *= f;

        return *this;
    }

    Vector2& Vector2::operator /= (const float f){
        x /= f;
        y /= f;

        return *this;
    }

    float& Vector4::operator[](int index){
        if(index >= 4 || index < 0){
            std::cout << "out of bound";
            exit(0);
        }
        
        switch(index){
            case 0: return x; break;
            case 1: return y; break;
            case 2: return z; break;
            case 3: return w; break;
        }
        
        return x;
    }

    void Vector4::Print(){
        std::cout << "Vector4(" << x << ", " << y << ", " << z << ", " << w << ")\n";
    }

    Matrix::Matrix(){
        for(int i = 0; i < 4; i++){
            array[i * 4 + i] = 1.0f; 
        }
    }

    Matrix::Matrix(float value){
        for(int i = 0; i < 16; i++){
            array[i] = value;
        }
    }

    void Matrix::Print(){
        for(int i = 0; i < 16; i++){
            std::cout << array[i] << " ";
            if((i + 1) % 4 == 0) std::cout << "\n";
        }
    }

    float* Matrix::operator[](int index){
        if(index >= 4){
            std::cout << "out of bound";
            exit(0);
        }
        
        index *= 4;
        return (array + index);
    }

    Vector4 Matrix::Multiply(Vector4& vec){
        Vector4 res;
        
        for(int i = 0; i < 4; i++){
            float temp = 0;
            
            for(int j = 0; j < 4; j++){
                temp += array[i * 4 + j] * vec[j];
            }
            
            res[i] = temp;
        }
        
        return res;
    }

    Matrix Matrix::Multiply(const Matrix& mat){
        const float* array1 = mat.GetPointer();
        Matrix res(0.0f);

        for (int row = 0; row < 4; row++) 
        {
            for (int col = 0; col < 4; col++) 
            {
                for (int k = 0; k < 4; k++) 
                {
                    res[row][col] += array[4 * row + k] * array1[4 * k + col];
                }
            }
        }

        return res;
    }

    void Matrix::Translate(float x, float y, float z){
        Matrix mat(0.0f);
        for(int i = 0; i < 4; i++) mat[i][i] = 1.0f;

        mat[0][3] = x;
        mat[1][3] = y;
        mat[2][3] = z;

        *this = mat.Multiply(*this);
    }

    void Matrix::Scale(float x, float y, float z){
        Matrix mat(0.0f);

        mat[0][0] = x;
        mat[1][1] = y;
        mat[2][2] = z;
        mat[3][3] = 1.0f;

        *this = mat.Multiply(*this);
    }

    void Matrix::Rotate(int angle, float x, float y, float z){
        Matrix mat(0.0f);

        float angleRad = (float)angle * M_PI / 180.0f;
        float c = cosf(angleRad);
        float s = sinf(angleRad);

        mat[0][0] = (1 - c) * x * x + c;
        mat[0][1] = (1 - c) * x * y - (s * z);
        mat[0][2] = (1 - c) * x * z + (s * y);

        mat[1][0] = (1 - c) * x * y + (s * z);
        mat[1][1] = (1 - c) * y * y + c;
        mat[1][2] = (1 - c) * y * z - (s * x);

        mat[2][0] = (1 - c) * x * z - (s * y);
        mat[2][1] = (1 - c) * y * z + (s * x);
        mat[2][2] = (1 - c) * z * z + c;

        mat[3][3] = 1;

        *this = mat.Multiply(*this);
    }

    void Matrix::RotateX(int angle){
        Matrix mat(0.0f);

        float angleRad = (float)angle * M_PI / 180.0f;
        float c = cosf(angleRad);
        float s = sinf(angleRad);

        mat[0][0] = 1;
        mat[3][3] = 1;

        mat[1][1] = c;
        mat[2][2] = c;

        mat[1][2] = -s;
        mat[2][1] = s;

        *this = mat.Multiply(*this);
    }

    void Matrix::RotateY(int angle){
        Matrix mat(0.0f);

        float angleRad = (float)angle * M_PI / 180.0f;
        float c = cosf(angleRad);
        float s = sinf(angleRad);

        mat[0][0] = c;
        mat[1][1] = 1;
        mat[2][2] = c;
        mat[3][3] = 1;

        mat[0][2] = s;
        mat[2][0] = -s;

        *this = mat.Multiply(*this);
    }

    void Matrix::RotateZ(int angle){
        Matrix mat(0.0f);

        float angleRad = (float)angle * M_PI / 180.0f;
        float c = cosf(angleRad);
        float s = sinf(angleRad);

        mat[0][0] = c;
        mat[1][1] = c;
        mat[2][2] = 1;
        mat[3][3] = 1;

        mat[0][1] = -s;
        mat[1][0] = s;

        *this = mat.Multiply(*this);
    }

    const float* Matrix::GetPointer() const{
        return array;
    }

    std::string Matrix::ToString() const{
        std::string res = "";

        for(int i = 0; i < 4; i++){
            res += "[ "; 
            for(int j = 0; j < 4; j++){
                res += std::to_string(array[i * 4 + j]);
                res += ",\t";
            }
            res += " ]\n";
        }

        return res;
    }
}

std::ostream& operator << (std::ostream &os, const qmath::Matrix &mat){
    return os << mat.ToString();
}

qmath::Vector2 operator + (const qmath::Vector2& v0, const qmath::Vector2& v1){
    return (qmath::Vector2){v0.x + v1.x, v0.y + v1.y};
}

qmath::Vector2 operator - (const qmath::Vector2& v0, const qmath::Vector2& v1){
    return (qmath::Vector2){v0.x - v1.x, v0.y - v1.y};
}

qmath::Vector2 operator * (const qmath::Vector2& v0, const float f1){
    return (qmath::Vector2){v0.x * f1, v0.y * f1};
}

qmath::Vector2 operator / (const qmath::Vector2& v0, const float f1){
    return (qmath::Vector2){v0.x / f1, v0.y / f1};
}




