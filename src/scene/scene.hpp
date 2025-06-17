#pragma once

#include "raylib.h"

#include "../object/hero.hpp"

class Scene {

public:
    Hero m_hero;
    Texture m_Background;

public:
    Scene();
    virtual ~Scene() = default;

    virtual void draw();
    virtual void update();

};