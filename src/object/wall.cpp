#include "wall.hpp"

Wall::Wall(Vector2 position, Vector2 size, bool isRight) :
    m_body({position.x, position.y, size.x, size.y}), m_isRight(isRight) {}

void Wall::update() {
    ;
}

void Wall::draw() {
    if (Debug::m_debugMode)
        DrawRectangleRec(m_body, WALL_COLOR);
}

