#include "idle.hpp"
#include "../../../object/hero.hpp"

void IdleState::enter() {
    m_owner->m_sprite.changeFrame(6);
    m_owner->m_animations[0].play();
}

void IdleState::exit() {
    m_owner->m_animations[0].stop();
}

void IdleState::update() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D)) {
        m_owner->changeState(m_owner->m_moveState);
    }
}
