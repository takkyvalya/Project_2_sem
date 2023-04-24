#include <string>
#include "Game.h"

namespace mt {

    Game::~Game() {
        if (m_window != nullptr)
            delete m_window;
    }

    void Game::SetCaption(const std::string& caption) {
        m_caption = caption;
    }

    void Game::SetResolution(int width, int height) {
        m_width = width;
        m_height = height;
    }

    void Game::Setup() {
        m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_caption);
    }

    void Game::Run() {

        sf::Clock timer;
        sf::CircleShape ball(50);

        m::Map map( "C:\\Users\\vtakk\\CLionProjects\\2_semestr\\Susuwatari\\files\\Map.txt");
        map.SetMassive();
        map.SetImage();

        while (m_window->isOpen()) {
            sf::Event event;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            sf::Time dt = timer.restart();

            m_window->clear();

            //Рисуем карту
            for (int i = 0; i < map.GetHEIGHT(); i++)
                for (int j = 0; j < map.GetWIDTH(); j++)
                    m_window->draw( (*map.SetTexture(i,j)));//рисуем квадратики на экран

            //m_window->draw(ball);
            m_window->display();
        }

    }
}
