#include "raylib.h"
#include "spdlog/spdlog.h"

#include "sprite_sheet.hpp"

class Animation {

protected:
    SpriteSheet* m_sprite;
    Vector2 m_startEndFrame;

    float m_animSpeed;  // 1.f = 1 frame per second
    float m_animCounter;
    float m_animCounterTick;

    int m_currentFrame;

    bool m_isPlaying;
    bool m_flipH;
    bool m_flipV;

public:
    Animation(SpriteSheet* sprite, Vector2 startEndFrame, float animSpeed, bool flipH, bool flipV) 
    : m_sprite(sprite), m_startEndFrame(startEndFrame), m_animSpeed(animSpeed), 
      m_animCounter(0.f), m_currentFrame(0), m_animCounterTick(1.f / m_animSpeed), 
      m_isPlaying(false), m_flipH(flipH), m_flipV(flipV)
    {}

    bool getPlayingStatus() { return m_isPlaying; }

    bool getFlip(bool isFlipH) { return isFlipH ? m_flipH : m_flipV; }
    void setFlip(bool flipH, bool flipV);

    void play() { m_isPlaying = true;  }
    void stop() { m_isPlaying = false; }

    void syncCurrentFrame() { m_currentFrame = m_sprite->getSelectedFrame(); }
    void update();

};
