#pragma once
#include <string>
#include <iostream>
#include <C:/Users/vtakk/CLionProjects/2_semestr/LaboratoryWork_1/SFML-2.5.1/include/SFML/Graphics.hpp>
#include "Map/Map.h"
#include "Entity.h"

namespace mt {
    class Game {
    private:
        int m_width = 0;
        int m_height = 0;
        std::string m_caption;
        sf::RenderWindow* m_window = nullptr;

    public:
        Game() = default;
        ~Game();

        void SetCaption(const std::string &caption);

        void SetResolution(int width, int height);

        void Setup();

        void Run();
    };
}