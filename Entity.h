#pragma once
#include "Game.h"

    class Entity {
    protected:
        float x, y, dx, dy, speed, moveTimer;
        int w, h;
        bool isMove, onGround;
        sf::String name;
        sf::Texture texture;
        sf::Sprite sprite;
        char **map;
    public:
        Entity(sf::Image &image, float X, float Y, int W, int H, sf::String Name);

        sf::FloatRect getRect();

        void SetMap(char **Map);

        sf::Sprite* GetSprite();
    };

    class Player : public Entity {
        private:
            int count = 0; //счетчик букв

            void Stopper(float Dx, float Dy, int i, int j);

        public:
            bool life = true; //переменная жизни

            enum { left, right, up, doun, jump, stay } state;  // пречисление состояния персонажа

            Player(sf::Image &image, float X, float Y, int W, int H, sf::String Name);

            ///////////////////////АНИМАЦИЯ///////////////////////////////
            void control(float *CurrentFrame, float time, sf::View *view);

            void checkCollisionWithMap(float Dx, float Dy);

            void update(float time, float *CurrentFrame, float t, sf::View *view);

            float getplayercoordinateX();

            float getplayercoordinateY();
    };

    class Enemy : public Entity {
        public:
            float moveTimer = 0;

            Enemy(sf::Image &image, float X, float Y, int W, int H, sf::String Name);

            void update(float time); //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.

    };
