#pragma once

#include "raylib.h"
#include "spdlog/spdlog.h"

#include "../core/sprite_sheet.hpp"
#include "../core/animation.hpp"

#define ANIM_IDLE 0
#define ANIM_WALK 1

#define ANIM_SIZE 2

class Hero {

public:
    float m_speed = 100.f;

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
    
public:
    Hero() :   
        m_texture{LoadTexture("assets\\sprite\\hero\\hero.png")}, 
        m_sprite{&m_texture, {6.f, 5.f}}, 
        m_animations{
            Animation{&m_sprite, {6.f, 6.f}, 1.f, false, false}, 
            Animation{&m_sprite, {0.f, 5.f}, 4.f, false, false}
        } {}

    void setPosition();

    void update();
    void draw();

};