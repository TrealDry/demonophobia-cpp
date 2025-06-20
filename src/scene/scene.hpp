#pragma once

class Scene {

public:
    virtual ~Scene() = default;

    virtual void draw()   = 0;
    virtual void update() = 0;

};