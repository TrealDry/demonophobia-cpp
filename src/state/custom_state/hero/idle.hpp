#pragma once

#include "raylib.h"

#include "../../state.hpp"

class IdleState : public State {

public:
    IdleState(Hero* owner) : State(owner) {}

    virtual void enter() override;
    virtual void exit()  override;

    virtual void update() override;

};