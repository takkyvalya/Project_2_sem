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
        m::Map map( "C:\\Users\\vtakk\\CLionProjects\\2_semestr\\Susuwatari\\Map\\files\\Map.txt");
        map.SetMassive();
        map.SetImage();

        sf::View view(sf::FloatRect(0.f, 0.f, m_width, m_height));
        view.zoom(0.3f);

        sf::Image Susa;
        Susa.loadFromFile("C:/Users/vtakk/CLionProjects/2_semestr/Susuwatari/Map/files/susa4.png");
        Player susa(Susa, 300-16, 500, 32, 32,"susa");
        //Player susa(Susa, 88*32 , 9*32, 32, 32,"susa");
        susa.SetMap(map.GetMassive());

        sf::Image Clip;
        Clip.loadFromFile("C:/Users/vtakk/CLionProjects/2_semestr/Susuwatari/Map/files/clip.png");
        Enemy clip1(Clip, 448, 2464, 32, 32, "clip");
        Enemy clip2(Clip, 78 * 32, 13*32, 32, 32, "clip");

        float CurrentFrame = 0;
        sf::Clock clock;

        while (m_window->isOpen()) {
            sf::Event event;
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time = time / 800;
            while (m_window->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    m_window->close();
            }

            //////////////////// СТОЛКНОВЕНИЕ С ВРАГОМ ////////////////////
            if (clip1.getRect().intersects(susa.getRect()) || clip2.getRect().intersects(susa.getRect())) //если скрепка пересекается с игроком
            {
                susa.life = false; //персонаж умирает
            }

            ///////////////////
            //sf::Time dt = timer.restart();
            susa.update(time, &CurrentFrame , time, &view);
            clip1.update(time);
            clip2.update(time);

            m_window->clear();
            m_window->setView(view);

            //Рисуем карту
            for (int i = 0; i < map.GetHEIGHT(); i++)
                for (int j = 0; j < map.GetWIDTH(); j++)
                    m_window->draw( (*map.SetTexture(i,j)));//рисуем квадратики на экран

                     //m_window->draw(ball1);
            m_window->draw(*susa.GetSprite());
            m_window->draw(*clip1.GetSprite());
            m_window->draw(*clip2.GetSprite());
            m_window->display();
        }

    }
}
