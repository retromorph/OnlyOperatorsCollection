#include <SFML/Graphics.hpp>
#include <vector>

// dynamic
// dynamic[0]
// dynamic << awdawd
// dynamic >> 1
// dynamic >> awdawd
// dynamic <=> awdawd     == contains
// +dynamic     == getSize
// !dynamic      == clear
// ~dynamic      == getEnmerator
// (~dynamic)
// ~dynamic << x->{}
int main(){
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vector");
    sf::CircleShape shape;
    shape.setRadius(40.f);
    shape.setPosition(100.f, 100.f);
    shape.setFillColor(sf::Color::Cyan);

    while (window.isOpen())
    {
        sf::Event event{};

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}