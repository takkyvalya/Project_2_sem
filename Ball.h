#pragma once

namespace mt {
    struct Point {
        float x;
        float y;
    };

    struct Vec {
        float x;
        float y;
    };

    class Ball {
    private:
        Point m_p0;
        Vec m_velocity = { 0, 9 };
        float m_r;
        sf::CircleShape* m_shape;
        int m_count = 0;
    public:
        Ball(Point p0, float r, sf::Color color) {
            m_p0 = p0;
            m_r = r;
            m_shape = new sf::CircleShape(m_r);
            m_shape->setFillColor(color);
            m_shape->setOrigin(m_r, m_r);
        }

        ~Ball() {
            delete m_shape;
        }

        void Move(double dt) {
            m_p0.x += m_velocity.x * dt;
            m_p0.y += m_velocity.y * dt;
            m_shape->setPosition(m_p0.x, m_p0.y);
        }

        void MoveCharacter(double dt, sf::View* view) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                m_velocity = { -1, 0 };
                m_p0.x = m_p0.x - 0.5;
                view->move(-0.5,0);
                m_shape->setPosition( m_p0.x,m_p0.y);
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                m_velocity = { 1, 0 };
                m_p0.x = m_p0.x +0.5;
                view->move(0.5,0);
                m_shape->setPosition( m_p0.x,m_p0.y );
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                m_velocity = { 0, -1 };
                m_p0.y = m_p0.y - 0.5;
                view->move(0,-0.5);
                m_shape->setPosition( m_p0.x,m_p0.y);

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                m_velocity = { 0, 1 };
                m_p0.y = m_p0.y + 0.5;
                view->move(0,0.5);
                m_shape->setPosition( m_p0.x ,m_p0.y);
            }
        }

        sf::CircleShape* Get() { return m_shape; }

        void SetVelocity(Vec v) {
            m_velocity = v;
        }

        void SetPosition(Point p) {
            m_p0 = p;
            m_shape->setPosition(m_p0.x, m_p0.y);
        }

        void Count() {
            m_count++;
        }

        //Ãåòòåðû
        int GetCount() { return m_count; }
        Point GetPosition() { return m_p0; }
        Vec GetVelocity() { return m_velocity; }

        float Radius() { return m_r; }
    };
}