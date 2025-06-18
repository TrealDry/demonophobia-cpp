#pragma once

#include "raylib.h"

#include "../../state.hpp"

#define SIT_TIME 0.2f

class HalfSitState : public State {

public:
    float m_counter;

public:
    HalfSitState(Hero* owner) : State(owner), m_counter(0.f) {}

    virtual void enter() override;
    virtual void exit()  override;

    virtual void update() override;

};