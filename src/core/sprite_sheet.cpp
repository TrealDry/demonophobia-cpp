#include "sprite_sheet.hpp"

void SpriteSheet::changeFrame(int frame) {
    int x = 0, y = 0;

    for (size_t i = 0; i < frame; i++) {
        if (++x >= m_textureFrameSize.x) {
            x = 0;
            if (++y >= m_textureFrameSize.y) 
                y = 0;
        }
    }
    
    Rectangle newTextureSource = {
        (m_textureFrameSizePixel.x * (x + 1)) - m_textureFrameSizePixel.x,
        (m_textureFrameSizePixel.y * (y + 1)) - m_textureFrameSizePixel.y,

        m_textureFrameSizePixel.x,
        m_textureFrameSizePixel.y
    };
    m_textureSource = newTextureSource;
    m_selectedFrame = frame;
}

void SpriteSheet::flipFrame(bool flipH, bool flipV) {
    m_textureSource.width  = flipH ? -m_textureSource.width  : m_textureSource.width;
    m_textureSource.height = flipV ? -m_textureSource.height : m_textureSource.height;
}

void SpriteSheet::initFrameSizePixel() {
    m_textureFrameSizePixel.x = (float)m_texture->width / m_textureFrameSize.x;
    m_textureFrameSizePixel.y = (float)m_texture->height / m_textureFrameSize.y;
}

void SpriteSheet::initFields() {
    if (m_textureFrameSizePixelInit) {
        m_textureFrameSizePixelInit = false;
        initFrameSizePixel();
    }
}