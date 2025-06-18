#pragma once

class Object {

public:
    virtual ~Object() = default;

    virtual void draw()   = 0;
    virtual void update() = 0;

};
