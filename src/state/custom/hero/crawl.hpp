#pragma once

#include "raylib.h"

#include "../../state.hpp"

class CrawlState : public State {

public:
    CrawlState(Hero* owner) : State(owner) {}

    void enter() override;
    void exit()  override;

    void movementHandler();

    void update() override;

};