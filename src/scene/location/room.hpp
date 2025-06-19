#pragma once

#include "raylib.h"
#include "array"

#include "../scene.hpp"

#include "../../object/wall.hpp"

#define SCREEN_WIDTH  800.f
#define SCREEN_HEIGHT 600.f

class Hero;

class Room : public Scene {

protected:
    Hero*    m_hero    = nullptr;
    Texture* m_background = nullptr;

    std::array<Wall, 2> m_walls = {
        Wall({0.f, 0.f}, {139.f, SCREEN_HEIGHT}, false),
        Wall({SCREEN_WIDTH - 94.f, 0.f}, {94.f, SCREEN_HEIGHT}, true)
    };

public:
    Room(Hero* hero);
    Room(Hero* hero, Texture* background);

    std::array<Wall, 2>& getWall() { return m_walls; }

    void update() override;
    void draw()   override;

};
