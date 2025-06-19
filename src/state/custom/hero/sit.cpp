#include "sit.hpp"
#include "../../../object/hero.hpp"

void SitState::enter() {
    m_owner->m_sprite.changeFrame(8);
    m_owner->m_animations[ANIM_SIT].play();
}

void SitState::exit() {
    m_owner->m_animations[ANIM_SIT].stop();
    m_owner->changeLook(IsKeyPressed(KEY_D));
}

void SitState::update() {
    if (IsKeyPressed(KEY_A) || IsKeyPressed(KEY_D)) {
        m_owner->changeState(m_owner->m_crawlState);
    } else if (!IsKeyDown(KEY_S) && (!IsKeyDown(KEY_A) || !IsKeyDown(KEY_D))) {
        m_owner->changeState(m_owner->m_idleState);
    }
}
