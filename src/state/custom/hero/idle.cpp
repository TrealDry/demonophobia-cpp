#include "idle.hpp"
#include "../../../object/hero.hpp"

void IdleState::enter() {
    m_owner->m_sprite.changeFrame(6);
    m_owner->m_animations[ANIM_IDLE].play();
}

void IdleState::exit() {
    m_owner->m_animations[ANIM_IDLE].stop();
}

void IdleState::update() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D)) {
        m_owner->changeState(m_owner->m_moveState);
    } else if (IsKeyDown(KEY_S)) {
        m_owner->changeState(m_owner->m_halfSitState);
    }
}
