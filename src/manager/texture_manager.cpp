#include "texture_manager.hpp"

Texture* TextureManager::get(const std::string &name) {
    spdlog::info("Getting texture name: {}", name);

    if (!m_texturesPath.contains(name)) {
        throw std::runtime_error("Texture does not exist!!!");
    }

    if (!m_textures.contains(name)) {
        if (!load(name)) {
            throw std::runtime_error("Texture could not be loaded!!!");
        }
    }

    return m_textures[name];
}

bool TextureManager::load(const std::string &name) {
    if (!m_texturesPath.contains(name)) {
        spdlog::error("Texture hasn't been loaded! Name = {}", name);
        return false;
    }

    auto* texture = new Texture(LoadTexture(m_texturesPath[name].c_str()));
    m_textures.insert({name, texture});

    spdlog::info("Texture has been loaded! Name = {}", name);
    return true;
}

TextureManager& TextureManager::getInstance() {
    static TextureManager instance;

    return instance;
}

TextureManager::TextureManager() {
    for (auto& entry: fs::recursive_directory_iterator("assets\\sprite")) {
        if (!entry.is_regular_file()) continue;

        std::string filename = entry.path().stem().string();
        m_texturesPath[filename] = entry.path().string();
    }
}




