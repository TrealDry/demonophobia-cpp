#pragma once

#include "../../state.hpp"

class MoveState : public State {

public:
    bool m_animIsPlaying = false;

public:
    MoveState(Hero* owner) : State(owner) {}

    void enter() override;
    void exit()  override;

    void playAnimation();
    void movementHandler();

    void update() override;

};