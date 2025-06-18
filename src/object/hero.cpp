#include "hero.hpp"

Hero::Hero() :   
    m_texture{LoadTexture("assets\\sprite\\hero\\hero.png")}, 
    m_sprite{&m_texture, {6.f, 5.f}}, 
    m_animations{
        Animation{&m_sprite, {6.f, 6.f},  1.f, false}, 
        Animation{&m_sprite, {0.f, 5.f},  4.f, false},
        Animation{&m_sprite, {8.f, 8.f},  1.f, false}, 
        Animation{&m_sprite, {7.f, 7.f},  1.f, false},
        Animation{&m_sprite, {9.f, 11.f}, 3.f, true}
    }, m_idleState{this}, m_moveState{this}
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
    m_body.x = m_bodyPosition.x;
    m_body.y = m_bodyPosition.y;
}

void Hero::changeLook(bool lookRight) {
    if (m_lookRight == lookRight) return;

    m_lookRight = lookRight;
    m_lookChanged = true;
}

void Hero::animationHandler() {
    if (m_lookChanged) {
        m_sprite.setFlip(m_lookRight, false);
        m_lookChanged = false;
    }

    for (size_t i = 0; i < ANIM_SIZE; i++) {
        m_animations[i].update();
    }
}

void Hero::update() {
    m_currentState->update();
    animationHandler();
}

void Hero::draw() {
    DrawTextureRec(
        m_texture, m_sprite.getTextureSource(), 
        m_bodyPosition, WHITE
    );
}
