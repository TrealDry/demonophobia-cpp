#pragma once

#include "raylib.h"

#include "object.hpp"

#include "../core/sprite_sheet.hpp"
#include "../core/animation.hpp"

#include "../state/custom/hero/include.hpp"

#define ANIM_IDLE     0
#define ANIM_WALK     1
#define ANIM_SIT      2
#define ANIM_HALF_SIT 3
#define ANIM_CRAWL    4

#define ANIM_SIZE 5

#define SPRITE_OFFSET_X 9.f

#define BODY_COLOR Color(230, 41, 55, 100)
#define HITBOX_COLOR Color(230, 41, 55, 100)

class Room;
class Wall;

class Hero : public Object {

public:
    float m_speed = 100.f;

    bool m_move = false;

    bool m_lookRight   = false;
    bool m_lookChanged = false;

    bool  m_collided     = false;
    Wall* m_collidedWall = nullptr;

    Room* m_owner = nullptr;

    Vector2 m_bodyPosition = {500.f, 198.f};
    Vector2 m_bodySize     = {185.f, 256.f};

    Rectangle m_body = {
        m_bodyPosition.x, m_bodyPosition.y,
        m_bodySize.x,     m_bodySize.y
    };

    Vector2 m_hitboxSize = {52.f, 240.f};

    Rectangle m_hitbox = {
        (m_bodyPosition.x + (m_bodySize.x / 2.f)) - (m_hitboxSize.x / 2.f),  // + HITBOX_X_OFFSET
        m_bodyPosition.y + (m_bodySize.y - m_hitboxSize.y),
        m_hitboxSize.x, m_hitboxSize.y
    };
    
    // 1110x1280, 6x5 sprite, 185x256
    Texture2D m_texture;
    SpriteSheet m_sprite;
    Animation m_animations[ANIM_SIZE];

    IdleState    m_idleState;
    MoveState    m_moveState;
    HalfSitState m_halfSitState;
    SitState     m_sitState;
    CrawlState   m_crawlState;

    bool m_initCurrentState = true;
    State* m_currentState = nullptr;
    
public:
    Hero();
    
    void setPosition();

    void changeState(State& state);
    void changeLook(bool lookRight);

    void collisionHandler();
    void animationHandler();

    void update() override;
    void draw()   override;

};