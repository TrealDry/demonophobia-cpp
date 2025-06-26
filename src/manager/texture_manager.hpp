#pragma once

#include <string>
#include <stdexcept>
#include <filesystem>
#include <unordered_map>

#include "raylib.h"
#include "spdlog/spdlog.h"

#define PATH_TO_SPRITES "assets\\sprites\\"

namespace fs = std::filesystem;

class TextureManager {

protected:
    std::unordered_map<std::string, Texture*> m_textures;
    std::unordered_map<std::string, std::string> m_texturesPath;

protected:
    TextureManager();

public:
    ~TextureManager() = default;

    Texture* get(const std::string& name);
    bool load(const std::string& name);

    static TextureManager& getInstance();

    // singleton
    TextureManager(TextureManager const&) = delete;
    TextureManager& operator= (TextureManager const&) = delete;
};
