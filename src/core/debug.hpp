#pragma once

#include "raylib.h"

class Debug {

public:
    inline static bool m_debugMode = false;

public:
    Debug() = delete;

    static void update();

};
