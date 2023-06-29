#include <C:/Users/vtakk/CLionProjects/2_semestr/LaboratoryWork_1/SFML-2.5.1/include/SFML/Graphics.hpp>
#pragma once
#include <fstream>
#include <iostream>


namespace m{
    class Map{
    private:
        void SetSize();
    public:
        Map(std::string path);

        ~Map();

        void SetMassive();

        void SetImage();

        ////////ЗАДАНИЕ ТЕКСТУРЫ КАРТЫ////////
        sf::Sprite* SetTexture(int a, int b);

        //Геттеры
        char** GetMassive();
        int GetHEIGHT();
        int GetWIDTH();
        sf::Sprite* GetSprite();

    private:
        std::ifstream map_file;
        std::ofstream out;
        int map_HEIGHT;
        int map_WIDTH;
        char** map_mas;
        sf::Texture map_texture;
        sf::Sprite map_sprite;//создаём спрайт для карты
    };
}