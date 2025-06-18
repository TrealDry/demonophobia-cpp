#pragma once

class Hero;

class State {

public:
    Hero* m_owner;

public:
    State(Hero* owner) : m_owner(owner) {};
    virtual ~State() = default;

    virtual void enter()  = 0;
    virtual void exit()   = 0;

    virtual void update() = 0;

};