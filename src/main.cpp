#include <iostream>
#include "SFML/Graphics.hpp"

void render(sf::RenderWindow& r);
bool eventHandle(sf::Event& e,sf::RenderWindow& r);
int main()
{
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode().getDesktopMode(),"Mandelbrot");
    sf::Event* event = new sf::Event();
    bool exit = false;

    while (!exit)
    {
       exit = eventHandle(*event,*window); 
       window->clear(sf::Color::White);

        render(*window);
        eventHandle(*event,*window);

        window->display();
    }
    
    delete window;
    delete event;
}

void render(sf::RenderWindow& r)
{
    sf::RectangleShape rect;
    rect.setPosition(100,100);
    rect.setSize(sf::Vector2f(100,100));
    rect.setFillColor(sf::Color::Black);
    r.draw(rect);

}

bool eventHandle(sf::Event& e,sf::RenderWindow& r)
{
    bool exit;
        while (r.pollEvent(e))
        {
            exit = (e.type == sf::Event::Closed);
            
        }
    return exit;
}