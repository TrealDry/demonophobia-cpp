#pragma once

#include "raylib.h"

#include "../../state.hpp"

class MoveState : public State {

public:
    MoveState(Hero* owner) : State(owner) {}

    virtual void enter() override;
    virtual void exit()  override;

    void movementHandler();

    virtual void update() override;

};