#include "animation.hpp"

void Animation::update() {
    if (!m_isPlaying) return;

    m_animCounter += GetFrameTime();

    if (!(m_animCounter >= m_animCounterTick)) return;

    m_animCounter = 0.f;
    syncCurrentFrame();

    if (m_oneFrame) goto skipAnim;

    m_currentFrame += 1 * m_multiplierFrame;

    if (m_currentFrame > (int)m_startEndFrame.y) {
        if (m_reverseAfterFinish) {
            m_multiplierFrame = -1;
            m_currentFrame -= 2;
        } else {
            m_currentFrame = (int)m_startEndFrame.x;
        }
    
    } else if (m_currentFrame < (int)m_startEndFrame.x) {
        if (m_reverseAfterFinish) {
            m_multiplierFrame = 1;
            m_currentFrame += 2;
        } else {
            m_currentFrame = (int)m_startEndFrame.y;
        }
    }

    skipAnim:
    m_sprite->changeFrame(m_currentFrame);
}
