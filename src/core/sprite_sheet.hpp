#pragma once

#include "raylib.h"
#include "spdlog/spdlog.h"

class SpriteSheet {

protected:
    Texture* m_texture;
    Vector2 m_textureFrameSize;
    Vector2 m_textureFrameSizePixel;
    Rectangle m_textureSource;

    bool m_textureFrameSizePixelInit;

    int m_selectedFrame;

protected:
    void initFrameSizePixel();
    void initFields();

public:
    SpriteSheet(Texture* texture, Vector2 textureFrameSize)
        : m_texture(texture), m_textureFrameSize(textureFrameSize),
          m_textureFrameSizePixelInit(true)
    { initFields(); }
    
    Texture2D* getTexture()       { return m_texture; }
    Rectangle& getTextureSource() { return m_textureSource; }
    int        getSelectedFrame() { return m_selectedFrame; }

    void changeFrame(int frame);
    void flipFrame(bool flipH, bool flipV);
    
};