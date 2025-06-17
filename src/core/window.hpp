#pragma once

#include "raylib.h"

#include <stdio.h>
#include <string>

#include "../scene/scene.hpp"

class Window {

public:
    const int m_screenWidth = 800;
    const int m_screenHeight = 600;

    std::string m_windowName = "Demonophobia";

    int m_fps = 60;

    Scene* m_scene;

private:
    Window();

public:
    ~Window() {};

    static Window& getInstance();

    void run();

    // singleton
    Window(Window const&) = delete;
    Window& operator= (Window const&) = delete;
};