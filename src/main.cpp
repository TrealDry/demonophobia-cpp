#include "./core/window.hpp"

auto sourcePath = "E:\\Archive\\Code\\demonophobia-cpp";

int main(void) {
    ChangeDirectory(sourcePath);

    Window& win = Window::getInstance();
    win.run();

    return 0;
}
