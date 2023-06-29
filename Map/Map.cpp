#include "Map.h"

#include <fstream>
#include <iostream>

namespace m {
    void Map::SetSize() {
        for (int i = 0; i < 2; i++) {
            std::string str;
            map_file >> str;
            if (str == "HEIGHT")
                map_file >> map_HEIGHT;
            else if (str == "WIDTH")
                map_file >> map_WIDTH;
        }
        map_HEIGHT--;
        map_WIDTH--;
    }

    Map::Map(std::string path) {
        std::cout << "Map Constructor" << std::endl;
        map_file.open(path);
    }

    Map::~Map() {
        std::cout << "Map Destructor" << std::endl;
        map_file.close();

        for (int i = 0; i < map_HEIGHT; i++)
            delete[] map_mas[i];
        delete[] map_mas;
    }

    ///СОЗДАЕМ МАССИВ КАРТЫ///
    void Map::SetMassive() {
        SetSize();
        map_mas = new char *[map_HEIGHT];
        for (int i = 0; i < map_HEIGHT; i++)
            map_mas[i] = new char[map_WIDTH];

        char b;
        for (int i = 0; i < map_HEIGHT; i++) {
            for (int j = 0; j < map_WIDTH; j++) {
                map_file >> b;
                map_mas[i][j] = b;
            }
        }
    }

    void Map::SetImage() {
        std::cout << "Image complite" << std::endl;
        sf::Image map_image;//объект изображения для карты
        map_image.loadFromFile("C:/Users/vtakk/CLionProjects/2_semestr/Susuwatari/Map/files/Sprites.png");
        map_texture.loadFromImage(map_image);
        //map_texture;
        map_sprite.setTexture(map_texture);
    }

    ////////ЗАДАНИЕ ТЕКСТУРЫ КАРТЫ////////
    sf::Sprite *Map::SetTexture(int a, int b) {
        switch (map_mas[a][b]) {
            case 'b':
                map_sprite.setTextureRect(sf::IntRect(300, 0, 32, 32));
                a = 0;
                b = 0;
                //map_sprite.setTextureRect(nullptr);
                break;
            case '_':
                map_sprite.setTextureRect(sf::IntRect(384, 0, 32, 32));
                break;
            case '0':
                map_sprite.setTextureRect(sf::IntRect(384, 0, 32, 32));
                break;
            case 's':
                map_sprite.setTextureRect(sf::IntRect(0, 0, 32, 32));
                break;
            case 'q':
                map_sprite.setTextureRect(sf::IntRect(0, 64, 64, 128));
                break;
            case 'p':
                map_sprite.setTextureRect(sf::IntRect(274, 64, 222, 128));
                break;
            case 'w':
                map_sprite.setTextureRect(sf::IntRect(0, 32, 160, 32));
                break;
            case 'e':
                map_sprite.setTextureRect(sf::IntRect(176, 32, 160, 32));
                break;
            case 'r':
                map_sprite.setTextureRect(sf::IntRect(352, 32, 160, 32));
                break;
            case 'y':
                map_sprite.setTextureRect(sf::IntRect(528, 32, 160, 32));
                break;
            case '1':
                map_sprite.setTextureRect(sf::IntRect(41, 0, 32, 32));
                break;
            case '2':
                map_sprite.setTextureRect(sf::IntRect(41 + 32, 0, 32, 32));
                break;
            case '3':
                map_sprite.setTextureRect(sf::IntRect(41 + 64, 0, 32, 32));
                break;
            case '4':
                map_sprite.setTextureRect(sf::IntRect(41 + 96, 0, 32, 32));
                break;
            case '5':
                map_sprite.setTextureRect(sf::IntRect(41 + 96 + 32, 0, 32, 32));
                break;
            case '6':
                map_sprite.setTextureRect(sf::IntRect(41 + 96 + 64, 0, 32, 32));
                break;
            case '7':
                map_sprite.setTextureRect(sf::IntRect(41 + 96 + 96, 0, 32, 32));
                break;
            case '8':
                map_sprite.setTextureRect(sf::IntRect(41 + 96 + 96 + 32, 0, 32, 32));
                break;
            case 'N':
                map_sprite.setTextureRect(sf::IntRect(0, 209, 32, 32));
                break;
            case 'O':
                map_sprite.setTextureRect(sf::IntRect(32, 209, 32, 32));
                break;
            case 'W':
                map_sprite.setTextureRect(sf::IntRect(64, 209, 32, 32));
                break;
            case 'A':
                map_sprite.setTextureRect(sf::IntRect(96, 209, 32, 32));
                break;
            case 'Y':
                map_sprite.setTextureRect(sf::IntRect(128, 209, 32, 32));
                break;
            case 'K':
                map_sprite.setTextureRect(sf::IntRect(176, 208, 32, 32));
                break;
            case 'C':
                map_sprite.setTextureRect(sf::IntRect(240, 209, 32, 32));
                break;
        }

        map_sprite.setPosition(b * 32, a * 32);
        return &map_sprite;
    }

    //Геттеры
    char **Map::GetMassive() { return map_mas; }

    int Map::GetHEIGHT() { return map_HEIGHT; }

    int Map::GetWIDTH() { return map_WIDTH; }

    sf::Sprite *Map::GetSprite() { return &map_sprite; }
}