#include "move.hpp"
#include "../../../object/hero.hpp"

void MoveState::movementHandler() {
    if (IsKeyDown(KEY_D)) {
        m_owner->changeLook(true);
        m_owner->m_bodyPosition.x += m_owner->m_speed * GetFrameTime();
    } else if (IsKeyDown(KEY_A)) {
        m_owner->changeLook(false);
        m_owner->m_bodyPosition.x -= m_owner->m_speed * GetFrameTime();
    } else {
        m_owner->m_move = false;
        return;
    }

    m_owner->m_move = true;
    m_owner->setPosition();
}

void MoveState::enter() {
    m_owner->m_sprite.changeFrame(0);
    m_owner->m_animations[ANIM_WALK].play();
}

void MoveState::exit() {
    m_owner->m_animations[ANIM_WALK].stop();
}

void MoveState::update() {
    movementHandler();

    if (m_owner->m_collided) {
        m_owner->changeState(m_owner->m_idleState);
    } else if (!m_owner->m_move) {
        m_owner->changeState(m_owner->m_idleState);
    }
}
