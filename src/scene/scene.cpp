#include "scene.hpp"

Scene::Scene() {
    m_Background = LoadTexture("assets\\sprite\\rooms\\room1b.png");
}

void Scene::draw() {
    ClearBackground(BLUE);
    DrawTexture(m_Background, 0, 0, WHITE);
    m_hero.draw();
    //DrawText("Congrats! You created your first scene!", 190, 200, 20, LIGHTGRAY);
}

void Scene::update() {
    m_hero.update();
}
