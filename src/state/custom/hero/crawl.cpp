#include "crawl.hpp"
#include "../../../object/hero.hpp"

void CrawlState::movementHandler() {
    if (IsKeyDown(KEY_D)) {
        m_owner->changeLook(true);
        m_owner->m_bodyPosition.x += (m_owner->m_speed / 2.f) * GetFrameTime();
    } else if (IsKeyDown(KEY_A)) {
        m_owner->changeLook(false);
        m_owner->m_bodyPosition.x -= (m_owner->m_speed / 2.f) * GetFrameTime();
    } else {
        m_owner->m_move = false;
        return;
    }

    m_owner->m_move = true;
    m_owner->setPosition();
}

void CrawlState::playAnimation() {
    if (m_animIsPlaying) return;

    m_owner->m_sprite.changeFrame(9);
    m_owner->m_animations[ANIM_CRAWL].play();

    m_animIsPlaying = true;
}

void CrawlState::enter() {}

void CrawlState::exit() {
    m_animIsPlaying = false;
    m_owner->m_animations[ANIM_CRAWL].stop();
}

void CrawlState::update() {
    movementHandler();
    m_owner->collisionHandler();

    if (m_owner->m_collided) {
        m_owner->changeState(m_owner->m_sitState);
        return;
    }

    if (!m_owner->m_move) {
        if (IsKeyDown(KEY_S)) {
            m_owner->changeState(m_owner->m_sitState);
        } else {
            m_owner->changeState(m_owner->m_idleState);
        }

        return;
    }

    playAnimation();
}
