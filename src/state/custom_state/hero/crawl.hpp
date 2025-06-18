#pragma once

#include "raylib.h"

#include "../../state.hpp"

class CrawlState : public State {

public:
    CrawlState(Hero* owner) : State(owner) {}

    virtual void enter() override;
    virtual void exit()  override;

    void movementHandler();

    virtual void update() override;

};