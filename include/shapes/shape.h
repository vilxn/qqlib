#pragma once
#include "qcore/qcore.h"

class Shape{
private:    
    qcore::Color _color = Q_WHITE; 

public:
    void SetColor(qcore::Color newColor);

    virtual void Init() = 0;

    virtual void Draw(int posX, int posY, int width, int height) = 0;
};