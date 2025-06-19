#pragma once

#include <string>

#include "debug.hpp"
#include "../object/hero.hpp"
#include "../scene/location/custom/room/room1.hpp"

class Window {

public:
    const int m_screenWidth  = 800;
    const int m_screenHeight = 600;

    std::string m_windowName = "Demonophobia";

    int m_fps = 60;

    Hero*  m_hero;
    Scene* m_scene;

private:
    Window();

public:
    ~Window() = default;

    static Window& getInstance();

    void run();

    // singleton
    Window(Window const&) = delete;
    Window& operator= (Window const&) = delete;
};