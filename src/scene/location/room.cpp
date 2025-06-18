#include "room.hpp"
#include "../../object/hero.hpp"

Room::Room(Hero *hero) : m_hero(hero) {
    m_hero->m_owner = this;
}

Room::Room(Hero *hero, Texture *background) : m_hero(hero), m_background(background) {
    m_hero->m_owner = this;
}

void Room::update() {
    m_hero->update();
}

void Room::draw() {
    DrawTexture(*m_background, 0, 0, WHITE);
    m_hero->draw();

    for (auto wall: m_walls) {
        wall.draw();
    }
}
