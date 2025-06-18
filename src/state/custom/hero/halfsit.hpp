#pragma once

#include "raylib.h"

#include "../../state.hpp"

#define SIT_TIME 0.2f

class HalfSitState : public State {

public:
    float m_counter;

public:
    HalfSitState(Hero* owner) : State(owner), m_counter(0.f) {}

    void enter() override;
    void exit()  override;

    void update() override;

};