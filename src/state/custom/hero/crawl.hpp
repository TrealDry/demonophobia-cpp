#pragma once

#include "../../state.hpp"

class CrawlState : public State {

public:
    bool m_animIsPlaying = false;

public:
    CrawlState(Hero* owner) : State(owner) {}

    void enter() override;
    void exit()  override;

    void playAnimation();
    void movementHandler();

    void update() override;

};