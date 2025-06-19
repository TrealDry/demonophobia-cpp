#include "debug.hpp"

void Debug::update() {
    if (IsKeyPressed(KEY_F1))
        m_debugMode = !m_debugMode;
}

