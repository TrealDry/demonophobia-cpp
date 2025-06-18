#include "hero.hpp"

#include "../scene/location/room.hpp"

Hero::Hero() :   
    m_texture{LoadTexture("assets\\sprite\\hero\\hero.png")}, 
    m_sprite{&m_texture, {6.f, 5.f}}, 
    m_animations{
        Animation{&m_sprite, {6.f, 6.f},  1.f, false}, 
        Animation{&m_sprite, {0.f, 5.f},  4.f, false},
        Animation{&m_sprite, {8.f, 8.f},  1.f, false}, 
        Animation{&m_sprite, {7.f, 7.f},  1.f, false},
        Animation{&m_sprite, {9.f, 11.f}, 3.f, true}}, 
    m_idleState{this}, m_moveState{this}, m_halfSitState{this}, 
    m_sitState{this}, m_crawlState{this}
{
    m_currentState = &m_idleState;
    changeState(m_idleState);
}

void Hero::changeState(State& state) {
    m_currentState->exit();
    m_currentState = &state;
    m_currentState->enter();
}

void Hero::setPosition() {
    m_hitbox.x += m_bodyPosition.x - m_body.x;  // прибавляем разницу

    m_body.x = m_bodyPosition.x;
}

void Hero::changeLook(bool lookRight) {
    if (m_lookRight == lookRight) return;

    m_lookRight = lookRight;
    m_lookChanged = true;

    // if (lookRight) {
    //     m_hitbox.x -= HITBOX_X_OFFSET * 2;
    // } else {
    //     m_hitbox.x += HITBOX_X_OFFSET * 2;
    // }
}

void Hero::collisionHandler() {
    for (auto wall: m_owner->getWall()) {
        if (!CheckCollisionRecs(m_hitbox, wall.m_body))
            continue;

        m_collided     = true;
        m_collidedWall = wall.getPtr();
        return;
    }

    m_collided     = false;
    m_collidedWall = nullptr;
}

void Hero::animationHandler() {
    if (m_lookChanged) {
        m_sprite.setFlip(m_lookRight, false);
        m_lookChanged = false;
    }

    for (auto& m_animation : m_animations) {
        m_animation.update();
    }
}

void Hero::update() {
    collisionHandler();
    m_currentState->update();
    animationHandler();
}

void Hero::draw() {
    float spriteOffsetX = (m_lookRight ? 1 : -1) * SPRITE_OFFSET_X;

    DrawTextureRec(
        m_texture, m_sprite.getTextureSource(), 
        {m_bodyPosition.x + spriteOffsetX, m_bodyPosition.y}, WHITE
    );

    DrawRectangleRec(m_body,   BODY_COLOR);
    DrawRectangleRec(m_hitbox, HITBOX_COLOR);
}
