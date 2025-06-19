#pragma once

#include "raylib.h"

#include "object.hpp"
#include "../core/debug.hpp"

#define WALL_COLOR Color(130, 130, 130, 200)

class Wall : public Object {

public:
    Rectangle m_body;
    bool m_isRight;

public:
    Wall(Vector2 position, Vector2 size, bool isRight);

    Wall* getPtr() { return this; }

    void update() override;
    void draw()   override;

};
