
class Entity
{
protected:
    float x, y, dx, dy, speed, moveTimer;
    int w, h;
    bool isMove, onGround;
    sf::String name;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Entity (sf::Image& image, float X, float Y, int W, int H, sf::String Name)
    {
        x = X; y = Y; w = W; h = H; name = Name; moveTimer = 0;
        speed = 0; dx = 0; dy = 0;
        onGround = false; isMove = false;
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
    }
};

class Player: public Entity
{
private:
    void Stopper(float Dx, float Dy, int i, int j){
        if (Dy > 0) {
            y = i * 32 - h;
            Dy = 0;
            onGround = true;
        }
        if (Dy < 0) {
            y = i * 32 + 32;
            Dy = 0;
            onGround = false;
        }
        if (Dx > 0) {
            x = j * 32 - w;
        }
        if (Dx < 0) {
            x = j * 32 + 32;
        }
    }

public:
    enum {left, right, up, doun, jump, stay} state;

    Player(sf::Image &image, float X, float Y, int W, int H, sf::String Name):Entity(image, X, Y, W, H, Name)
    {
        state = stay;
        if(name == "susa")
        {
            sprite.setTextureRect(sf::IntRect(0, 0, w, h));
        }
        sprite.setOrigin(w/2, h/2);
    }

    void control(float* CurrentFrame, float time, sf::View* view)
    {
        if (sf::Keyboard::isKeyPressed)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                state = left;
                speed = 0.1;
                *CurrentFrame += 0.005 * time;
                if (*CurrentFrame > 4)
                {
                    *CurrentFrame -= 4;
                }
                sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 66, 33, 32));
                //view->move(-speed,0);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                state = right;
                speed = 0.1;
                *CurrentFrame += 0.005 * time;
                if (*CurrentFrame > 4)
                {
                    *CurrentFrame -= 4;
                }
                sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 98, 32, 32));
                //view->move(speed,0);
            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::A)))
            {
                state = left;
                speed = 0.2;
                *CurrentFrame += 0.005 * time;
                if (*CurrentFrame > 4)
                {
                    *CurrentFrame -= 4;
                }
                sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 131, 32, 32));
            }
            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) && (sf::Keyboard::isKeyPressed(sf::Keyboard::D)))
            {
                state = right;
                speed = 0.2;
                *CurrentFrame += 0.005 * time;
                if (*CurrentFrame > 4)
                {
                    *CurrentFrame -= 4;
                }
                sprite.setTextureRect(sf::IntRect(32 * int(*CurrentFrame), 98, 32, 32));
            }

            if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) && (onGround))
            {
                state = jump;
                dy = -0.4;
                //sprite.setTextureRect(sf::IntRect(120 * int(CurrentFrame), 133, 120, 133));
                onGround = false;
            }
        }
    }

    void checkCollisionWithMap(float Dx, float Dy, char** map) {
        for (int i = y / 32; i < (y + h) / 32; i++) {
            for (int j = x / 32; j < (x + w) / 32; j++) {
                switch (map[i][j]) {
                    case 's':
                        Stopper(Dx, Dy, i,j);
                    case 'b':
                        Stopper(Dx, Dy, i,j);
                    case 'q':
                        Stopper(Dx, Dy, i,j);
                    case 'w':
                        Stopper(Dx, Dy, i,j);
                    case 'e':
                        Stopper(Dx, Dy, i,j);
                    case '1':
                        Stopper(Dx, Dy, i,j);
                    case '2':
                        Stopper(Dx, Dy, i,j);
                    case '3':
                        Stopper(Dx, Dy, i,j);
                    case '4':
                        Stopper(Dx, Dy, i,j);
                }
            }
        }
    }

    void update(float time, char** map, float* CurrentFrame, float t, sf::View* view)
    {
        control(CurrentFrame, t, view);
        switch (state)
        {
            case right: dx = speed; break;
            case left: dx = -speed; break;
            case jump: break;
            case stay: break;
        }

        x += dx * time;
        view->move(dx * time, 0);
        checkCollisionWithMap(dx, 0, map);
        y += dy * time;
        std::cout << "x: " << x << " y: " << y<< " dy: " << dy << std::endl;
        //view->move(0,dy * time);
        checkCollisionWithMap(0, dy, map);
        sprite.setPosition(x + w / 2, y + h / 2);
        if (!isMove)
        {
            speed = 0;
        }
        dy = dy + 0.0015 * time;
    }
    float getplayercoordinateX()
    {
        return x;
    }

    float getplayercoordinateY()
    {
        return y;
    }

    sf::Sprite* GetSprite(){
        return &sprite;
    }
};
