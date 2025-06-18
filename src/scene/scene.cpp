#include "scene.hpp"

Scene::Scene() : 
    m_hero(), m_Background(LoadTexture("assets\\sprite\\rooms\\room1b.png")) 
    {
        spdlog::info("init scene !!!!!");
        // m_hero.changeState(m_hero.m_idleState);
    }

void Scene::draw() {
    ClearBackground(BLUE);
    DrawTexture(m_Background, 0, 0, WHITE);
    m_hero.draw();
}

void Scene::update() {
    m_hero.update();
}
