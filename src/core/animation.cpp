#include "animation.hpp"

void Animation::setFlip(bool flipH, bool flipV) {
    m_flipH = flipH; 
    m_flipV = flipV;
}

void Animation::update() {
    if (!m_isPlaying) return;

    m_animCounter += GetFrameTime();

    if (!(m_animCounter >= m_animCounterTick)) return;

    m_animCounter = 0.f;
    syncCurrentFrame();
    
    if (++m_currentFrame > (int)m_startEndFrame.y)
        m_currentFrame = (int)m_startEndFrame.x;
    
    m_sprite->changeFrame(m_currentFrame);
    m_sprite->flipFrame(m_flipH, m_flipV);
}
