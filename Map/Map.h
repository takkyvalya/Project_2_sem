#include <fstream>
#include <iostream>

namespace m{
    class Map{
    private:
        void SetSize(){
            for(int i =0; i<2;i++){
                std::string str;
                map_file >> str;
                if(str == "HEIGHT")
                    map_file >> map_HEIGHT;
                else if(str == "WIDTH")
                    map_file >> map_WIDTH;
            }
            map_HEIGHT--; map_WIDTH--;
        }
    public:
        Map(std::string path){
            std::cout << "Map Constructor" << std::endl;
            map_file.open(path);
        }
        ~Map(){
            std::cout << "Map Destructor" << std::endl;

            map_file.close();

            for(int i = 0;i < map_HEIGHT;i++)
                delete [] map_mas[i];
            delete [] map_mas;
        }

        void SetMassive(){
            SetSize();
            map_mas = new char*[map_HEIGHT];
            for(int i = 0;i < map_HEIGHT;i++)
                map_mas[i] = new char[map_WIDTH];

            char b;
            for (int i = 0; i < map_HEIGHT; i++) {
                for (int j = 0; j < map_WIDTH; j++) {
                    map_file >> b;
                    map_mas[i][j] = b;
                }
            }
        }

        void SetImage(){
            std::cout << "Image complite" <<std::endl;
            sf::Image map_image;//объект изображения для карты
            map_image.loadFromFile("C:/Users/vtakk/CLionProjects/2_semestr/Susuwatari/Map/files/Books.png");
            map_texture.loadFromImage(map_image);
             //map_texture;
            map_sprite.setTexture(map_texture);
        }

        sf::Sprite* SetTexture(int a, int b){
            switch (map_mas[a][b]) {
                case 'b':
                    map_sprite.setTextureRect(sf::IntRect(300, 0,32, 32));
                    a=0; b=0;
                    //map_sprite.setTextureRect(nullptr);
                    break;
                case '_':
                    map_sprite.setTextureRect(sf::IntRect(300, 0,32, 32));
                    break;
                case '0':
                    map_sprite.setTextureRect(sf::IntRect(300, 0,32, 32));
                    break;
                case 's':
                    map_sprite.setTextureRect(sf::IntRect(0, 0,32, 32));
                    break;
                case 'q':
                    map_sprite.setTextureRect(sf::IntRect(0, 64, 192, 128));
                    //map_sprite.setTextureRect(sf::IntRect(64, 0, 32, 32));
                    break;
                case 'w':
                    map_sprite.setTextureRect(sf::IntRect(0, 32, 160, 32));
                    break;
                case 'e':
                    map_sprite.setTextureRect(sf::IntRect(192, 64, 64, 128));
                    break;
                case '1':
                    map_sprite.setTextureRect(sf::IntRect(32+96, 0, 32, 32));
                    break;
                case '2':
                    map_sprite.setTextureRect(sf::IntRect(32, 0,32, 32));
                    break;
                case '3':
                    map_sprite.setTextureRect(sf::IntRect(64, 0,32, 32));
                    break;
                case '4':
                    map_sprite.setTextureRect(sf::IntRect(96, 0,32, 32));
                    break;
            }

            map_sprite.setPosition(b * 32, a * 32);
            return &map_sprite;
        }

        //Геттеры
        char** GetMassive(){ return map_mas; }
        int GetHEIGHT(){ return map_HEIGHT; }
        int GetWIDTH(){ return map_WIDTH; }
        sf::Sprite* GetSprite(){ return &map_sprite; }

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