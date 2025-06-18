#include "wall.hpp"

Wall::Wall(Vector2 position, Vector2 size) :
    m_body({position.x, position.y, size.x, size.y}) {}

void Wall::update() {
    ;
}

void Wall::draw() {
    DrawRectangleRec(m_body, WALL_COLOR);
}

