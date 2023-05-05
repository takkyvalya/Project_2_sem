#include <string>
#include "Game.h"
#include "Ball.h"

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

        //sf::Clock timer;
        //mt::Ball ball({300,360},14,sf::Color::Black);
        //sf::CircleShape ball1(50);

        m::Map map( "C:\\Users\\vtakk\\CLionProjects\\2_semestr\\Susuwatari\\Map\\files\\Map.txt");
        map.SetMassive();
        map.SetImage();

        sf::View view(sf::FloatRect(0.f, 0.f, m_width, m_height));
        view.setCenter(300,320);
        //view.zoom(2.0f);
        //view.move(1000.f,0.f);
        view.zoom(0.3f);

        sf::Image Susa;
        Susa.loadFromFile("C:/Users/vtakk/CLionProjects/2_semestr/Susuwatari/Map/files/susa.png");

        float CurrentFrame = 0;
        sf::Clock clock;

        Player susa(Susa, 300-16, 300, 32, 32,"susa");

        while (m_window->isOpen()) {
            sf::Event event;
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            //sf::Time dt = timer.restart();


            susa.update(time, map.GetMassive(), &CurrentFrame , time, &view);

            m_window->clear();
            m_window->setView(view);

            //Рисуем карту
            for (int i = 0; i < map.GetHEIGHT(); i++)
                for (int j = 0; j < map.GetWIDTH(); j++)
                    m_window->draw( (*map.SetTexture(i,j)));//рисуем квадратики на экран

                     //m_window->draw(ball1);
            m_window->draw(*susa.GetSprite());
            m_window->display();
        }

    }
}
