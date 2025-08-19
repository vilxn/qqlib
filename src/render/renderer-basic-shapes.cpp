#include <render/renderer.h>

void Renderer::DrawRectangle(int posX, int posY, float width, float height, qcore::Color color){
    unsigned int vertixNum = _vertices.size() / 3;

    float horRatio = 2.0f / (float)_windowHeight;
    float verRatio = 2.0f / (float)_windowHeight;

    float x = posX * horRatio - 1.0f;
    float y = 1.0f - posY * verRatio;

    // std::cout << x << " " << y << std::endl;
    float w = width * horRatio;
    float h = height * verRatio;

    _vertices.insert(_vertices.end(), {x, y, 1.0f});
    _vertices.insert(_vertices.end(), {x + w, y, 1.0f});
    _vertices.insert(_vertices.end(), {x + w, y - h, 1.0f});
    _vertices.insert(_vertices.end(), {x, y - h, 1.0f});

    _indices.insert(_indices.end(), {vertixNum, vertixNum + 1, vertixNum + 2});
    _indices.insert(_indices.end(), {vertixNum + 2, vertixNum + 3, vertixNum});
}

void Renderer::DrawCircle(int posX, int posY, int radius, qcore::Color color){
    const int segments = 128;

    unsigned int vertixNum = _vertices.size() / 3;

    float horRatio = 2.0f / (float)_windowHeight;
    float verRatio = 2.0f / (float)_windowHeight;

    float positionX = posX * horRatio - 1.0f;
    float positionY = 1.0f - posY * verRatio;

    _vertices.insert(_vertices.end(), {positionX, positionY, 1.0f});

    long double angleOffset = M_PI * 2 / segments;
    for(unsigned int i = 1; i <= segments; i++){
        float x = cosh(angleOffset * i) * radius * horRatio;
        float y = sinh(angleOffset * i) * radius * verRatio;

        _vertices.insert(_vertices.end(), {positionX + x, positionY - y, 1.0f});

        _indices.push_back(vertixNum + i);
        _indices.push_back(vertixNum + (i == segments ? 1 : i + 1));
        _indices.push_back(vertixNum);
    }
}
