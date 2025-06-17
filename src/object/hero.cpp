#include "hero.hpp"

void Hero::setPosition()
{
    m_body.x = m_bodyPosition.x;
    m_body.y = m_bodyPosition.y;
}

void Hero::update() {
    static bool heroLookRight = false;

    if (IsKeyDown(KEY_D)) {
        heroLookRight = true;
        m_bodyPosition.x += m_speed * GetFrameTime();
    } else if (IsKeyDown(KEY_A)) {
        heroLookRight = false;
        m_bodyPosition.x -= m_speed * GetFrameTime();
    } else {
        if (!m_animations[ANIM_IDLE].getPlayingStatus()) {
            m_sprite.changeFrame(6);
            m_sprite.flipFrame(heroLookRight, false);
            m_animations[ANIM_WALK].stop();
            m_animations[ANIM_IDLE].play();
        }

        goto skipWalkAnim;
    }

    setPosition();

    if (!m_animations[ANIM_WALK].getPlayingStatus()) {
        m_sprite.changeFrame(0);
        m_sprite.flipFrame(heroLookRight, false);
        m_animations[ANIM_IDLE].stop();
        m_animations[ANIM_WALK].play();
    }

    skipWalkAnim:
    for (size_t i = 0; i < ANIM_SIZE; i++) {
        if (m_animations[i].getFlip(true) != heroLookRight)
            m_animations[i].setFlip(heroLookRight, false);
        
        m_animations[i].update();
    }
}

void Hero::draw() {
    DrawTextureRec(
        m_texture, m_sprite.getTextureSource(), 
        m_bodyPosition, WHITE
    );

    //DrawRectangleRec(m_body, {230, 41, 55, 100});
}
