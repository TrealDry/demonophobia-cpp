#pragma once

#include "raylib.h"

#include "object.hpp"

#define WALL_COLOR Color(130, 130, 130, 200)

class Wall : public Object {

public:
    Rectangle m_body;

public:
    Wall(Vector2 position, Vector2 size);

    Wall* getPtr() { return this; }

    void update() override;
    void draw()   override;

};
