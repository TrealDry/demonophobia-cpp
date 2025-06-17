#include "window.hpp"
#include "spdlog/spdlog.h"

Window::Window() {
    spdlog::info("Create window");

    InitWindow(m_screenWidth, m_screenHeight, m_windowName.c_str());
    SetTargetFPS(m_fps);
    
    m_scene = new Scene;
}

Window& Window::getInstance() {
    static Window w;
    return w;
}

void Window::run() {
    while (!WindowShouldClose()) {
        m_scene->update();

        BeginDrawing();
        m_scene->draw();
        EndDrawing();
    }

    CloseWindow();
}
