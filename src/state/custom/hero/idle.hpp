#pragma once

#include "raylib.h"

#include "../../state.hpp"

class IdleState : public State {

public:
    IdleState(Hero* owner) : State(owner) {}

    void enter() override;
    void exit()  override;

    void update() override;

};