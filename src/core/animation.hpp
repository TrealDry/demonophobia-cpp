#pragma once

#include "raylib.h"
#include "spdlog/spdlog.h"

#include "sprite_sheet.hpp"

class Animation {

protected:
    SpriteSheet* m_sprite;
    Vector2 m_startEndFrame;

    float m_animSpeed;  // 1.f = 1 frame per second
    float m_animCounter = 0.f;
    float m_animCounterTick;

    int m_currentFrame = 0;

    bool m_isPlaying = false;

    char m_multiplierFrame = 1; // 1 = animation move forward, -1 = reverse
    bool m_reverseAfterFinish = false;

    bool m_oneFrame;

public:
    Animation(SpriteSheet* sprite, Vector2 startEndFrame, float animSpeed, bool reverseAfterFinish) 
    : m_sprite(sprite), m_startEndFrame(startEndFrame), 
      m_animSpeed(animSpeed), m_animCounterTick(1.f / m_animSpeed), 
      m_reverseAfterFinish(reverseAfterFinish),
      m_oneFrame(m_startEndFrame.x - m_startEndFrame.y == 0)
      {}

    bool getPlayingStatus() { return m_isPlaying; }

    void play() { m_isPlaying = true;  }
    void stop() { m_isPlaying = false; }

    void syncCurrentFrame() { m_currentFrame = m_sprite->getSelectedFrame(); }
    void update();

};
