#include "Entity.h"

    Entity::Entity(sf::Image &image, float X, float Y, int W, int H, sf::String Name) {
        x = X; y = Y; w = W; h = H; name = Name;
        moveTimer = 0; speed = 0; dx = 0; dy = 0;
        onGround = false;
        isMove = false;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
    }

    sf::FloatRect Entity::getRect() { return sf::FloatRect(x, y, w, h); }

    void Entity::SetMap(char **Map) { map = Map; }

    sf::Sprite* Entity::GetSprite() { return &sprite; }

    void Player::Stopper(float Dx, float Dy, int i, int j) {
        if (Dy > 0) {
            y = i * 32 - h;
            dy = 0;
            onGround = true;
        }
        if (Dy < 0) {
            y = i * 32 + 32;
            dy = 0;
            onGround = false;
        }
        if (Dx > 0) {
            x = j * 32 - w;
        }
        if (Dx < 0) {
            x = j * 32 + 32;
        }
    }

    Player::Player(sf::Image &image, float X, float Y, int W, int H, sf::String Name) : Entity(image, X, Y, W, H, Name) {
        state = stay;
        if (name == "susa") {
            sprite.setTextureRect(sf::IntRect(0, 0, w, h));
        }
        sprite.setOrigin(w / 2, h / 2);
    }

    /////////////////////////////АНИМАЦИЯ//////////////////////////////////
    void Player::control(float *CurrentFrame, float time, sf::View *view) {
        if (life == true) {
            if (sf::Keyboard::isKeyPressed) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                    state = left;
                    speed = 0.1;
                    *CurrentFrame += 0.005 * time;
                    if (*CurrentFrame > 4) {
                        *CurrentFrame -= 4;
                    }
                    sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 66, 33, 32));
                    //view->move(-speed,0);
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                    state = right;
                    speed = 0.1;
                    *CurrentFrame += 0.005 * time;
                    if (*CurrentFrame > 4) {
                        *CurrentFrame -= 4;
                    }
                    sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 98, 32, 32));
                    //view->move(speed,0);
                }

                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) &&
                    (sf::Keyboard::isKeyPressed(sf::Keyboard::A))) {
                    state = left;
                    speed = 0.2;
                    *CurrentFrame += 0.005 * time;
                    if (*CurrentFrame > 4) {
                        *CurrentFrame -= 4;
                    }
                    sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 131, 32, 32));
                }
                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) ||
                     sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) &&
                    (sf::Keyboard::isKeyPressed(sf::Keyboard::D))) {
                    state = right;
                    speed = 0.2;
                    *CurrentFrame += 0.005 * time;
                    if (*CurrentFrame > 4) {
                        *CurrentFrame -= 4;
                    }
                    sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 160, 32, 32));
                }

                if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (onGround)) {
                    state = jump;
                    dy = -0.4;
                    //sprite.setTextureRect(sf::IntRect(120 * int(CurrentFrame), 133, 120, 133));
                    onGround = false;
                }
            }
        }
    }

    ////////////////////ВЗАИМОДЕЙСТВИЕ С КАРТОЙ/////////////
    void Player::checkCollisionWithMap(float Dx, float Dy) {
        for (int i = y / 32; i < (y + h) / 32; i++) {
            for (int j = x / 32; j < (x + w) / 32; j++) {
                switch (map[i][j]) {
                    case 's':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'b':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'q':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'w':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 't':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'e':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'r':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'y':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '1':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '2':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '3':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '4':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '5':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '6':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '7':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case '8':
                        Stopper(Dx, Dy, i, j);
                        break;
                    case 'N':
                        map[i][j] = '_';  //суса собирает буквы
                        count++;
                        break;
                    case 'O':
                        map[i][j] = '_';
                        count++;
                        break;
                    case 'W':
                        map[i][j] = '_';
                        count++;
                        break;
                    case 'A':
                        map[i][j] = '_';
                        count++;
                        break;
                    case 'Y':
                        map[i][j] = '_';
                        count++;
                        break;
                    case 'K':
                        map[i][j] = 'C';
                        break;
                }
            }
        }
    }

    /////////////////////////////ДВИЖЕНИЕ/////////////////////////////////////////
    void Player::update(float time, float *CurrentFrame, float t, sf::View *view) {
        control(CurrentFrame, t, view);
        switch (state) //различные действия в зависимости от состояния
        {
            case right:
                dx = speed;
                break;
            case left:
                dx = -speed;
                break;
            case jump:
                break;
            case stay:
                break;
        }

        x += dx * time; //наше ускорение на время получаем смещение координат и как следствие движение
        checkCollisionWithMap(dx, 0); //обрабатываем столкновиние по Х
        y += dy * time; //аналогично
        checkCollisionWithMap(0, dy); //обрабатываем столкновение по Y
        //std::cout << " Susa  x: " << x << " y: " << y<< " dy: " << dy << std::endl;
        view->setCenter(x + 30, y);
        sprite.setPosition(x + w / 2, y + h /
                                          2); //задаём позицию спрайта в место его центра. бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
        if (!isMove) {
            speed = 0;
        }
        dy = dy + 0.0015 * time; //притяжение к земле
        if (life == false) {
            speed = 0;
        }
    }

    float Player::getplayercoordinateX() {
        return x;
    }

    float Player::getplayercoordinateY() {
        return y;
    }


    Enemy::Enemy(sf::Image &image, float X, float Y, int W, int H, sf::String Name) : Entity(image, X, Y, W, H, Name) {
        if (name == "clip") {

            sprite.setTextureRect(sf::IntRect(0, 0, w, h));
            dx = -0.08; //постоянная скорость скрепки
        }
    }

    void Enemy::update(float time) //функция "оживления" объекта класса. update - обновление. принимает в себя время SFML , вследствие чего работает бесконечно, давая персонажу движение.
    {
        if (name == "clip") {
            moveTimer += time;

            if (moveTimer > 2500) {
                dx *= -1;
                sprite.scale(-1, 1);
                moveTimer = 0;
            }
            x += dx * time; //наше ускорение на время получаем смещение координат и как следствие движение
            sprite.setPosition(x + w / 2, y + h /
                                              2); //выводим спрайт в позицию (x + w / 2, y + h / 2). бесконечно выводим в этой функции, иначе бы наш спрайт стоял на месте.
        }
    }
