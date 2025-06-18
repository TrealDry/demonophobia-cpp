#pragma once

#include "raylib.h"

#include "../../state.hpp"

class SitState : public State {

public:
    SitState(Hero* owner) : State(owner) {}

    virtual void enter() override;
    virtual void exit()  override;

    virtual void update() override;

};