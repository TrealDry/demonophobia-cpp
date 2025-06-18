#pragma once

#include "raylib.h"

#include "../../state.hpp"

class SitState : public State {

public:
    SitState(Hero* owner) : State(owner) {}

    void enter() override;
    void exit()  override;

    void update() override;

};