#pragma once

#include "raylib.h"
#include "spdlog/spdlog.h"

#include "../core/sprite_sheet.hpp"
#include "../core/animation.hpp"

#include "../state/custom_state/hero/include.hpp"

#define ANIM_IDLE     0
#define ANIM_WALK     1
#define ANIM_SIT      2
#define ANIM_HALF_SIT 3
#define ANIM_CRAWL    4

#define ANIM_SIZE 5

class Hero {

public:
    float m_speed = 100.f;

    bool m_move = false;

    bool m_lookRight   = false;
    bool m_lookChanged = false;

    Vector2 m_bodyPosition = {0.f, 200.f};
    Vector2 m_bodySize     = {185.f, 256.f};

    Rectangle m_body = {
        m_bodyPosition.x, m_bodyPosition.y,
        m_bodySize.x,     m_bodySize.y
    };
    
    // 1110x1280, 6x5 sprite, 185x256
    Texture2D m_texture;
    SpriteSheet m_sprite;
    Animation m_animations[ANIM_SIZE];

    IdleState m_idleState;
    MoveState m_moveState;

    bool m_initCurrentState = true;
    State* m_currentState = nullptr;
    
public:
    Hero();
    
    void setPosition();

    void changeState(State& state);
    void changeLook(bool lookRight);

    void movementHandler();
    void animationHandler();
    void update();

    void draw();

};