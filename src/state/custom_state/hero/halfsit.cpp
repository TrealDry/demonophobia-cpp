#include "halfsit.hpp"
#include "../../../object/hero.hpp"

void HalfSitState::enter() {
    m_counter = 0.f;

    m_owner->m_sprite.changeFrame(7);
    m_owner->m_animations[ANIM_HALF_SIT].play();
}

void HalfSitState::exit() {
    m_owner->m_animations[ANIM_HALF_SIT].stop();
}

void HalfSitState::update() {
    m_counter += GetFrameTime();

    if (IsKeyReleased(KEY_S)) {
        m_owner->changeState(m_owner->m_idleState);
        return;
    }
    
    if (m_counter >= SIT_TIME) 
        m_owner->changeState(m_owner->m_sitState);
}
