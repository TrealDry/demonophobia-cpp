#pragma once

#include "../../room.hpp"
#include "../../../../object/hero.hpp"

#define ROOM_1A_BG "room1a"
#define ROOM_1B_BG "room1b"

class Room1 : public Room {

public:
    Texture m_texture;

public:
    Room1(Hero* hero) :
        Room(hero,TextureManager::getInstance().get(ROOM_1A_BG)) {}

};
