#pragma once

#include "../../state.hpp"

class MoveState : public State {

public:
    MoveState(Hero* owner) : State(owner) {}

    void enter() override;
    void exit()  override;

    void movementHandler();

    void update() override;

};