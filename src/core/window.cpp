#include "window.hpp"

Window::Window() {
    InitWindow(m_screenWidth, m_screenHeight, m_windowName.c_str());
    SetTargetFPS(m_fps);

    m_hero  = new Hero();
    m_scene = new Room1(m_hero);
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
