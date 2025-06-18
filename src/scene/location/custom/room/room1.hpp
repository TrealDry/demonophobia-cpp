#pragma once

#include "../../room.hpp"
#include "../../../../object/hero.hpp"

#define ROOM_1A_BG "assets\\sprite\\rooms\\room1a.png"
#define ROOM_1B_BG "assets\\sprite\\rooms\\room1b.png"

class Room1 : public Room {

public:
    Texture m_texture;

public:
    Room1(Hero* hero) :
        Room(hero), m_texture(LoadTexture(ROOM_1A_BG))
        { m_background = &m_texture; }

};
