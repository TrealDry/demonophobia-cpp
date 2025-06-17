#include "./core/window.hpp"

int main(void) {
    Window& win = Window::getInstance();
    win.run();

    return 0;
}
